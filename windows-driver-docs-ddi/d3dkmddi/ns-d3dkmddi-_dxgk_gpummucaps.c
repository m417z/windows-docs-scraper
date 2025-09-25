typedef struct _DXGK_GPUMMUCAPS {
  union {
    struct {
      UINT ReadOnlyMemorySupported : 1;
      UINT NoExecuteMemorySupported : 1;
      UINT ZeroInPteSupported : 1;
      UINT ExplicitPageTableInvalidation : 1;
      UINT CacheCoherentMemorySupported : 1;
      UINT PageTableUpdateRequireAddressSpaceIdle : 1;
      UINT LargePageSupported : 1;
      UINT DualPteSupported : 1;
      UINT AllowNonAlignedLargePageAddress : 1;
      UINT SysMem64KBPageSupported : 1;
      UINT InvalidTlbEntriesNotCached : 1;
      UINT SysMemLargePageSupported : 1;
      UINT CachedPageTables : 1;
#if ...
      UINT Reserved : 19;
#elif
      UINT Reserved : 20;
#elif
      UINT Reserved : 21;
#elif
      UINT Reserved : 22;
#else
      UINT Reserved : 24;
#endif
    };
    UINT Value;
  };
  DXGK_PAGETABLEUPDATEMODE PageTableUpdateMode;
  UINT                     VirtualAddressBitCount;
  UINT                     LeafPageTableSizeFor64KPagesInBytes;
  UINT                     PageTableLevelCount;
  struct {
    UINT SourcePageTableVaInTransfer : 1;
    UINT Reserved : 31;
  } LegacyBehaviors;
} DXGK_GPUMMUCAPS;