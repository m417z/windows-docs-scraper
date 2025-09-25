typedef struct {
  USN       StartUsn;
  ULONG     ReasonMask;
  ULONG     ReturnOnlyOnClose;
  ULONGLONG Timeout;
  ULONGLONG BytesToWaitFor;
  ULONGLONG UsnJournalID;
  USHORT    MinMajorVersion;
  USHORT    MaxMajorVersion;
} READ_USN_JOURNAL_DATA_V1, *PREAD_USN_JOURNAL_DATA_V1;