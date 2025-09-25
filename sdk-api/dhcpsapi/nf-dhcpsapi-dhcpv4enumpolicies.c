DWORD DHCP_API_FUNCTION DhcpV4EnumPolicies(
  [in, optional] LPWSTR              ServerIpAddress,
  [in, out]      LPDWORD             ResumeHandle,
  [in]           DWORD               PreferredMaximum,
  [in]           BOOL                fGlobalPolicy,
  [in]           DHCP_IP_ADDRESS     SubnetAddress,
  [out]          LPDHCP_POLICY_ARRAY *EnumInfo,
  [out]          DWORD               *ElementsRead,
  [out]          DWORD               *ElementsTotal
);