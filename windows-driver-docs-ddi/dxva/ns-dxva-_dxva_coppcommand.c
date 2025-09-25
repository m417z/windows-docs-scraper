typedef struct _DXVA_COPPCommand {
  GUID  macKDI;
  GUID  guidCommandID;
  ULONG dwSequence;
  ULONG cbSizeData;
  UCHAR CommandData[4056];
} DXVA_COPPCommand, *LPDXVA_COPPCommand;