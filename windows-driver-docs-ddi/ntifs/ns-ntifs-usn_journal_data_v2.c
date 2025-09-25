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
  ULONG     Flags;
  ULONGLONG RangeTrackChunkSize;
  LONGLONG  RangeTrackFileSizeThreshold;
} USN_JOURNAL_DATA_V2, *PUSN_JOURNAL_DATA_V2;