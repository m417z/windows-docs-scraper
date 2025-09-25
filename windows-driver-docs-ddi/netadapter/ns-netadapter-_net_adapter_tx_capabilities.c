typedef struct _NET_ADAPTER_TX_CAPABILITIES {
  ULONG                          Size;
  NET_MEMORY_MAPPING_REQUIREMENT MappingRequirement;
  SIZE_T                         PayloadBackfill;
  SIZE_T                         MaximumNumberOfFragments;
  SIZE_T                         FragmentBufferAlignment;
  UINT32                         FragmentRingNumberOfElementsHint;
  SIZE_T                         MaximumNumberOfQueues;
  NET_ADAPTER_DMA_CAPABILITIES   *DmaCapabilities;
} NET_ADAPTER_TX_CAPABILITIES;