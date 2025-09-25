typedef struct _NET_ADAPTER_OFFLOAD_CHECKSUM_CAPABILITIES {
  ULONG                                Size;
  BOOLEAN                              IPv4;
  BOOLEAN                              Tcp;
  BOOLEAN                              Udp;
  PFN_NET_ADAPTER_OFFLOAD_SET_CHECKSUM EvtAdapterOffloadSetChecksum;
} NET_ADAPTER_OFFLOAD_CHECKSUM_CAPABILITIES;