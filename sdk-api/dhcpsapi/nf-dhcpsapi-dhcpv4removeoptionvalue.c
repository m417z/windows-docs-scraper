DWORD DHCP_API_FUNCTION DhcpV4RemoveOptionValue(
  [in, optional] LPWSTR                   ServerIpAddress,
  [in]           DWORD                    Flags,
  [in]           DHCP_OPTION_ID           OptionID,
  [in, optional] LPWSTR                   PolicyName,
  [in, optional] LPWSTR                   VendorName,
  [in]           LPDHCP_OPTION_SCOPE_INFO ScopeInfo
);