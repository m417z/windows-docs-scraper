DWORD DHCP_API_FUNCTION DhcpV4DeletePolicy(
  [in, optional] LPWSTR          ServerIpAddress,
  [in]           BOOL            fGlobalPolicy,
  [in]           DHCP_IP_ADDRESS SubnetAddress,
  [in]           LPWSTR          PolicyName
);