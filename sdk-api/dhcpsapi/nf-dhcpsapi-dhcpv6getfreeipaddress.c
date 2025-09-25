DWORD DHCP_API_FUNCTION DhcpV6GetFreeIPAddress(
  [in, optional] LPWSTR            ServerIpAddress,
  [in]           DHCP_IPV6_ADDRESS ScopeId,
  [in]           DHCP_IPV6_ADDRESS StartIP,
  [in]           DHCP_IPV6_ADDRESS EndIP,
  [in]           DWORD             NumFreeAddrReq,
  [out]          LPDHCPV6_IP_ARRAY *IPAddrList
);