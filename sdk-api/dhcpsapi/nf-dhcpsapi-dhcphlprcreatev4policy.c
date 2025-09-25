DWORD DHCP_API_FUNCTION DhcpHlprCreateV4Policy(
  [in]  LPWSTR              PolicyName,
  [in]  BOOL                fGlobalPolicy,
  [in]  DHCP_IP_ADDRESS     Subnet,
  [in]  DWORD               ProcessingOrder,
  [in]  DHCP_POL_LOGIC_OPER RootOperator,
  [in]  LPWSTR              Description,
  [in]  BOOL                Enabled,
  [out] LPDHCP_POLICY       *Policy
);