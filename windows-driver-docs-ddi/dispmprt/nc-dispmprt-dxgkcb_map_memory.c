DXGKCB_MAP_MEMORY DxgkcbMapMemory;

NTSTATUS DxgkcbMapMemory(
  [in]  HANDLE DeviceHandle,
  [in]  PHYSICAL_ADDRESS TranslatedAddress,
  [in]  ULONG Length,
  [in]  BOOLEAN InIoSpace,
  [in]  BOOLEAN MapToUserMode,
  [in]  MEMORY_CACHING_TYPE CacheType,
  [out] PVOID *VirtualAddress
)
{...}