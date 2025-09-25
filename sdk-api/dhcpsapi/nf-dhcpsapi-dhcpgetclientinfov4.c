DWORD DHCP_API_FUNCTION DhcpGetClientInfoV4(
  [in]  DHCP_CONST WCHAR            *ServerIpAddress,
  [in]  DHCP_CONST DHCP_SEARCH_INFO *SearchInfo,
  [out] LPDHCP_CLIENT_INFO_V4       *ClientInfo
);