typedef struct _DXGK_QUERYSEGMENTMEMORYSTATE {
  WORD             DriverSegmentId;
  WORD             PhysicalAdapterIndex;
  union {
    UINT NumInvalidMemoryRanges;
    UINT NumUEFIFrameBufferRanges;
  };
  UINT             NumInvalidMemoryRanges;
  DXGK_MEMORYRANGE *pMemoryRanges;
} DXGK_QUERYSEGMENTMEMORYSTATE, DXGK_SEGMENTMEMORYSTATE;