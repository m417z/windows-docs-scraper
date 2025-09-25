typedef struct {
  USN       StartUsn;
  DWORD     ReasonMask;
  DWORD     ReturnOnlyOnClose;
  DWORDLONG Timeout;
  DWORDLONG BytesToWaitFor;
  DWORDLONG UsnJournalID;
  WORD      MinMajorVersion;
  WORD      MaxMajorVersion;
} READ_USN_JOURNAL_DATA_V1, *PREAD_USN_JOURNAL_DATA_V1;