typedef struct __RAW_READ_INFO {
  LARGE_INTEGER   DiskOffset;
  ULONG           SectorCount;
  TRACK_MODE_TYPE TrackMode;
} RAW_READ_INFO, *PRAW_READ_INFO;