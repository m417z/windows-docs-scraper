DWORD DhcpGetAllOptionValues(
  [in]  LPWSTR                   ServerIpAddress,
  [in]  DWORD                    Flags,
  [in]  LPDHCP_OPTION_SCOPE_INFO ScopeInfo,
  [out] LPDHCP_ALL_OPTION_VALUES *Values
);