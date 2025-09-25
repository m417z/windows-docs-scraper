DWORD DHCP_API_FUNCTION DhcpV4GetFreeIPAddress(
  [in, optional] LPWSTR          ServerIpAddress,
  [in]           DHCP_IP_ADDRESS ScopeId,
  [in]           DHCP_IP_ADDRESS StartIP,
  [in]           DHCP_IP_ADDRESS EndIP,
  [in]           DWORD           NumFreeAddrReq,
  [out]          LPDHCP_IP_ARRAY *IPAddrList
);