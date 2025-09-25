DWORD DHCP_API_FUNCTION DhcpGetServerBindingInfo(
  [in]  DHCP_CONST WCHAR          *ServerIpAddress,
  [in]  ULONG                     Flags,
  [out] LPDHCP_BIND_ELEMENT_ARRAY *BindElementsInfo
);