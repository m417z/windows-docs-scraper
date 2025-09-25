typedef struct _NET_ADAPTER_OFFLOAD_RSC_CAPABILITIES {
  ULONG                            Size;
  NET_ADAPTER_OFFLOAD_LAYER3_FLAGS Layer3Flags;
  NET_ADAPTER_OFFLOAD_LAYER4_FLAGS Layer4Flags;
  BOOLEAN                          TcpTimestampOption;
  PFN_NET_ADAPTER_OFFLOAD_SET_RSC  EvtAdapterOffloadSetRsc;
} NET_ADAPTER_OFFLOAD_RSC_CAPABILITIES;