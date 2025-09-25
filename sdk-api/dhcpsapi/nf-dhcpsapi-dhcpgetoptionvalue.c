DWORD DHCP_API_FUNCTION DhcpGetOptionValue(
  [in]  DHCP_CONST WCHAR                  *ServerIpAddress,
  [in]  DHCP_OPTION_ID                    OptionID,
  [in]  DHCP_CONST DHCP_OPTION_SCOPE_INFO *ScopeInfo,
  [out] LPDHCP_OPTION_VALUE               *OptionValue
);