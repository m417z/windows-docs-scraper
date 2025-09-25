DWORD DHCP_API_FUNCTION DhcpGetOptionInfo(
  [in]  DHCP_CONST WCHAR *ServerIpAddress,
  [in]  DHCP_OPTION_ID   OptionID,
  [out] LPDHCP_OPTION    *OptionInfo
);