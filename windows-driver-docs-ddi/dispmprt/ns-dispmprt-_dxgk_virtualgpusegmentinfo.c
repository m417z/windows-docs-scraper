typedef struct _DXGK_VIRTUALGPUSEGMENTINFO {
  ULONG  DriverSegmentId;
  UINT64 Size;
  UINT   Alignment;
  UINT64 MinSegmentOffset;
  UINT64 MaxSegmentOffset;
  UINT   PrivateDriverData;
} DXGK_VIRTUALGPUSEGMENTINFO, *PDXGK_VIRTUALGPUSEGMENTINFO;