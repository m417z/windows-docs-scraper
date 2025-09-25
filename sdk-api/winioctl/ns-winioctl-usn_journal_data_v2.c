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
  DWORD     Flags;
  DWORDLONG RangeTrackChunkSize;
  LONGLONG  RangeTrackFileSizeThreshold;
} USN_JOURNAL_DATA_V2, *PUSN_JOURNAL_DATA_V2;