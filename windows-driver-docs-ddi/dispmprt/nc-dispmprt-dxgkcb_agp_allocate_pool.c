DXGKCB_AGP_ALLOCATE_POOL DxgkcbAgpAllocatePool;

NTSTATUS DxgkcbAgpAllocatePool(
  [in]  IN HANDLE Context,
  [in]  IN ULONG AllocationSize,
  [in]  IN MEMORY_CACHING_TYPE CacheType,
  [out] OUT PPHYSICAL_ADDRESS PhysicalAddress,
  [out] OUT PVOID *VirtualAddress
)
{...}