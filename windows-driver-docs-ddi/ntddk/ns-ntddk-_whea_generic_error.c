typedef struct _WHEA_GENERIC_ERROR {
  WHEA_GENERIC_ERROR_BLOCKSTATUS BlockStatus;
  ULONG                          RawDataOffset;
  ULONG                          RawDataLength;
  ULONG                          DataLength;
  WHEA_ERROR_SEVERITY            ErrorSeverity;
  UCHAR                          Data[1];
} WHEA_GENERIC_ERROR, *PWHEA_GENERIC_ERROR;