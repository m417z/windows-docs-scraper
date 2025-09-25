DWORD DHCP_API_FUNCTION DhcpEnumSubnetClientsFilterStatusInfo(
  [in]      DHCP_CONST WCHAR                       *ServerIpAddress,
  [in]      DHCP_IP_ADDRESS                        SubnetAddress,
  [in, out] DHCP_RESUME_HANDLE                     *ResumeHandle,
  [in]      DWORD                                  PreferredMaximum,
  [out]     LPDHCP_CLIENT_FILTER_STATUS_INFO_ARRAY *ClientInfo,
  [out]     DWORD                                  *ClientsRead,
  [out]     DWORD                                  *ClientsTotal
);