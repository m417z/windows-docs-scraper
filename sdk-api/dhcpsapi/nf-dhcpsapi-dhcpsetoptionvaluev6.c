DWORD DHCP_API_FUNCTION DhcpSetOptionValueV6(
  [in] LPWSTR                    ServerIpAddress,
  [in] DWORD                     Flags,
  [in] DHCP_OPTION_ID            OptionId,
  [in] LPWSTR                    ClassName,
  [in] LPWSTR                    VendorName,
  [in] LPDHCP_OPTION_SCOPE_INFO6 ScopeInfo,
  [in] LPDHCP_OPTION_DATA        OptionValue
);