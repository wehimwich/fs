/*
 * Copyright (c) 2020 NVI, Inc.
 *
 * This file is part of VLBI Field System
 * (see http://github.com/nvi-inc/fs).
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
 */
/* mk5dbbcd.c make list of bbc detectors needed for DBBC_DDC rack */

#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <sys/types.h>
#include "../include/macro.h"

#include "../include/params.h"
#include "../include/fs_types.h"
#include "../include/fscom.h"         /* shared memory definition */
#include "../include/shm_addr.h"      /* shared memory pointer */

void mk5dbbcd(itpis)
int itpis[MAX_DBBC_BBC*2];
{
  int vc,i;

  if(shm_addr->mk5b_mode.mask.state.known == 0)
    return;

  if(shm_addr->dbbcform.mode==0) { /* astro */
    for (i=0;i<16;i++) {
      if(shm_addr->mk5b_mode.mask.mask & 1ull<<i ||
	 shm_addr->mk5b_mode.mask.mask & 1ull<<i+32){
	vc=i/2;
	if(-1 < vc && vc <8)
	  itpis[vc+MAX_DBBC_BBC]=1; /* usb */
      }
    }
    for (i=16;i<32;i++) {
      if(shm_addr->mk5b_mode.mask.mask & 1ull<<i ||
	 shm_addr->mk5b_mode.mask.mask & 1ull<<i+32){
	vc=(i-16)/2;
	if(-1 < vc && vc <8)
	  itpis[vc]=1;  /* lsb */
      }
    }
  } else if(shm_addr->dbbcform.mode==2 ) { /* wastro */
    for (i=0;i<16;i++) {
      if(shm_addr->mk5b_mode.mask.mask & 1ull<<i){
	vc=i/2;
	if(-1 < vc && vc <8)
	  itpis[vc+MAX_DBBC_BBC]=1; /* usb */
      }
    }
    for (i=16;i<32;i++) {
      if(shm_addr->mk5b_mode.mask.mask & 1ull<<i) {
	vc=(i-16)/2;
	if(-1 < vc && vc <8)
	  itpis[vc]=1;  /* lsb */
      }
    }
    for (i=32;i<48;i++) {
      if(shm_addr->mk5b_mode.mask.mask & 1ull<<i){
	vc=(i-16)/2;
	if(7 < vc && vc <16)
	  itpis[vc+MAX_DBBC_BBC]=1; /* usb */
      }
    }
    for (i=48;i<64;i++) {
      if(shm_addr->mk5b_mode.mask.mask & (1ull<<i)) {
	vc=(i-32)/2;
	if(7 < vc && vc <16)
	  itpis[vc]=1;  /* lsb */
      }
    }
  } else if(shm_addr->dbbcform.mode==5) { /*astro2 */
    for (i=0;i<8;i++) {
      if(shm_addr->mk5b_mode.mask.mask & 1ull<<i ||
	 shm_addr->mk5b_mode.mask.mask & 1ull<<i+32){
	vc=i/2;
	if(-1 < vc && vc <4)
	  itpis[vc+MAX_DBBC_BBC]=1; /* usb */
      }
    }
    for (i=8;i<16;i++) {
      if(shm_addr->mk5b_mode.mask.mask & 1ull<<i ||
	 shm_addr->mk5b_mode.mask.mask & 1ull<<i+32){
	vc=4+i/2;
	if(7 < vc && vc <12)
	  itpis[vc+MAX_DBBC_BBC]=1; /* usb */
      }
    }
    for (i=16;i<24;i++) {
      if(shm_addr->mk5b_mode.mask.mask & 1ull<<i ||
	 shm_addr->mk5b_mode.mask.mask & 1ull<<i+32){
	vc=(i-16)/2;
	if(-1 < vc && vc <4)
	  itpis[vc]=1;  /* lsb */
      }
    }
    for (i=24;i<32;i++) {
      if(shm_addr->mk5b_mode.mask.mask & 1ull<<i ||
	 shm_addr->mk5b_mode.mask.mask & 1ull<<i+32){
	vc=4+(i-16)/2;
	if(7 < vc && vc <12)
	  itpis[vc]=1;  /* lsb */
      }
    }
  } else if(shm_addr->dbbcform.mode==6) { /*astro3 */
    for (i=0;i<16;i++) {
      if(shm_addr->mk5b_mode.mask.mask & 1ull<<i){
	vc=i/2;
	vc=vc*2;
	if(-1 < vc && vc <16)
	  itpis[vc+MAX_DBBC_BBC]=1; /* usb */
      }
    }
    for (i=16;i<32;i++) {
      if(shm_addr->mk5b_mode.mask.mask & 1ull<<i) {
	vc=(i-16)/2;
	vc=vc*2;
	if(-1 < vc && vc <16)
	  itpis[vc]=1;  /* lsb */
      }
    }
  } else if(shm_addr->dbbcform.mode==4 ) { /* lba */
    for (i=0;i<4;i++) {
      if(shm_addr->mk5b_mode.mask.mask & 1ull<<i ||
	 shm_addr->mk5b_mode.mask.mask & 1ull<<i+32){
	vc=i/2;
	if(-1 < vc && vc <2)
	  itpis[vc+MAX_DBBC_BBC]=1; /* usb */
      }
    }
    for (i=4;i<8;i++) {
      if(shm_addr->mk5b_mode.mask.mask & 1ull<<i ||
	 shm_addr->mk5b_mode.mask.mask & 1ull<<i+32){
	vc=(i-4)/2+4;
	if(3 < vc && vc <6)
	  itpis[vc+MAX_DBBC_BBC]=1; /* usb */
      }
    }
    for (i=8;i<12;i++) {
      if(shm_addr->mk5b_mode.mask.mask & 1ull<<i ||
	 shm_addr->mk5b_mode.mask.mask & 1ull<<i+32){
	vc=(i-8)/2+2;
	if(1 < vc && vc <4)
	  itpis[vc+MAX_DBBC_BBC]=1; /* usb */
      }
    }
    for (i=12;i<16;i++) {
      if(shm_addr->mk5b_mode.mask.mask & 1ull<<i ||
	 shm_addr->mk5b_mode.mask.mask & 1ull<<i+32){
	vc=(i-12)/2+6;
	if(5 < vc && vc <8)
	  itpis[vc+MAX_DBBC_BBC]=1; /* usb */
      }
    }
    for (i=16;i<20;i++) {
      if(shm_addr->mk5b_mode.mask.mask & 1ull<<i ||
	 shm_addr->mk5b_mode.mask.mask & 1ull<<i+32){
	vc=(i-16)/2;
	if(-1 < vc && vc <2)
	  itpis[vc]=1;  /* lsb */
      }
    }
    for (i=20;i<24;i++) {
      if(shm_addr->mk5b_mode.mask.mask & 1ull<<i ||
	 shm_addr->mk5b_mode.mask.mask & 1ull<<i+32){
	vc=(i-20)/2+4;
	if(3 < vc && vc <6)
	  itpis[vc]=1;  /* lsb */
      }
    }
    for (i=24;i<28;i++) {
      if(shm_addr->mk5b_mode.mask.mask & 1ull<<i ||
	 shm_addr->mk5b_mode.mask.mask & 1ull<<i+32){
	vc=(i-24)/2+2;
	if(1 < vc && vc <4)
	  itpis[vc]=1;  /* lsb */
      }
    }
    for (i=28;i<32;i++) {
      if(shm_addr->mk5b_mode.mask.mask & 1ull<<i ||
	 shm_addr->mk5b_mode.mask.mask & 1ull<<i+32){
	vc=(i-28)/2+6;
	if(5 < vc && vc <8)
	  itpis[vc]=1;  /* lsb */
      }
    }
  } else if(shm_addr->dbbcform.mode == 1 ) { /*geo */
    for (i=0;i<16;i++) {
      if(shm_addr->mk5b_mode.mask.mask & 1ull<<i ||
	 shm_addr->mk5b_mode.mask.mask & 1ull<<i+32){
	vc=i/2;
	if(-1 < vc && vc <8)
	  itpis[vc+MAX_DBBC_BBC]=1;  /* usb */
      }
    }
    for (i=16;i<18;i++) {
      if(shm_addr->mk5b_mode.mask.mask & 1ull<<i ||
	 shm_addr->mk5b_mode.mask.mask & 1ull<<i+32){
	vc=0;
	if(-1 < vc && vc <1)
	  itpis[vc]=1; /*lsb*/
      }
    }
    for (i=18;i<20;i++) {
      if(shm_addr->mk5b_mode.mask.mask & 1ull<<i ||
	 shm_addr->mk5b_mode.mask.mask & 1ull<<i+32){
	vc=7;
	if(6 < vc && vc <8)
	  itpis[vc]=1; /*lsb*/
      }
    }
    for (i=20;i<32;i++) {
      if(shm_addr->mk5b_mode.mask.mask & 1ull<<i ||
	 shm_addr->mk5b_mode.mask.mask & 1ull<<i+32){
	vc=(i-20)/2+8;
	if(7 < vc && vc <14)
	  itpis[vc+MAX_DBBC_BBC]=1; /* usb */
      }
    }
  } else if(shm_addr->dbbcform.mode == 7 ) { /*geo2 */
    for (i=0;i<32;i++) {
      if(shm_addr->mk5b_mode.mask.mask & 1ull<<i) {
	vc=i/2;
	if(-1 < vc && vc <16)
	  itpis[vc+MAX_DBBC_BBC]=1;  /* usb */
      }
    }
    for (i=32;i<64;i++) {
      if(shm_addr->mk5b_mode.mask.mask & 1ull<<i) {
	vc=(i-32)/2;
	if(-1 < vc && vc <16)
	  itpis[vc]=1;  /* lsb */
      }
    }
  }
}

