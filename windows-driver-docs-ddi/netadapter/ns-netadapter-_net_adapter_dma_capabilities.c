typedef struct _NET_ADAPTER_DMA_CAPABILITIES {
  ULONG            Size;
  WDFDMAENABLER    DmaEnabler;
  PHYSICAL_ADDRESS MaximumPhysicalAddress;
  WDF_TRI_STATE    CacheEnabled;
  NODE_REQUIREMENT PreferredNode;
} NET_ADAPTER_DMA_CAPABILITIES;