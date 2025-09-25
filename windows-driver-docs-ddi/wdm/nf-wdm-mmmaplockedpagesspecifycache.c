PVOID MmMapLockedPagesSpecifyCache(
  [in]           PMDL                                                                          MemoryDescriptorList,
  [in]           __drv_strictType(KPROCESSOR_MODE / enum _MODE,__drv_typeConst)KPROCESSOR_MODE AccessMode,
  [in]           __drv_strictTypeMatch(__drv_typeCond)MEMORY_CACHING_TYPE                      CacheType,
  [in, optional] PVOID                                                                         RequestedAddress,
  [in]           ULONG                                                                         BugCheckOnFailure,
  [in]           ULONG                                                                         Priority
);