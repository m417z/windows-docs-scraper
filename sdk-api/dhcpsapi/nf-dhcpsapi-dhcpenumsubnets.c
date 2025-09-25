DWORD DHCP_API_FUNCTION DhcpEnumSubnets(
  [in]      DHCP_CONST WCHAR   *ServerIpAddress,
  [in, out] DHCP_RESUME_HANDLE *ResumeHandle,
  [in]      DWORD              PreferredMaximum,
  [out]     LPDHCP_IP_ARRAY    *EnumInfo,
  [out]     DWORD              *ElementsRead,
  [out]     DWORD              *ElementsTotal
);