typedef struct {
  DWORD     Flags;
  DWORD     Unused;
  DWORDLONG ChunkSize;
  LONGLONG  FileSizeThreshold;
} USN_TRACK_MODIFIED_RANGES, *PUSN_TRACK_MODIFIED_RANGES;