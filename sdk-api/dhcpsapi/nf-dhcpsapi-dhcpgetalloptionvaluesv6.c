DWORD DHCP_API_FUNCTION DhcpGetAllOptionValuesV6(
  [in]  LPWSTR                    ServerIpAddress,
  [in]  DWORD                     Flags,
  [in]  LPDHCP_OPTION_SCOPE_INFO6 ScopeInfo,
  [out] LPDHCP_ALL_OPTION_VALUES  *Values
);