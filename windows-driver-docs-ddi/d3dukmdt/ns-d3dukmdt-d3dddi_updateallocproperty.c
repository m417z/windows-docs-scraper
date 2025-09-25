typedef struct D3DDDI_UPDATEALLOCPROPERTY {
  D3DKMT_HANDLE                    hPagingQueue;
  D3DKMT_HANDLE                    hAllocation;
  UINT                             SupportedSegmentSet;
  D3DDDI_SEGMENTPREFERENCE         PreferredSegment;
  D3DDDI_UPDATEALLOCPROPERTY_FLAGS Flags;
  D3DKMT_ALIGN64 UINT64            PagingFenceValue;
  union {
    struct {
      UINT SetAccessedPhysically : 1;
      UINT SetSupportedSegmentSet : 1;
      UINT SetPreferredSegment : 1;
      UINT SetUnmoveable : 1;
      UINT Reserved : 28;
    };
    UINT PropertyMaskValue;
  };
} D3DDDI_UPDATEALLOCPROPERTY;