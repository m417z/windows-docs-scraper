DWORD DHCP_API_FUNCTION DhcpEnumSubnetClientsV6(
  [in]      DHCP_CONST WCHAR            *ServerIpAddress,
  [in]      DHCP_IPV6_ADDRESS           SubnetAddress,
  [in, out] DHCP_RESUME_IPV6_HANDLE     *ResumeHandle,
  [in]      DWORD                       PreferredMaximum,
  [out]     LPDHCP_CLIENT_INFO_ARRAY_V6 *ClientInfo,
  [out]     DWORD                       *ClientsRead,
  [out]     DWORD                       *ClientsTotal
);