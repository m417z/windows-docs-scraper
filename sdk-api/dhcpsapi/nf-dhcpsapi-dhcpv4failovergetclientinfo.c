DWORD DHCP_API_FUNCTION DhcpV4FailoverGetClientInfo(
  [in, optional] LPWSTR                        ServerIpAddress,
  [in]           DHCP_CONST DHCP_SEARCH_INFO   *SearchInfo,
  [out]          LPDHCPV4_FAILOVER_CLIENT_INFO *ClientInfo
);