typedef struct _DXGK_QUERYSEGMENTOUT {
  [out] UINT                   NbSegment;
  [out] DXGK_SEGMENTDESCRIPTOR *pSegmentDescriptor;
  [out] UINT                   PagingBufferSegmentId;
  [out] UINT                   PagingBufferSize;
  [out] UINT                   PagingBufferPrivateDataSize;
} DXGK_QUERYSEGMENTOUT;