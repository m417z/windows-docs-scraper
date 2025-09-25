DWORD DHCP_API_FUNCTION DhcpV4QueryPolicyEnforcement(
  [in, optional] LPWSTR          ServerIpAddress,
  [in]           BOOL            fGlobalPolicy,
  [in]           DHCP_IP_ADDRESS SubnetAddress,
  [out]          BOOL            *Enabled
);