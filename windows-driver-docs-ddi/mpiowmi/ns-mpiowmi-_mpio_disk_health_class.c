typedef struct _MPIO_DISK_HEALTH_CLASS {
  WCHAR     Name[63 + 1];
  ULONGLONG NumberReads;
  ULONGLONG NumberWrites;
  ULONGLONG NumberBytesRead;
  ULONGLONG NumberBytesWritten;
  ULONGLONG NumberRetries;
  ULONGLONG NumberIoErrors;
  ULONGLONG CreateTime;
  ULONGLONG PathFailures;
  ULONGLONG FailTime;
  BOOLEAN   DeviceOffline;
  UCHAR     NumberReadsWrap;
  UCHAR     NumberWritesWrap;
  UCHAR     NumberBytesReadWrap;
  UCHAR     NumberBytesWrittenWrap;
  UCHAR     Pad[3];
} MPIO_DISK_HEALTH_CLASS, *PMPIO_DISK_HEALTH_CLASS;