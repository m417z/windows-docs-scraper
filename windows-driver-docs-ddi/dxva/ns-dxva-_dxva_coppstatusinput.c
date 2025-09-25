typedef struct _DXVA_COPPStatusInput {
  GUID  rApp;
  GUID  guidStatusRequestID;
  ULONG dwSequence;
  ULONG cbSizeData;
  UCHAR StatusData[4056];
} DXVA_COPPStatusInput, *LPDXVA_COPPStatusInput;