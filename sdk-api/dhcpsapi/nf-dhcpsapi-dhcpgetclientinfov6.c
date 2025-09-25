DWORD DHCP_API_FUNCTION DhcpGetClientInfoV6(
  [in]  DHCP_CONST WCHAR               *ServerIpAddress,
  [in]  DHCP_CONST DHCP_SEARCH_INFO_V6 *SearchInfo,
  [out] LPDHCP_CLIENT_INFO_V6          *ClientInfo
);