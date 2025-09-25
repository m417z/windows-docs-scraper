DWORD DHCP_API_FUNCTION DhcpV4SetOptionValue(
  [in, optional] LPWSTR                   ServerIpAddress,
  [in]           DWORD                    Flags,
  [in]           DHCP_OPTION_ID           OptionId,
  [in, optional] LPWSTR                   PolicyName,
  [in, optional] LPWSTR                   VendorName,
  [in]           LPDHCP_OPTION_SCOPE_INFO ScopeInfo,
  [in]           LPDHCP_OPTION_DATA       OptionValue
);