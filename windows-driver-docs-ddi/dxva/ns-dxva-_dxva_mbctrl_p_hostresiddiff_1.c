typedef struct _DXVA_MBctrl_P_HostResidDiff_1 {
  WORD         wMBaddress;
  WORD         wMBtype;
  DWORD        dwMB_SNL;
  WORD         wPatternCode;
  WORD         wPC_Overflow;
  DWORD        dwReservedBits2;
  DXVA_MVvalue MVector[DXVA_NumMV_OBMC_off_BinPBwith4MV_off];
} DXVA_MBctrl_P_HostResidDiff_1;