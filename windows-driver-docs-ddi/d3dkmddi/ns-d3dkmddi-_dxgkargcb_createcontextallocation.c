typedef struct _DXGKARGCB_CREATECONTEXTALLOCATION {
  [in]  DXGK_CREATECONTEXTALLOCATIONFLAGS ContextAllocationFlags;
  [in]  HANDLE                            hAdapter;
  [in]  HANDLE                            hDevice;
  [in]  HANDLE                            hContext;
  [in]  HANDLE                            hDriverAllocation;
  [in]  SIZE_T                            Size;
  union {
    [in]  UINT Alignment;
    struct {
      UINT16 MinimumPageSize;
      UINT16 RecommendedPageSize;
    };
  };
  [in]  UINT                              SupportedSegmentSet;
  [in]  UINT                              EvictionSegmentSet;
  [in]  DXGK_SEGMENTPREFERENCE            PreferredSegment;
  union {
    [in]  DXGK_SEGMENTBANKPREFERENCE HintedBank;
          UINT                       MmuSet;
  };
  [in]  DXGK_ALLOCATIONINFOFLAGS          Flags;
  [out] HANDLE                            hAllocation;
  [in]  UINT                              PhysicalAdapterIndex;
} DXGKARGCB_CREATECONTEXTALLOCATION;