PFREE_COMMON_BUFFER PfreeCommonBuffer;

VOID PfreeCommonBuffer(
  [in] PDMA_ADAPTER DmaAdapter,
  [in] ULONG Length,
  [in] PHYSICAL_ADDRESS LogicalAddress,
  [in] PVOID VirtualAddress,
  [in] BOOLEAN CacheEnabled
)
{...}