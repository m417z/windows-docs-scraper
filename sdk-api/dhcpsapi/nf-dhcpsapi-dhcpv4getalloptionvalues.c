DWORD DHCP_API_FUNCTION DhcpV4GetAllOptionValues(
  [in, optional] LPWSTR                      ServerIpAddress,
  [in]           DWORD                       Flags,
  [in]           LPDHCP_OPTION_SCOPE_INFO    ScopeInfo,
  [out]          LPDHCP_ALL_OPTION_VALUES_PB *Values
);