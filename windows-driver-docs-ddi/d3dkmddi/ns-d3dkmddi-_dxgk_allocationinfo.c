typedef struct _DXGK_ALLOCATIONINFO {
  VOID                       *pPrivateDriverData;
  UINT                       PrivateDriverDataSize;
  union {
    UINT Alignment;
    struct {
      UINT16 MinimumPageSize;
      UINT16 RecommendedPageSize;
    };
  };
  SIZE_T                     Size;
  SIZE_T                     PitchAlignedSize;
  DXGK_SEGMENTBANKPREFERENCE HintedBank;
  DXGK_SEGMENTPREFERENCE     PreferredSegment;
  union {
    UINT SupportedReadSegmentSet;
    UINT MmuSet;
  };
  UINT                       SupportedWriteSegmentSet;
  UINT                       EvictionSegmentSet;
  union {
    UINT MaximumRenamingListLength;
    UINT PhysicalAdapterIndex;
  };
  HANDLE                     hAllocation;
  union {
    DXGK_ALLOCATIONINFOFLAGS         Flags;
    DXGK_ALLOCATIONINFOFLAGS_WDDM2_0 FlagsWddm2;
  };
  DXGK_ALLOCATIONUSAGEHINT   *pAllocationUsageHint;
  UINT                       AllocationPriority;
  DXGK_ALLOCATIONINFOFLAGS2  Flags2;
} DXGK_ALLOCATIONINFO;