typedef struct _NET_POWER_OFFLOAD_ARP_PARAMETERS {
  ULONG                          Size;
  ULONG                          Id;
  NET_IPV4_ADDRESS               RemoteIPv4Address;
  NET_IPV4_ADDRESS               HostIPv4Address;
  NET_ADAPTER_LINK_LAYER_ADDRESS LinkLayerAddress;
} NET_POWER_OFFLOAD_ARP_PARAMETERS;