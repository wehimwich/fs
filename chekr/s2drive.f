      subroutine s2drive(lwho,ichecks)
C
      include '../include/fscom.i'
C 
C  INPUT: 
      integer*2 lwho
      integer ichecks(1)
C 
C 
C  SUBROUTINES CALLED:
C 
C
C  LOCAL VARIABLES: 
      integer icherr(17)
C
C
C  INITIALIZED:
      do j=1,17
        icherr(j)=0
      enddo
      call fs_get_ichs2(icheck(18))
      if(icheck(18).le.0.or.ichecks(18).ne.icheck(18)) return
      call s2recchk(icherr,lwho)

      call fs_get_ichs2(icheck(18))
      if(icheck(18).le.0.or.ichecks(18).ne.icheck(18)) return
      do j=1,17
        if (icherr(j).ne.0) then
          call logit7ic(0,0,0,0,-500-j,lwho,'rc')
        endif
      enddo
C
      return
      end