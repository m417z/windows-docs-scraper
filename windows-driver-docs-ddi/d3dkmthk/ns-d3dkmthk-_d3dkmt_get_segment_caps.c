typedef struct _D3DKMT_GET_SEGMENT_CAPS {
  UINT                PhysicalAdapterIndex;
  UINT                NumSegments;
  D3DKMT_SEGMENT_CAPS SegmentCaps[D3DKMT_MAX_SEGMENT_COUNT];
} D3DKMT_GET_SEGMENT_CAPS;