/* mark IV formatter display */

#include <stdio.h>
#include <string.h>
#include <sys/types.h>

#include "../include/params.h"
#include "../include/fs_types.h"
#include "../include/fscom.h"
#include "../include/shm_addr.h"

#define MAX_OUT 256
#define MAX_BUF 256

void form4_dis(command,itask,ip)
struct cmd_ds *command;
int itask;
long ip[5];
{
      struct form4_cmd lclc;
      struct form4_mon lclm;
      int ind,kcom,i,j,ich, ierr, count, nrec, nchar, idum;
      long iclass;

      char output[MAX_OUT];
      char buff[MAX_BUF];

      ind=itask-1;

      kcom= command->argv[0] != NULL &&
            *command->argv[0] == '?' && command->argv[1] == NULL;

      if ((!kcom) && command->equal == '=') {
         logmatmsg(output,command,ip);
         return;
      } else if(kcom)
         memcpy(&lclc,&shm_addr->form4,sizeof(lclc));
      else {
	iclass=ip[0];
	nrec=ip[1];
	
	nchar=cls_rcv(iclass,buff,MAX_BUF,&idum,&idum,0,0);
	maSTAform4(&lclc,&lclm,buff);

	nchar=cls_rcv(iclass,buff,MAX_BUF,&idum,&idum,0,0);
	maSHOform4(&lclc,buff);

	nchar=cls_rcv(iclass,buff,MAX_BUF,&idum,&idum,0,0);
	maSHOform4(&lclc,buff);

	nchar=cls_rcv(iclass,buff,MAX_BUF,&idum,&idum,0,0);
	maSHOform4(&lclc,buff);

	nchar=cls_rcv(iclass,buff,MAX_BUF,&idum,&idum,0,0);
	maSHOform4(&lclc,buff);

	nchar=cls_rcv(iclass,buff,MAX_BUF,&idum,&idum,0,0);
	maSSTform4(&lclc,buff);

       cls_clr(iclass);
      }

   /* format output buffer */

      strcpy(output,command->name);
      strcat(output,"/");

      count=0;
      while( count>= 0) {
        if (count > 0) strcat(output,",");
        count++;
        form4_enc(output,&count,&lclc);
      }

      if(!kcom) {
        count=0;
        while( count>= 0) {
        if (count > 0) strcat(output,",");
          count++;
          form4_mon(output,&count,&lclm);
        }
      }
      if(strlen(output)>0) output[strlen(output)-1]='\0';

      for (i=0;i<5;i++) ip[i]=0;
      cls_snd(&ip[0],output,strlen(output),0,0);
      ip[1]=1;

      return;

error:
      ip[0]=0;
      ip[1]=0;
      ip[2]=ierr;
      memcpy(ip+3,"4f",2);
      return;
}