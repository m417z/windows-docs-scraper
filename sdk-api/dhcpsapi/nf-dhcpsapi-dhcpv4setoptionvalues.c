DWORD DHCP_API_FUNCTION DhcpV4SetOptionValues(
  [in, optional] LPWSTR                    ServerIpAddress,
  [in]           DWORD                     Flags,
  [in, optional] LPWSTR                    PolicyName,
  [in, optional] LPWSTR                    VendorName,
  [in]           LPDHCP_OPTION_SCOPE_INFO  ScopeInfo,
  [in]           LPDHCP_OPTION_VALUE_ARRAY OptionValues
);