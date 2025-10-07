NETIOAPI_API GetBestRoute2(
  _In_opt_       NET_LUID            *InterfaceLuid,
  _In_           NET_IFINDEX         InterfaceIndex,
  _In_opt_ const SOCKADDR_INET       *SourceAddress,
  _In_     const SOCKADDR_INET       *DestinationAddress,
  _In_           ULONG               AddressSortOptions,
  _Out_          PMIB_IPFORWARD_ROW2 BestRoute,
  _Out_          SOCKADDR_INET       *BestSourceAddress
);