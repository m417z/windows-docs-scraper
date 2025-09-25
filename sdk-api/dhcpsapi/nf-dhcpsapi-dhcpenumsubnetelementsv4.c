DWORD DHCP_API_FUNCTION DhcpEnumSubnetElementsV4(
  [in]      DHCP_CONST WCHAR                    *ServerIpAddress,
  [in]      DHCP_IP_ADDRESS                     SubnetAddress,
  [in]      DHCP_SUBNET_ELEMENT_TYPE            EnumElementType,
  [in, out] DHCP_RESUME_HANDLE                  *ResumeHandle,
  [in]      DWORD                               PreferredMaximum,
  [out]     LPDHCP_SUBNET_ELEMENT_INFO_ARRAY_V4 *EnumElementInfo,
  [out]     DWORD                               *ElementsRead,
  [out]     DWORD                               *ElementsTotal
);