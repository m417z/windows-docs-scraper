typedef struct _DATA_HEADER {
  DWORD dwSignature;
  WORD  wSize;
  WORD  wDataID;
  DWORD dwDataSize;
  DWORD dwReserved;
} DATA_HEADER, *PDATA_HEADER;