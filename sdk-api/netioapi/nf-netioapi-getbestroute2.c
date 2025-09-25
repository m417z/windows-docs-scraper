IPHLPAPI_DLL_LINKAGE _NETIOAPI_SUCCESS_ NETIOAPI_API GetBestRoute2(
  [in, optional] NET_LUID            *InterfaceLuid,
  [in]           NET_IFINDEX         InterfaceIndex,
  [in]           const SOCKADDR_INET *SourceAddress,
  [in]           const SOCKADDR_INET *DestinationAddress,
  [in]           ULONG               AddressSortOptions,
  [out]          PMIB_IPFORWARD_ROW2 BestRoute,
  [out]          SOCKADDR_INET       *BestSourceAddress
);