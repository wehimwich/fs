define  bbcagc        000000000000
bbc01=*,*,*,*,*,agc
bbc02=*,*,*,*,*,agc
bbc03=*,*,*,*,*,agc
bbc04=*,*,*,*,*,agc
bbc05=*,*,*,*,*,agc
bbc06=*,*,*,*,*,agc
bbc07=*,*,*,*,*,agc
bbc08=*,*,*,*,*,agc
bbc09=*,*,*,*,*,agc
bbc10=*,*,*,*,*,agc
bbc11=*,*,*,*,*,agc
bbc12=*,*,*,*,*,agc
bbc13=*,*,*,*,*,agc
bbc14=*,*,*,*,*,agc
enddef
define  bbcman        000000000000
bbc01=*,*,*,*,*,man
bbc02=*,*,*,*,*,man
bbc03=*,*,*,*,*,man
bbc04=*,*,*,*,*,man
bbc05=*,*,*,*,*,man
bbc06=*,*,*,*,*,man
bbc07=*,*,*,*,*,man
bbc08=*,*,*,*,*,man
bbc09=*,*,*,*,*,man
bbc10=*,*,*,*,*,man
bbc11=*,*,*,*,*,man
bbc12=*,*,*,*,*,man
bbc13=*,*,*,*,*,man
bbc14=*,*,*,*,*,man
enddef
define  bread        000000000000
bbc01
bbc02
bbc03
bbc04
bbc05
bbc06
bbc07
bbc08
bbc09
bbc10
bbc11
bbc12
bbc13
bbc14
enddef
define  bbcsx2        000000000000
bbc01=610.89,a,2.0,2.0
bbc02=620.89,a,2.0,2.0
bbc03=650.89,a,2.0,2.0
bbc04=710.89,a,2.0,2.0
bbc05=820.89,a,2.0,2.0
bbc06=900.89,a,2.0,2.0
bbc07=950.89,a,2.0,2.0
bbc08=970.89,a,2.0,2.0
bbc09=677.89,b,2.0,2.0
bbc10=682.89,b,2.0,2.0
bbc11=697.89,b,2.0,2.0
bbc12=727.89,b,2.0,2.0
bbc13=752.89,b,2.0,2.0
bbc14=762.89,b,2.0,2.0
enddef
define  bbcsx4        000000000000
bbc01=610.89,a,4.0,4.0
bbc02=620.89,a,4.0,4.0
bbc03=650.89,a,4.0,4.0
bbc04=710.89,a,4.0,4.0
bbc05=820.89,a,4.0,4.0
bbc06=900.89,a,4.0,4.0
bbc07=950.89,a,4.0,4.0
bbc08=970.89,a,4.0,4.0
bbc09=677.89,b,4.0,4.0
bbc10=682.89,b,4.0,4.0
bbc11=697.89,b,4.0,4.0
bbc12=727.89,b,4.0,4.0
bbc13=752.89,b,4.0,4.0
bbc14=762.89,b,4.0,4.0
enddef
define  bbcwb2        000000000000
bbc01=612.89,a,2.0,2.0
bbc02=652.89,a,2.0,2.0
bbc03=752.89,a,2.0,2.0
bbc04=912.89,a,2.0,2.0
bbc05=652.99,c,2.0,2.0
bbc06=772.99,c,2.0,2.0
bbc07=832.99,c,2.0,2.0
bbc08=852.99,c,2.0,2.0
bbc09=680.89,b,2.0,2.0
bbc10=690.89,b,2.0,2.0
bbc11=710.89,b,2.0,2.0
bbc12=765.89,b,2.0,2.0
bbc13=800.89,b,2.0,2.0
bbc14=805.89,b,2.0,2.0
enddef
define  bbcwb4        000000000000
bbc01=612.89,a,4.0,4.0
bbc02=652.89,a,4.0,4.0
bbc03=752.89,a,4.0,4.0
bbc04=912.89,a,4.0,4.0
bbc05=652.99,c,4.0,4.0
bbc06=772.99,c,4.0,4.0
bbc07=832.99,c,4.0,4.0
bbc08=852.99,c,4.0,4.0
bbc09=680.89,b,4.0,4.0
bbc10=690.89,b,4.0,4.0
bbc11=710.89,b,4.0,4.0
bbc12=765.89,b,4.0,4.0
bbc13=800.89,b,4.0,4.0
bbc14=805.89,b,4.0,4.0
enddef
define  caloff        000000000000
rx=*,*,*,*,*,*,off
enddef
define  calon        000000000000
rx=*,*,*,*,*,*,on
enddef
define  caltemps        000000000000
caltempa=20.8
caltempb=21.4
caltempc=20.8
enddef
define  check2a1        000000000000
check2c1
enddef
define  check2a2        000000000000
check2c2
enddef
define  check2c1        000000000000
check=*,-rc
enable=
parity=,,ab,off,g1,g3
fastr=14s
!+6s
!*
st=for,120,off
!+4s
repro=read,1,3
parity
repro=byp,1,3
!*+28.20s
et
!+3s
check=*,rc
enddef
define  check2c2        000000000000
check=*,-rc
enable=
parity=,,ab,off,g2,g4
fastf=14s
!+6s
!*
st=rev,120,off
!+4s
repro=read,2,4
parity
repro=byp,1,3
!*+28.20s
et
!+3s
check=*,rc
enddef
define  dat           00000000000x
bbc15=200
bbcsx2
bbc15=alarm
ifdsx
form=c,4
enddef
define  dqaeven        000000000000
dqa=1
repro=byp,2,4
dqa
repro=byp,6,8
dqa
repro=byp,10,12
dqa
repro=byp,14,16
dqa
repro=byp,18,20
dqa
repro=byp,22,24
dqa
repro=byp,26,28
enddef
define  dqaodd        000000000000
dqa=1
repro=byp,1,3
dqa
repro=byp,5,7
dqa
repro=byp,9,11
dqa
repro=byp,13,15
dqa
repro=byp,17,19
dqa
repro=byp,21,23
dqa
repro=byp,25,27
enddef
define  fastf        000000000000
ff
!+$
et
enddef
define  fastr        000000000000
rw
!+$
et
enddef
define  ifdsx        000000000000
ifdab=0,0,nor,nor
ifdcd=0,0,nor,nor
lo=8080.00,2020.00
upconv=479.9,479.9
enddef
define  ifdwb        000000000000
ifdab=0,0,nor,nor
ifdcd=0,0,nor,nor
lo=8080.00,2020.00,8080.0
upconv=479.9,479.9,0
enddef
define  initi        000000000000
"welcome to field system version 8.0 and the new pc field system
form=addr
sy=setcl
enddef
define  midob        000000000000
tpi=1u,2u,3u,4u,5u,6u,7u,8u,ifa,ifc
tpi=9u,10u,11u,12u,13u,14u,ifb
bbcagc
caltemps
tsys1=1u,2u,3u,4u,5u,6u,7u,8u,ifa,ifc
tsys2=9u,10u,11u,12u,13u,14u,ifb
onsource
wx
cable
ifdab
ifdcd
bbc06
bbc11
enddef
define  midtp        000000000000
bbcman
ifdab=max,max,*,*
ifdcd=max,max,*,*
!+2s
tpzero=1u,2u,3u,4u,5u,6u,7u,8u,ifa,ifc
tpzero=9u,10u,11u,12u,13u,14u,ifb
bbcagc
ifdab=0,0,*,*
ifdcd=0,0,*,*
rxmon
enddef
define  min15
rxall
wx
cable
sxcts
enddef
define  overnite
log=overnite
setup
check=*,-rc
min15@!,15m
rxmon@!+2m30s,5m
repro=byp,5,11
dqa=1
dqa@!,1m
enddef
define  postob
enddef
define  precond
schedule=prepass,#1
enddef
define  preob
onsource
bbcman
calon
!+2s
tpical=1u,2u,3u,4u,5u,6u,7u,8u,ifa,ifc
tpical=9u,10u,11u,12u,13u,14u,ifb
caloff
enddef
define  prepass
wakeup
xdisp=on
" mount the next tape without cleaning the tape drive.
" use the cont command when finished.
halt
xdisp=off
check=*,-rc
rec=load
!+10s
tape=low,reset
sff
!+5m27s
et
!+9s
wakeup
rec=release
xdisp=on
"drop vacuum loop, clean the tape drive thoroughly.
"re-thread the tape. type cont when finished.
halt
xdisp=off
rec=load
srw
!+5m28s
et
!+9s
enddef
define  ready
sxcts
rxmon
newtape
rec=load
!+10s
st=for,120,off
!+11s
et
!+3s
label
check=*,rc
enddef
define  rxall
rx=front,*,*,*,*,*,*
rx
rx=rear,*,*,*,*,*,*
rx
rx=lo,*,*,*,*,*,*
rx
rx=dcal,*,*,*,*,*,*
rx
rx=inlet,*,*,*,*,*,*
rx
rx=ret,*,*,*,*,*,*
rx
rx=sup,*,*,*,*,*,*
rx
rx=2.73v,*,*,*,*,*,*
rx
rx=sif,*,*,*,*,*,*
rx
rx=xif,*,*,*,*,*,*
rx
rx=kif,*,*,*,*,*,*
rx
rx=slo,*,*,*,*,*,*
rx
rx=xlo,*,*,*,*,*,*
rx
rx=klo,*,*,*,*,*,*
rx
rx=lo5mhz,*,*,*,*,*,*
rx
rx=28v,*,*,*,*,*,*
rx
rx=24v,*,*,*,*,*,*
rx
rx=20v,*,*,*,*,*,*
rx
rx=15v,*,*,*,*,*,*
rx
rx=5v,*,*,*,*,*,*
rx
rx=-15v,*,*,*,*,*,*
rx
rx=ground,*,*,*,*,*,*
rx
rx=pres,*,*,*,*,*,*
rx
rx=x1bias,*,*,*,*,*,*
rx
rx=x2bias,*,*,*,*,*,*
rx
rx=x3bias,*,*,*,*,*,*
rx
rx=s1bias,*,*,*,*,*,*
rx
rx=s2bias,*,*,*,*,*,*
rx
rx=s3bias,*,*,*,*,*,*
rx
rx=20k,*,*,*,*,*,*
rx
rx=70k,*,*,*,*,*,*
rx
enddef
define  rxmon
rxx=lo
rx
rxx=dcal
rx
rxx=lo5mhz
rx
rxx=pres
rx
rxx=20k
rx
rxx=70k
rx
enddef
define  rxx
rx=$,*,*,*,*,*,*
enddef
define  setup
dat
enable=
repro=byp,1,3
enddef
define  sfastf
sff
!+$
et
enddef
define  sfastr
srw
!+$
et
enddef
define  sx2a1
form=a,4.000
!*
tapeforma
pass=$
bbcsx2
ifdsx
enable=g1,g2,g3,g4
tape=low
repro=byp,5,17
!*+7s
enddef
define  sx2c1         00000000000
form=c,4.000
!*
tapeformc
pass=$
bbcsx2
ifdsx
enable=g1,g3
tape=low
repro=byp,5,17
!*+7s
enddef
define  sx2c2         00000000000x
form=c,4.000
!*
tapeformc
pass=$
bbcsx2
ifdsx
enable=g2,g4
tape=low
repro=byp,6,18
!*+7s
enddef
define  sx4a1
form=a,8.000
!*
tapeforma
pass=$
bbcsx4
ifdsx
enable=g1,g2,g3,g4
tape=low
repro=byp,5,17
!*+7s
enddef
define  sx4c1
form=c,8.000
!*
tapeformc
pass=$
bbcsx4
ifdsx
enable=g1,g3
tape=low
repro=byp,5,17
!*+7s
enddef
define  sx4c2
form=c,8.000
!*
tapeformc
pass=$
bbcsx4
ifdsx
enable=g2,g4
tape=low
repro=byp,6,18
!*+7s
enddef
define  sxcts
bbcman
tpi=1u,2u,3u,4u,5u,6u,7u,8u,ifa,ifc
tpi=9u,10u,11u,12u,13u,14u,ifb
ifdab=20,20,*,*
ifdcd=20,20,*,*
!+2s
tpzero=1u,2u,3u,4u,5u,6u,7u,8u,ifa,ifc
tpzero=9u,10u,11u,12u,13u,14u,ifb
ifdab=0,0,*,*
ifdcd=0,0,*,*
calon
!+2s
tpical=1u,2u,3u,4u,5u,6u,7u,8u,ifa,ifc
tpical=9u,10u,11u,12u,13u,14u,ifb
bbcagc
caloff
caltemps
tsys1=1u,2u,3u,4u,5u,6u,7u,8u,ifa,ifc
tsys2=9u,10u,11u,12u,13u,14u,ifb
enddef
define  tapeforma
tapeform=1,-350,2,  0,3,-295, 4, 55, 5, -240, 6,110
tapeform=7,-185,8,165,9,-130,10,220,11,  -75,12,275
enddef
define  tapeformc
tapeform=1,-330,2,-330,3,-275,4,-275,5,-220,6,-220
tapeform=7,-165,8,-165,9,-110,10,-110,11,-55,12,-55
tapeform=13,0,14,0,15,55,16,55,17,110,18,110
tapeform=19,165,20,165,21,220,22,220,23,275,24,275
enddef
define  ucall
uc=front,*,*,*,*,*,*
uc
uc=rear,*,*,*,*,*,*
uc
uc=lo,*,*,*,*,*,*
uc
uc=dcal,*,*,*,*,*,*
uc
uc=+12v,*,*,*,*,*,*
uc
uc=sense+,*,*,*,*,*,*
uc
uc=lolock,*,*,*,*,*,*
uc
uc=-2.73v,*,*,*,*,*,*
uc
uc=prisif,*,*,*,*,*,*
uc
uc=xif,*,*,*,*,*,*
uc
uc=secsif,*,*,*,*,*,*
uc
uc=prislo,*,*,*,*,*,*
uc
uc=xlo,*,*,*,*,*,*
uc
uc=secslo,*,*,*,*,*,*
uc
uc=lo5mhz,*,*,*,*,*,*
uc
uc=+15ps2,*,*,*,*,*,*
uc
uc=28v,*,*,*,*,*,*
uc
uc=-15ps1,*,*,*,*,*,*
uc
uc=20v,*,*,*,*,*,*
uc
uc=+15ps1,*,*,*,*,*,*
uc
uc=+5ps1,*,*,*,*,*,*
uc
uc=-15ps2,*,*,*,*,*,*
uc
uc=+5ps2,*,*,*,*,*,*
uc
uc=secs3b,*,*,*,*,*,*
uc
uc=x1bias,*,*,*,*,*,*
uc
uc=x2bias,*,*,*,*,*,*
uc
uc=x3bias,*,*,*,*,*,*
uc
uc=pris1b,*,*,*,*,*,*
uc
uc=pris2b,*,*,*,*,*,*
uc
uc=pris3b,*,*,*,*,*,*
uc
uc=secs1b,*,*,*,*,*,*
uc
uc=secs2b,*,*,*,*,*,*
uc
enddef
define  ucmon
ucx=front
uc
ucx=rear
uc
ucx=lo
uc
ucx=dcal
uc
ucx=lo5mhz
uc
ucx=sense+
uc
enddef
define  ucx
uc=$,*,*,*,*,*,*
enddef
define  unlod
enable=,
check=*,-rc
tape=off
rec=unload
xdisp=on
"**dismount this tape now**"
wakeup
xdisp=off
enddef
define  wb2c1
form=c,4.000
!*
tapeformc
pass=$
bbcwb2
ifdwb
enable=g1,g3
tape=low
repro=byp,5,17
!*+7s
enddef
define  wb2c2
form=c,4.000
!*
tapeformc
pass=$
bbcwb2
ifdwb
enable=g2,g4
tape=low
repro=byp,6,18
!*+7s
enddef
define  wb4c1
form=c,8.000
!*
tapeformc
pass=$
bbcwb4
ifdwb
enable=g1,g3
tape=low
repro=byp,5,17
!*+7s
enddef
define  wb4c2
form=c,8.000
!*
tapeformc
pass=$
bbcwb4
ifdwb
enable=g2,g4
tape=low
repro=byp,6,18
!*+7s
enddef
define  vlbainit      00000000000 
bbc01=addr
bbc02=addr
bbc03=addr
bbc04=addr
bbc05=addr
bbc06=addr
bbc07=addr
bbc08=addr
bbc09=addr
bbc10=addr
bbc11=addr
bbc12=addr
bbc13=addr
bbc14=addr
form=addr
rec=addr
ifdab=addr
ifdcd=addr
enddef
