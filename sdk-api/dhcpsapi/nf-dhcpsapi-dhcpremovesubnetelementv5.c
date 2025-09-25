DWORD DHCP_API_FUNCTION DhcpRemoveSubnetElementV5(
  [in, optional] DHCP_CONST WCHAR                       *ServerIpAddress,
  [in]           DHCP_IP_ADDRESS                        SubnetAddress,
  [in]           DHCP_CONST DHCP_SUBNET_ELEMENT_DATA_V5 *RemoveElementInfo,
  [in]           DHCP_FORCE_FLAG                        ForceFlag
);