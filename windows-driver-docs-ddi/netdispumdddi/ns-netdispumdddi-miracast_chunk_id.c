typedef union {
  struct {
    UINT64 FrameNumber : 40;
    UINT64 PartNumber : 24;
  };
  UINT64 Value;
} MIRACAST_CHUNK_ID;