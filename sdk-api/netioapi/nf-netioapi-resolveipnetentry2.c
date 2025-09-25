IPHLPAPI_DLL_LINKAGE _NETIOAPI_SUCCESS_ NETIOAPI_API ResolveIpNetEntry2(
  [in, out]      PMIB_IPNET_ROW2     Row,
  [in, optional] const SOCKADDR_INET *SourceAddress
);