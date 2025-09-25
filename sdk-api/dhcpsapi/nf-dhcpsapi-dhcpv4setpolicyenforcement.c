DWORD DHCP_API_FUNCTION DhcpV4SetPolicyEnforcement(
  [in, optional] LPWSTR          ServerIpAddress,
  [in]           BOOL            fGlobalPolicy,
  [in]           DHCP_IP_ADDRESS SubnetAddress,
  [in]           BOOL            Enable
);