IPHLPAPI_DLL_LINKAGE _NETIOAPI_SUCCESS_ NETIOAPI_API GetIpNetworkConnectionBandwidthEstimates(
  [in]  NET_IFINDEX                                    InterfaceIndex,
  [in]  ADDRESS_FAMILY                                 AddressFamily,
  [out] PMIB_IP_NETWORK_CONNECTION_BANDWIDTH_ESTIMATES BandwidthEstimates
);