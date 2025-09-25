typedef struct _DXGKARGCB_CREATECONTEXTALLOCATION {
  [in]  DXGK_CREATECONTEXTALLOCATIONFLAGS ContextAllocationFlags;
  [in]  HANDLE                            hAdapter;
  [in]  HANDLE                            hDevice;
  [in]  HANDLE                            hContext;
  [in]  HANDLE                            hDriverAllocation;
  [in]  SIZE_T                            Size;
  [in]  UINT                              Alignment;
  [in]  UINT                              SupportedSegmentSet;
  [in]  UINT                              EvictionSegmentSet;
  [in]  DXGK_SEGMENTPREFERENCE            PreferredSegment;
  [in]  DXGK_SEGMENTBANKPREFERENCE        HintedBank;
  [in]  DXGK_ALLOCATIONINFOFLAGS          Flags;
  [out] HANDLE                            hAllocation;
  [in]  UINT                              PhysicalAdapterIndex;
} DXGKARGCB_CREATECONTEXTALLOCATION;