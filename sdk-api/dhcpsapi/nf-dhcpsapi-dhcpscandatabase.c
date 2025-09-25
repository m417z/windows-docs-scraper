DWORD DHCP_API_FUNCTION DhcpScanDatabase(
  [in]  DHCP_CONST WCHAR *ServerIpAddress,
  [in]  DHCP_IP_ADDRESS  SubnetAddress,
  [in]  DWORD            FixFlag,
  [out] LPDHCP_SCAN_LIST *ScanList
);