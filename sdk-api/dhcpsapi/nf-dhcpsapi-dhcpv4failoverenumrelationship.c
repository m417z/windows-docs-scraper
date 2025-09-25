DWORD DHCP_API_FUNCTION DhcpV4FailoverEnumRelationship(
  [in, optional] LPWSTR                             ServerIpAddress,
  [in, out]      DHCP_RESUME_HANDLE                 *ResumeHandle,
  [in]           DWORD                              PreferredMaximum,
  [out]          LPDHCP_FAILOVER_RELATIONSHIP_ARRAY *pRelationship,
  [out]          LPDWORD                            RelationshipRead,
  [out]          LPDWORD                            RelationshipTotal
);