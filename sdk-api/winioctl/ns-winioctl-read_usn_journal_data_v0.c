typedef struct {
  USN       StartUsn;
  DWORD     ReasonMask;
  DWORD     ReturnOnlyOnClose;
  DWORDLONG Timeout;
  DWORDLONG BytesToWaitFor;
  DWORDLONG UsnJournalID;
} READ_USN_JOURNAL_DATA_V0, *PREAD_USN_JOURNAL_DATA_V0;