typedef struct _AMCOPPStatusOutput {
  GUID  macKDI;
  DWORD cbSizeData;
  BYTE  COPPStatus[4076];
} AMCOPPStatusOutput, *LPAMCOPPStatusOutput;