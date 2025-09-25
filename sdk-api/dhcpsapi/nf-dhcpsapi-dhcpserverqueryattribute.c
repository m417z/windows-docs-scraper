DWORD DhcpServerQueryAttribute(
  [in]  LPWSTR         ServerIpAddr,
  [in]  ULONG          dwReserved,
  [in]  DHCP_ATTRIB_ID DhcpAttribId,
  [out] LPDHCP_ATTRIB  *pDhcpAttrib
);