typedef struct _DXGKARG_CREATEMEMORYBASIS {
  UINT             SegmentId;
  UINT64           RangeCount;
  DXGK_MEMORYRANGE Ranges[1];
} DXGKARG_CREATEMEMORYBASIS;