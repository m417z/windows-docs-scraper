DWORD DHCP_API_FUNCTION DhcpRemoveSubnetElementV4(
  [in] DHCP_CONST WCHAR                       *ServerIpAddress,
  [in] DHCP_IP_ADDRESS                        SubnetAddress,
  [in] DHCP_CONST DHCP_SUBNET_ELEMENT_DATA_V4 *RemoveElementInfo,
  [in] DHCP_FORCE_FLAG                        ForceFlag
);