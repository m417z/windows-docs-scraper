DWORD DHCP_API_FUNCTION DhcpSetOptionValue(
  [in] DHCP_CONST WCHAR                  *ServerIpAddress,
  [in] DHCP_OPTION_ID                    OptionID,
  [in] DHCP_CONST DHCP_OPTION_SCOPE_INFO *ScopeInfo,
  [in] DHCP_CONST DHCP_OPTION_DATA       *OptionValue
);