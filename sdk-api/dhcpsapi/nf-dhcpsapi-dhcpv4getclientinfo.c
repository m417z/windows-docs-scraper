DWORD DHCP_API_FUNCTION DhcpV4GetClientInfo(
  [in, optional] DHCP_CONST WCHAR            *ServerIpAddress,
  [in]           DHCP_CONST DHCP_SEARCH_INFO *SearchInfo,
  [out]          LPDHCP_CLIENT_INFO_PB       *ClientInfo
);