DWORD DHCP_API_FUNCTION DhcpV4EnumSubnetClients(
  [in, optional] DHCP_CONST WCHAR            *ServerIpAddress,
  [in]           DHCP_IP_ADDRESS             SubnetAddress,
  [in, out]      DHCP_RESUME_HANDLE          *ResumeHandle,
  [in]           DWORD                       PreferredMaximum,
  [out]          LPDHCP_CLIENT_INFO_PB_ARRAY *ClientInfo,
  [out]          DWORD                       *ClientsRead,
  [out]          DWORD                       *ClientsTotal
);