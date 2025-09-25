DWORD DHCP_API_FUNCTION DhcpEnumSubnetsV6(
  [in]      DHCP_CONST WCHAR   *ServerIpAddress,
  [in, out] DHCP_RESUME_HANDLE *ResumeHandle,
  [in]      DWORD              PreferredMaximum,
  [out]     LPDHCPV6_IP_ARRAY  *EnumInfo,
  [out]     DWORD              *ElementsRead,
  [out]     DWORD              *ElementsTotal
);