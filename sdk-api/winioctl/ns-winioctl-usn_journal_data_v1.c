typedef struct {
  DWORDLONG UsnJournalID;
  USN       FirstUsn;
  USN       NextUsn;
  USN       LowestValidUsn;
  USN       MaxUsn;
  DWORDLONG MaximumSize;
  DWORDLONG AllocationDelta;
  WORD      MinSupportedMajorVersion;
  WORD      MaxSupportedMajorVersion;
} USN_JOURNAL_DATA_V1, *PUSN_JOURNAL_DATA_V1;