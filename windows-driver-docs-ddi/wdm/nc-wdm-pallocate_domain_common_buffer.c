PALLOCATE_DOMAIN_COMMON_BUFFER PallocateDomainCommonBuffer;

NTSTATUS PallocateDomainCommonBuffer(
  [in]           PDMA_ADAPTER DmaAdapter,
  [in]           HANDLE DomainHandle,
  [in, optional] PPHYSICAL_ADDRESS MaximumAddress,
  [in]           ULONG Length,
  [in]           ULONG Flags,
  [in, optional] MEMORY_CACHING_TYPE *CacheType,
  [in]           NODE_REQUIREMENT PreferredNode,
  [out]          PPHYSICAL_ADDRESS LogicalAddress,
  [out]          PVOID *VirtualAddress
)
{...}