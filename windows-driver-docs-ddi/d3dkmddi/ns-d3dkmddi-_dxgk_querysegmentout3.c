typedef struct _DXGK_QUERYSEGMENTOUT3 {
  [out] UINT                    NbSegment;
  [out] DXGK_SEGMENTDESCRIPTOR3 *pSegmentDescriptor;
  [out] UINT                    PagingBufferSegmentId;
  [out] UINT                    PagingBufferSize;
  [out] UINT                    PagingBufferPrivateDataSize;
} DXGK_QUERYSEGMENTOUT3;