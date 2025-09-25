DWORD DHCP_API_FUNCTION DhcpV4FailoverGetScopeRelationship(
  [in, optional] LPWSTR                       ServerIpAddress,
  [in]           DHCP_IP_ADDRESS              ScopeId,
  [out]          LPDHCP_FAILOVER_RELATIONSHIP *pRelationship
);