DWORD DHCP_API_FUNCTION DhcpEnumSubnetElementsV6(
  [in]      LPWSTR                              ServerIpAddress,
  [in]      DHCP_IPV6_ADDRESS                   SubnetAddress,
  [in]      DHCP_SUBNET_ELEMENT_TYPE_V6         EnumElementType,
  [in, out] DHCP_RESUME_HANDLE                  *ResumeHandle,
  [in]      DWORD                               PreferredMaximum,
  [out]     LPDHCP_SUBNET_ELEMENT_INFO_ARRAY_V6 *EnumElementInfo,
  [out]     DWORD                               *ElementsRead,
  [out]     DWORD                               *ElementsTotal
);