PMDL MmAllocatePagesForMdlEx(
  [in] PHYSICAL_ADDRESS    LowAddress,
  [in] PHYSICAL_ADDRESS    HighAddress,
  [in] PHYSICAL_ADDRESS    SkipBytes,
  [in] SIZE_T              TotalBytes,
  [in] MEMORY_CACHING_TYPE CacheType,
  [in] ULONG               Flags
);