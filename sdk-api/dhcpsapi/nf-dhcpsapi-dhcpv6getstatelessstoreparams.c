DWORD DHCP_API_FUNCTION DhcpV6GetStatelessStoreParams(
  [in, optional] LPWSTR                    ServerIpAddress,
  [in]           BOOL                      fServerLevel,
  [in]           DHCP_IPV6_ADDRESS         SubnetAddress,
  [out]          LPDHCPV6_STATELESS_PARAMS *Params
);