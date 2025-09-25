DWORD DHCP_API_FUNCTION DhcpV4FailoverGetRelationship(
  [in, optional] LPWSTR                       ServerIpAddress,
  [in]           LPWSTR                       pRelationshipName,
  [out]          LPDHCP_FAILOVER_RELATIONSHIP *pRelationship
);