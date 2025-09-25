typedef struct _DXVA_COPPStatusOutput {
  GUID  macKDI;
  ULONG cbSizeData;
  UCHAR COPPStatus[4076];
} DXVA_COPPStatusOutput, *LPDXVA_COPPStatusOutput;