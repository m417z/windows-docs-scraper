typedef struct _NET_ADAPTER_RECEIVE_FILTER_CAPABILITIES {
  ULONG                              Size;
  NET_PACKET_FILTER_FLAGS            SupportedPacketFilters;
  SIZE_T                             MaximumMulticastAddresses;
  PFN_NET_ADAPTER_SET_RECEIVE_FILTER EvtSetReceiveFilter;
} NET_ADAPTER_RECEIVE_FILTER_CAPABILITIES;