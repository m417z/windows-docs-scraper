typedef struct _NET_ADAPTER_OFFLOAD_GSO_CAPABILITIES {
  ULONG                            Size;
  NET_ADAPTER_OFFLOAD_LAYER3_FLAGS Layer3Flags;
  NET_ADAPTER_OFFLOAD_LAYER4_FLAGS Layer4Flags;
  UINT16                           Layer4HeaderOffsetLimit;
  SIZE_T                           MaximumOffloadSize;
  SIZE_T                           MinimumSegmentCount;
  PFN_NET_ADAPTER_OFFLOAD_SET_GSO  EvtAdapterOffloadSetGso;
} NET_ADAPTER_OFFLOAD_GSO_CAPABILITIES;