#include <stdio.h>
#include <memory.h>
#include <stdio.h>
#include <fcntl.h>
#include <termio.h>
#include <linux/serial.h>
#include <sys/errno.h>
/*
#include "../include/fs_types.h"      * general header file for all fs data
                                      * structure definations *
#include "../include/params.h"        * general fs parameter header *
#include "../include/fscom.h"         * shared memory (fscom C data 
                                      * structure) layout *
#include "../include/shm_addr.h"      * declaration of pointer to fscom *
  */
#include "/usr2/fs/include/fs_types.h"  /* general header file for all fs data
					 * structure definations */
#include "/usr2/fs/include/params.h"        /* general fs parameter header */
#include "/usr2/fs/include/fscom.h"         /* shared memory (fscom C data 
                                       * structure) layout */
#include "/usr2/fs/include/shm_addr.h"      /* declaration of pointer to fscom */
/*  */

#define MAXLEN 4095
#define MAXBUF 80
int portopen_();
int portwrite_();
int portread_();
char *metcmd[14] = {"*0100Q3\r\n",   /* MET3 temperature measurement. */
		   "*0100P3\r\n",   /* MET3 pressure measurement. */
		   "*0100RH\r\n",   /* MET3 humidity measurement. */
		   "*0100UN\r\n",   /* MET3 pressure determination (doc's) */
		   "*9900VR\r\n",   /* MET3 stop any commands in progress,
				       reset. */
		   "*0100EW*0100UN=2\r\n",  /* MET3 change to mbar. */
		   "*0100AR\r\n",   /* MET3 resolution determination (doc's) */
		   "*0100EW*0100AR=0\r\n",  /* MET3 
					     * output resolution to 0.1*/
		   "*0100EW*0100AR=1\r\n",  /* MET3 
					     * output resolution to 0.01*/
		   "*0100EW*0100UN=3\r\n",  /* MET3 change to mbar. */
		   "*0100N1\r\n",  /* return int cnt for one analog chan.*/
		   "*0100Z1\r\n",  /* return 0 adj coef. for analog chans.*/
		   "*0100M1\r\n",  /* return span adj coef. for analog chans.*/
		   "*0100P9\r\n"};   /* MET3 temp, humi, press */
char *windcmd[6] = {"C0.0\r\n",     /* WindSensor coast. */
		    "D\r\n",        /* WindSensor Diagnostics. */
		    "H\r\n",        /* WinddSensor heater control 
				     * 0=off 1=on. */
		    "I\r\n",        /* WindSensor Identity. */
		    "W5\r\n",        /* WindSensor avrg., direction, speed. */
		    "U3\r\n"};      /* WindSensor units:0=miles,1=knots,
				     *  2=kilometers,3=meters per hour. */
/*
 * This will test the Field System ports.
 */
