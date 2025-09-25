typedef struct _DXGK_ESCAPE_GPUMMUCAPS {
  BOOLEAN                      ReadOnlyMemorySupported;
  BOOLEAN                      NoExecuteMemorySupported;
  BOOLEAN                      ZeroInPteSupported;
  BOOLEAN                      CacheCoherentMemorySupported;
  BOOLEAN                      LargePageSupported;
  BOOLEAN                      DualPteSupported;
  BOOLEAN                      AllowNonAlignedLargePageAddress;
  BOOLEAN                      PageTable64KSupported : 1;
  BOOLEAN                      Reserved : 7;
  UINT                         VirtualAddressBitCount;
  UINT                         PageTableLevelCount;
  D3DKMT_PAGE_TABLE_LEVEL_DESC PageTableLevelDesk[DXGK_MAX_PAGE_TABLE_LEVEL_COUNT];
} DXGK_ESCAPE_GPUMMUCAPS;