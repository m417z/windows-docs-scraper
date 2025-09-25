typedef struct _DXGK_QUERYSEGMENTOUT4 {
  UINT   NbSegment;
  BYTE   *pSegmentDescriptor;
  UINT   PagingBufferSegmentId;
  UINT   PagingBufferSize;
  UINT   PagingBufferPrivateDataSize;
  SIZE_T SegmentDescriptorStride;
} DXGK_QUERYSEGMENTOUT4;