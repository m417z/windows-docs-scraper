ULONG StorPortFreeDmaMemory(
  [in]     PVOID               HwDeviceExtension,
  [in]     PVOID               BaseAddress,
  [in]     SIZE_T              NumberOfBytes,
  [in]     MEMORY_CACHING_TYPE CacheType,
  [in_opt] PHYSICAL_ADDRESS    PhysicalAddress
);