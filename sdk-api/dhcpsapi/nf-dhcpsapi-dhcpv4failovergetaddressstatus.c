DWORD DHCP_API_FUNCTION DhcpV4FailoverGetAddressStatus(
  [in, optional] LPWSTR          ServerIpAddress,
  [in]           DHCP_IP_ADDRESS SubnetAddress,
  [in, out]      LPDWORD         pStatus
);