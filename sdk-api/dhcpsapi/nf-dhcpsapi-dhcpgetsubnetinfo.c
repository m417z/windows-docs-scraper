DWORD DHCP_API_FUNCTION DhcpGetSubnetInfo(
  [in]  DHCP_CONST WCHAR   *ServerIpAddress,
  [in]  DHCP_IP_ADDRESS    SubnetAddress,
  [out] LPDHCP_SUBNET_INFO *SubnetInfo
);