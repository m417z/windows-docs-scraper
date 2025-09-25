PVOID MmMapLockedPagesWithReservedMapping(
  [in] PVOID                                                    MappingAddress,
  [in] ULONG                                                    PoolTag,
  [in] PMDL                                                     MemoryDescriptorList,
  [in] __drv_strictTypeMatch(__drv_typeCond)MEMORY_CACHING_TYPE CacheType
);