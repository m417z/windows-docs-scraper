typedef struct _DOT4_DC_CREATE_DATA {
  unsigned char bPsid;
  CHAR          pServiceName[MAX_SERVICE_LENGTH + 1];
  unsigned char bType;
  ULONG         ulBufferSize;
  USHORT        usMaxHtoPPacketSize;
  USHORT        usMaxPtoHPacketSize;
  unsigned char bHsid;
} DOT4_DC_CREATE_DATA, *PDOT4_DC_CREATE_DATA;