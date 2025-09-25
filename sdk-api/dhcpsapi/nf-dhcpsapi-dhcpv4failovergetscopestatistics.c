DWORD DHCP_API_FUNCTION DhcpV4FailoverGetScopeStatistics(
  [in, optional] LPWSTR                     ServerIpAddress,
  [in]           DHCP_IP_ADDRESS            ScopeId,
  [out]          LPDHCP_FAILOVER_STATISTICS *pStats
);