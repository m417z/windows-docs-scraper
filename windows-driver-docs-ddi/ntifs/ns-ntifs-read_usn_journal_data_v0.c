typedef struct {
  USN       StartUsn;
  ULONG     ReasonMask;
  ULONG     ReturnOnlyOnClose;
  ULONGLONG Timeout;
  ULONGLONG BytesToWaitFor;
  ULONGLONG UsnJournalID;
} READ_USN_JOURNAL_DATA_V0, *PREAD_USN_JOURNAL_DATA_V0;