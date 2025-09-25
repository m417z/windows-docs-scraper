DWORD DHCP_API_FUNCTION DhcpRemoveOptionValueV6(
  [in] LPWSTR                    ServerIpAddress,
  [in] DWORD                     Flags,
  [in] DHCP_OPTION_ID            OptionID,
  [in] LPWSTR                    ClassName,
  [in] LPWSTR                    VendorName,
  [in] LPDHCP_OPTION_SCOPE_INFO6 ScopeInfo
);