      SUBROUTINE HOL2CHAR(IARR,IFC,ILC,CH)

      IMPLICIT NONE

      CHARACTER*(*) CH
      INTEGER*2 IARR(*)
! AEM 20041230 int*2->int
      integer IFC,ILC
C
C HOL2CHAR: move a Hollerith string into a character variable
C           blank filled to the right
C
C Input:
C       IARR: Hollerith string
C       IFC:  first character in IARR to move

C       ILC:  last character in IARR to move
C       CH:   destination character string
C
C Output:
C       CH: contains characters IFC...ILC from IARR
C           blank filled to the right if necessery
C
C  040506  ZMM  removed trailing RETURN
C               changed type from integer to integer*2

      integer ln,iend,i,IWORD,JCHAR
c     CHARACTER*1 CWORD(2)
c     EQUIVALENCE (CWORD(1),IWORD)
C
      LN=LEN(CH)
      IEND=MIN(LN,ILC-IFC+1)
C
      DO I=1,IEND
        IWORD=JCHAR(IARR,IFC+I-1)
	  CH(I:I)=char(iword)
      ENDDO
C
      IF(IEND.LT.LN) CH(IEND+1:)=' '
C
      END