main(int argc, char *argv[])
{
  /* Passed arguments */
  int ttynum;         /* write to com port: 1-2 or Vikom: 16-23 */
  int ttynum2;        /* read from com port: 1-2 or Vikom: 16-23 */
  int met_baud_rate;  /* baudrate in Kbaud */
  int wind_baud_rate; /* baudrate in Kbaud */
  int parity;         /* parity bit */
  int bits;           /* bits */
  int stop;           /* stop bits */
  int buffsize;       /* read and write buffer size. */
  
  /* Local variables. */
  char terminal[40];    /* name of terminal device. */
  char terminal2[40];   /* name of terminal device. */
  int open_err;         /* terminal error on open.  */
  int open2_err;        /* terminal2 error on open. */
  char datetime[MAXLEN];
  char buff[MAXLEN];
  char buff2[MAXLEN];
  char buff3[4][MAXLEN];
  char temp_str[MAXLEN];
  char location_str[5][MAXLEN];
  int len, len2, cmdlen, wind_or_met=0; /* 0=wind, 1=met */
  int termch, err, nerr, count, to;
  int i, j, k, metcnt, cnt, loopcnt, windcnt;
  int status, error, which, used;
  float temp,pres,humi,wsp,wmax,wdir;
  char *sn, *longi, *lati, *elev;
  char *logfile;
  char wind_cmd_str[10],met_cmd_str[80];
  FILE *fp, *fp2;

  if(argc==1) {
    printf("metwind has parameters:\n");
    printf("For the MET Sensor(one parameter at a time):\n");
    printf("metwind temperature, pressure, humidity, or reset\n");
    printf("For the WIND Sensor:\n");
    printf("metwind wind\n");
    exit (0);
  } else {
    if(!strcmp(argv[1],"wind")) {
      if (argv[2]) {
	strcpy(wind_cmd_str,argv[2]);
      } else {
	strcpy(wind_cmd_str,"W5");
      }
      wind_or_met=0;
    } else {
      strcpy(met_cmd_str,argv[1]);
      cmdlen=strlen(met_cmd_str);
      strcpy(&met_cmd_str[cmdlen],"\r\n");
      if(strstr(met_cmd_str,"temp")) metcnt=0;
      else if(strstr(met_cmd_str,"pres")) metcnt=1;
      else if(strstr(met_cmd_str,"humi")) metcnt=2;
      else if(strstr(met_cmd_str,"borm")) metcnt=3;
      else if(strstr(met_cmd_str,"rese")) metcnt=4;
      else if(strstr(met_cmd_str,"chan")) metcnt=5;
      else if(strstr(met_cmd_str,"res0")) metcnt=6;
      else if(strstr(met_cmd_str,"res1")) metcnt=7;
      else if(strstr(met_cmd_str,"res2")) metcnt=8;
      else if(strstr(met_cmd_str,"bar")) metcnt=9;
      else if(strstr(met_cmd_str,"N1")) metcnt=10;
      else if(strstr(met_cmd_str,"Z1")) metcnt=11;
      else if(strstr(met_cmd_str,"M1")) metcnt=12;
      else if(strstr(met_cmd_str,"all")) metcnt=13;
      else metcnt=-1;
      /*else {printf("Try Again %0.4s\n",met_cmd_str); exit(0);}*/
	      wind_or_met=1;
    }
  }

  /* Opening met file. */
  if ((fp=fopen(FS_ROOT"/control/met.ctl","r")) == 0) {
    /* If the file does not exist complain only once. */
    if(!status)
      logit(NULL,-1,"ta");
    printf("write to file\n");
    exit(0);
  } else {
    /* Read the contents of the file then close  */
    k=0;
    cnt=0;
    while(fgets(buff,MAXBUF-1,fp) != NULL) {
      if(buff[0]!='*') {
	/* metport,windport,station code,windsample,logging,logfile */
	for(j=0; buff[j]!='\n'; j++) {
	  temp_str[j]=buff[j];
	  i++;
	  if(buff[0]=='\n') {
	    if(!status)
	      logit(NULL,-8,"ta");
	    printf("write to file\n");
	    exit(0);
	  }
	}
	err=sscanf(temp_str," %s ",&location_str[cnt]);
	if(k==7) break;
	cnt++;
      }
      k++;
    }
  }
  close(fp);

  sn=location_str[2];
  loopcnt=atoi(location_str[4]);
  logfile=location_str[5];
  
  /* ttynum = MET, ttynum2 = Wind Sensor */
  ttynum=atoi(&location_str[0][9]);
  ttynum2=atoi(&location_str[1][9]);
  met_baud_rate = 9600;
  wind_baud_rate = 2400;
  parity = 0;
  bits = 8;
  stop = 1;
  buffsize = 256;

  /* Create device name.
   * terminal = MET, terminal2 = Wind Sensor 
  sprintf (terminal, "/dev/ttyS%d", ttynum);
  sprintf (terminal2, "/dev/ttyS%d", ttynum2);*/
  strcpy(terminal,location_str[0]);
  strcpy(terminal2,location_str[1]);


  /* OPEN devices terminal and terminal2. */
  len = strlen(terminal);
  open_err = portopen_(&ttynum, terminal, &len,
		       &met_baud_rate, &parity, &bits, &stop);
  len = strlen(terminal2);
  open2_err = portopen_(&ttynum2, terminal2, &len,
			&wind_baud_rate, &parity, &bits, &stop);
  termch=0x0a; /* LF */
  to=500;      /* 500 centisecs. */


  buff2[0]='\0';
  /* printf("Port information from /usr2/control/met.ctl file\n");*/
  if(wind_or_met) {
    if(metcnt==-1) {
      len = strlen(met_cmd_str);
      err = portwrite_(&ttynum, met_cmd_str, &len);
    } else {
      len = strlen(metcmd[metcnt]);
      err = portwrite_(&ttynum, metcmd[metcnt], &len);
    }
    /* read from a port */
    if(err==-2) printf("write error\n");
    len2 = 80;
    err = portread_(&ttynum, buff2, &count, &len2, &termch, &to);
    if(err==-1) printf("wrong number of chars. read\n");
    if(err==-2) printf("timed out\n");
    if(err==-3) printf("read error\n");

    loopcnt=atoi(location_str[4]);
    logfile=location_str[5];
    len2 = strlen(buff2);
    buff2[len2]='\0';
    printf("cmd: %sresponse: %s\n", met_cmd_str,
	   &buff2[5]);
  } else {
    strcat(wind_cmd_str,"\r\n");
    printf("command: %s",wind_cmd_str);
    len = strlen(wind_cmd_str);
    err = portwrite_(&ttynum2, wind_cmd_str, &len);
    len = 80;
    err = portread_(&ttynum2, buff2, &count, &len, &termch, &to);
    len = strlen(buff2);
    buff2[len-5]='\0';
    if (!strstr(&wind_cmd_str[0],"W5")) {
      printf("Wind data: %s\n",&buff2[1]);
    } else {
      printf("Average: %.1s secs.\n", &buff2[2]);
      printf("Direction: %.3s degs.\n", &buff2[4]);
      printf("Speed: %.6s meters/sec.\n", &buff2[7]);
    }
  }
    
  portclose_(&ttynum);
  portclose_(&ttynum2);
  return 0;
}