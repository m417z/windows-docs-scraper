typedef struct _FS_BPIO_RESULTS {
  NTSTATUS OpStatus;
  USHORT   FailingDriverNameLen;
  WCHAR    FailingDriverName[32];
  USHORT   FailureReasonLen;
  WCHAR    FailureReason[128];
} FS_BPIO_RESULTS, *PFS_BPIO_RESULTS;