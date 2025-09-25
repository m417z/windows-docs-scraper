typedef struct _BTH_SET_SERVICE {
  PULONG pSdpVersion;
  HANDLE *pRecordHandle;
  ULONG  fCodService;
  ULONG  Reserved[5];
  ULONG  ulRecordLength;
  UCHAR  pRecord[1];
} BTH_SET_SERVICE, *PBTH_SET_SERVICE, BTHNS_SETBLOB, *PBTHNS_SETBLOB;