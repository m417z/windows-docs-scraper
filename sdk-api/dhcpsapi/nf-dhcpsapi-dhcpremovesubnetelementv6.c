DWORD DHCP_API_FUNCTION DhcpRemoveSubnetElementV6(
  [in] LPWSTR                        ServerIpAddress,
  [in] DHCP_IPV6_ADDRESS             SubnetAddress,
  [in] LPDHCP_SUBNET_ELEMENT_DATA_V6 RemoveElementInfo,
  [in] DHCP_FORCE_FLAG               ForceFlag
);