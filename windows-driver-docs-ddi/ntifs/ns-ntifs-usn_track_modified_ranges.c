typedef struct {
  ULONG     Flags;
  ULONG     Unused;
  ULONGLONG ChunkSize;
  LONGLONG  FileSizeThreshold;
} USN_TRACK_MODIFIED_RANGES, *PUSN_TRACK_MODIFIED_RANGES;