PALLOCATE_COMMON_BUFFER_VECTOR PallocateCommonBufferVector;

NTSTATUS PallocateCommonBufferVector(
  PDMA_ADAPTER DmaAdapter,
  PHYSICAL_ADDRESS LowAddress,
  PHYSICAL_ADDRESS HighAddress,
  MEMORY_CACHING_TYPE CacheType,
  NODE_REQUIREMENT IdealNode,
  ULONG Flags,
  ULONG NumberOfElements,
  ULONGLONG SizeOfElements,
  PDMA_COMMON_BUFFER_VECTOR *VectorOut
)
{...}