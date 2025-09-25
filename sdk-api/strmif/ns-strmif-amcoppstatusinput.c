typedef struct _AMCOPPStatusInput {
  GUID  rApp;
  GUID  guidStatusRequestID;
  DWORD dwSequence;
  DWORD cbSizeData;
  BYTE  StatusData[4056];
} AMCOPPStatusInput, *LPAMCOPPStatusInput;