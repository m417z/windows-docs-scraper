typedef struct _DXGK_CONTEXTINFO {
  UINT                  DmaBufferSize;
  UINT                  DmaBufferSegmentSet;
  UINT                  DmaBufferPrivateDataSize;
  UINT                  AllocationListSize;
  UINT                  PatchLocationListSize;
  UINT                  Reserved;
  DXGK_CONTEXTINFO_CAPS Caps;
  ULONG                 PagingCompanionNodeId;
} DXGK_CONTEXTINFO;