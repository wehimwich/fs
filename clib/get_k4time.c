/* get time setting information from k4con for k4 drive */

#include <memory.h>

#include "../include/params.h"
#include "../include/fs_types.h"
#include "../include/fscom.h"         /* shared memory definition */
#include "../include/shm_addr.h"

void get_k4time(centisec,fm_tim,ip)
long centisec[2];
int fm_tim[6];
long ip[5];                          /* ipc array */
{
  int year, ms, ilen, icount, ileap;
  char buf[30];

  ib_req11(ip,"d4",30,"TIM?");

  skd_run("ibcon",'w',ip);
  skd_par(ip);
  if(ip[2] <0) return;

  ilen=sizeof(buf);
  ib_res_ascii(buf,&ilen,ip);
  ib_res_time(centisec,ip);

  cls_clr(ip[0]);
  ip[0]=0;

  if(shm_addr->equip.drive_type == K41 )
     icount=sscanf(buf+4,"%2d%3d%2d%2d%2d.%3d",
   		&year,fm_tim+4,fm_tim+3,fm_tim+2,fm_tim+1,&ms);
  else
     icount=sscanf(buf+4,"%2d%3d%2d%2d%2d%3d",
   		&year,fm_tim+4,fm_tim+3,fm_tim+2,fm_tim+1,&ms);

  fm_tim[5]=100*((shm_addr->iyrctl_fs)/100)+year;
  if(ms >=995) {
    fm_tim[0]=0;
    if(++fm_tim[1]>59) {
      fm_tim[1]=0;
      if(++fm_tim[2]>59) {
	fm_tim[2]=0;
	if(++fm_tim[3]>23) {
	  fm_tim[3]=0;
	  fm_tim[4]++;
	  ileap=fm_tim[5]%4 == 0 && (fm_tim[5]%100 !=0 || fm_tim[5]%400 ==0);
	  if((ileap && fm_tim[4] >366)||
	     (!ileap && fm_tim[4] >365)) {
	    fm_tim[4]=1;
	    fm_tim[5]++;
	  }
	}
      }
    }
  } else
    fm_tim[0]=(ms+5)/10;

}