typedef struct _NET_ADAPTER_OFFLOAD_TX_CHECKSUM_CAPABILITIES {
  ULONG                                   Size;
  NET_ADAPTER_OFFLOAD_LAYER3_FLAGS        Layer3Flags;
  NET_ADAPTER_OFFLOAD_LAYER4_FLAGS        Layer4Flags;
  UINT16                                  Layer3HeaderOffsetLimit;
  UINT16                                  Layer4HeaderOffsetLimit;
  PFN_NET_ADAPTER_OFFLOAD_SET_TX_CHECKSUM EvtAdapterOffloadSetTxChecksum;
} NET_ADAPTER_OFFLOAD_TX_CHECKSUM_CAPABILITIES;