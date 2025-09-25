DWORD DHCP_API_FUNCTION DhcpGetClientOptions(
  [in]  DHCP_CONST WCHAR   *ServerIpAddress,
  [in]  DHCP_IP_ADDRESS    ClientIpAddress,
  [in]  DHCP_IP_MASK       ClientSubnetMask,
  [out] LPDHCP_OPTION_LIST *ClientOptions
);