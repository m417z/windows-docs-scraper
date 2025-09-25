DWORD DHCP_API_FUNCTION DhcpV6SetStatelessStoreParams(
  [in, optional] LPWSTR                    ServerIpAddress,
  [in]           BOOL                      fServerLevel,
  [in]           DHCP_IPV6_ADDRESS         SubnetAddress,
  [in]           DWORD                     FieldModified,
  [in]           LPDHCPV6_STATELESS_PARAMS Params
);