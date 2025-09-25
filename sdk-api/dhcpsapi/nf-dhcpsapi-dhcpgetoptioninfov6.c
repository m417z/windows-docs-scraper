DWORD DHCP_API_FUNCTION DhcpGetOptionInfoV6(
  [in]  LPWSTR         ServerIpAddress,
  [in]  DWORD          Flags,
  [in]  DHCP_OPTION_ID OptionID,
  [in]  LPWSTR         ClassName,
  [in]  LPWSTR         VendorName,
  [out] LPDHCP_OPTION  *OptionInfo
);