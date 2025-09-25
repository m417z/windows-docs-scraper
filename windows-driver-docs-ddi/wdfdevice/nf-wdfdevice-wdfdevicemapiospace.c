NTSTATUS WdfDeviceMapIoSpace(
  [in]  WDFDEVICE           Device,
  [in]  PHYSICAL_ADDRESS    PhysicalAddress,
  [in]  SIZE_T              NumberOfBytes,
  [in]  MEMORY_CACHING_TYPE CacheType,
  [out] PVOID               *PseudoBaseAddress
);