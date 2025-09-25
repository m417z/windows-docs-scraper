typedef struct {
  ULONGLONG UsnJournalID;
  USN       FirstUsn;
  USN       NextUsn;
  USN       LowestValidUsn;
  USN       MaxUsn;
  ULONGLONG MaximumSize;
  ULONGLONG AllocationDelta;
} USN_JOURNAL_DATA_V0, *PUSN_JOURNAL_DATA_V0;