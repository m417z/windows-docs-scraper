typedef struct {
  DWORDLONG UsnJournalID;
  USN       FirstUsn;
  USN       NextUsn;
  USN       LowestValidUsn;
  USN       MaxUsn;
  DWORDLONG MaximumSize;
  DWORDLONG AllocationDelta;
} USN_JOURNAL_DATA_V0, *PUSN_JOURNAL_DATA_V0;