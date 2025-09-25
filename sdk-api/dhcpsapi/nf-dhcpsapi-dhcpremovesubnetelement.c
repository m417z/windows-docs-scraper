DWORD DHCP_API_FUNCTION DhcpRemoveSubnetElement(
  [in] DHCP_CONST WCHAR                    *ServerIpAddress,
  [in] DHCP_IP_ADDRESS                     SubnetAddress,
  [in] DHCP_CONST DHCP_SUBNET_ELEMENT_DATA *RemoveElementInfo,
  [in] DHCP_FORCE_FLAG                     ForceFlag
);