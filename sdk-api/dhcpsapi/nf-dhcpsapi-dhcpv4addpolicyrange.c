DWORD DHCP_API_FUNCTION DhcpV4AddPolicyRange(
  [in, optional] LPWSTR          ServerIpAddress,
  [in]           DHCP_IP_ADDRESS SubnetAddress,
  [in]           LPWSTR          PolicyName,
  [in]           LPDHCP_IP_RANGE Range
);