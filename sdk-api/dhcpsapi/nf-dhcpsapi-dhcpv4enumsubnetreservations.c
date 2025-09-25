DWORD DHCP_API_FUNCTION DhcpV4EnumSubnetReservations(
  [in, optional] DHCP_CONST WCHAR              *ServerIpAddress,
  [in]           DHCP_IP_ADDRESS               SubnetAddress,
  [in, out]      DHCP_RESUME_HANDLE            *ResumeHandle,
  [in]           DWORD                         PreferredMaximum,
  [out]          LPDHCP_RESERVATION_INFO_ARRAY *EnumElementInfo,
  [out]          DWORD                         *ElementsRead,
  [out]          DWORD                         *ElementsTotal
);