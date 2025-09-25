typedef struct _NET_ADAPTER_RX_CAPABILITIES {
  ULONG                                  Size;
  NET_RX_FRAGMENT_BUFFER_ALLOCATION_MODE AllocationMode;
  NET_RX_FRAGMENT_BUFFER_ATTACHMENT_MODE AttachmentMode;
  UINT32                                 FragmentRingNumberOfElementsHint;
  SIZE_T                                 MaximumFrameSize;
  SIZE_T                                 MaximumNumberOfQueues;
  union {
    struct {
      PFN_NET_ADAPTER_RETURN_RX_BUFFER EvtAdapterReturnRxBuffer;
    } DUMMYSTRUCTNAME;
    struct {
      NET_MEMORY_MAPPING_REQUIREMENT MappingRequirement;
      SIZE_T                         FragmentBufferAlignment;
      NET_ADAPTER_DMA_CAPABILITIES   *DmaCapabilities;
    } DUMMYSTRUCTNAME2;
  } DUMMYUNIONNAME;
} NET_ADAPTER_RX_CAPABILITIES;