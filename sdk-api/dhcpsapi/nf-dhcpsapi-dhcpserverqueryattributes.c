DWORD DhcpServerQueryAttributes(
  [in]  LPWSTR              ServerIpAddr,
  [in]  ULONG               dwReserved,
  [in]  ULONG               dwAttribCount,
  [in]  DHCP_ATTRIB_ID []   pDhcpAttribs,
  [out] LPDHCP_ATTRIB_ARRAY *pDhcpAttribArr
);