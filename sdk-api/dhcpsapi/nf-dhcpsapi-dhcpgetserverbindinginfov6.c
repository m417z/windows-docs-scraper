DWORD DHCP_API_FUNCTION DhcpGetServerBindingInfoV6(
  [in]  DHCP_CONST WCHAR            *ServerIpAddress,
  [in]  ULONG                       Flags,
  [out] LPDHCPV6_BIND_ELEMENT_ARRAY *BindElementsInfo
);