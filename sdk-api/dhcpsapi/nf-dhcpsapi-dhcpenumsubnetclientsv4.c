DWORD DHCP_API_FUNCTION DhcpEnumSubnetClientsV4(
  [in]      DHCP_CONST WCHAR            *ServerIpAddress,
  [in]      DHCP_IP_ADDRESS             SubnetAddress,
  [in, out] DHCP_RESUME_HANDLE          *ResumeHandle,
  [in]      DWORD                       PreferredMaximum,
  [out]     LPDHCP_CLIENT_INFO_ARRAY_V4 *ClientInfo,
  [out]     DWORD                       *ClientsRead,
  [out]     DWORD                       *ClientsTotal
);