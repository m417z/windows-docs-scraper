DWORD DHCP_API_FUNCTION DhcpGetSubnetDelayOffer(
  [in]  LPWSTR          ServerIpAddress,
  [in]  DHCP_IP_ADDRESS SubnetAddress,
  [out] USHORT          *TimeDelayInMilliseconds
);