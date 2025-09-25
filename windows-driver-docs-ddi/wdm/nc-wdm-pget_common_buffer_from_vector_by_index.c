PGET_COMMON_BUFFER_FROM_VECTOR_BY_INDEX PgetCommonBufferFromVectorByIndex;

VOID PgetCommonBufferFromVectorByIndex(
  PDMA_ADAPTER DmaAdapter,
  PDMA_COMMON_BUFFER_VECTOR Vector,
  ULONG Index,
  PVOID *VirtualAddressOut,
  PPHYSICAL_ADDRESS LogicalAddressOut
)
{...}