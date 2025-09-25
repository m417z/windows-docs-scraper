typedef struct _AMCOPPCommand {
  GUID  macKDI;
  GUID  guidCommandID;
  DWORD dwSequence;
  DWORD cbSizeData;
  BYTE  CommandData[4056];
} AMCOPPCommand, *LPAMCOPPCommand;