typedef struct {
  ULONGLONG UsnJournalID;
  USN       FirstUsn;
  USN       NextUsn;
  USN       LowestValidUsn;
  USN       MaxUsn;
  ULONGLONG MaximumSize;
  ULONGLONG AllocationDelta;
  USHORT    MinSupportedMajorVersion;
  USHORT    MaxSupportedMajorVersion;
} USN_JOURNAL_DATA_V1, *PUSN_JOURNAL_DATA_V1;