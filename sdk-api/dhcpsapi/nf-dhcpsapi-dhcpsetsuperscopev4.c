DWORD DhcpSetSuperScopeV4(
  [in]           DHCP_CONST WCHAR           *ServerIpAddress,
  [in]           DHCP_CONST DHCP_IP_ADDRESS SubnetAddress,
  [in, optional] DHCP_CONST LPWSTR          SuperScopeName,
  [in]           DHCP_CONST BOOL            ChangeExisting
);