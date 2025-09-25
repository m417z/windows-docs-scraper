typedef union _IVRS_IVINFO {
  UINT32 AsUINT32;
  struct {
    UINT32 EFRSup : 1;
    UINT32 DmaGuardOptIn : 1;
    UINT32 ReservedZ0 : 3;
    UINT32 GVASize : 3;
    UINT32 PASize : 7;
    UINT32 VASize : 7;
    UINT32 HtAtsResv : 1;
    UINT32 ReservedZ1 : 9;
  } DUMMYSTRUCTNAME;
} IVRS_IVINFO, *PIVRS_IVINFO;