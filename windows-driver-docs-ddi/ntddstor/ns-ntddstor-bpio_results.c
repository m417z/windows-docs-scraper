typedef struct _BPIO_RESULTS {
  LONG   OpStatus;
  USHORT FailingDriverNameLen;
  WCHAR  FailingDriverName[32];
  USHORT FailureReasonLen;
  WCHAR  FailureReason[128];
} BPIO_RESULTS, *PBPIO_RESULTS;