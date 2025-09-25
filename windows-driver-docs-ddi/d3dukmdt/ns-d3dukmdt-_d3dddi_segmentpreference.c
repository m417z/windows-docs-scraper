typedef struct _D3DDDI_SEGMENTPREFERENCE {
  union {
    struct {
      UINT SegmentId0 : 5;
      UINT Direction0 : 1;
      UINT SegmentId1 : 5;
      UINT Direction1 : 1;
      UINT SegmentId2 : 5;
      UINT Direction2 : 1;
      UINT SegmentId3 : 5;
      UINT Direction3 : 1;
      UINT SegmentId4 : 5;
      UINT Direction4 : 1;
      UINT Reserved : 2;
    };
    UINT Value;
  };
} D3DDDI_SEGMENTPREFERENCE;