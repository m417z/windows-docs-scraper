typedef struct _NET_POWER_OFFLOAD_NS_PARAMETERS {
  ULONG                          Size;
  ULONG                          Id;
  NET_IPV6_ADDRESS               RemoteIPv6Address;
  NET_IPV6_ADDRESS               SolicitedNodeIPv6Address;
  NET_IPV6_ADDRESS               TargetIPv6Addresses[2];
  NET_ADAPTER_LINK_LAYER_ADDRESS LinkLayerAddress;
} NET_POWER_OFFLOAD_NS_PARAMETERS;