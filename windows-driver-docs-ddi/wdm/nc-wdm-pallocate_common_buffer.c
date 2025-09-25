PALLOCATE_COMMON_BUFFER PallocateCommonBuffer;

PVOID PallocateCommonBuffer(
  [in]  PDMA_ADAPTER DmaAdapter,
  [in]  ULONG Length,
  [out] PPHYSICAL_ADDRESS LogicalAddress,
  [in]  BOOLEAN CacheEnabled
)
{...}