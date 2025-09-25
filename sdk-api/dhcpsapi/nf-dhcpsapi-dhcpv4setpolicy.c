DWORD DHCP_API_FUNCTION DhcpV4SetPolicy(
  [in, optional] LPWSTR          ServerIpAddress,
  [in]           DWORD           FieldsModified,
  [in]           BOOL            fGlobalPolicy,
  [in]           DHCP_IP_ADDRESS SubnetAddress,
  [in]           LPWSTR          PolicyName,
  [in]           LPDHCP_POLICY   Policy
);