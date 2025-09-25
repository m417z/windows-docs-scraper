DWORD DhcpGetOptionInfoV5(
  [in]  LPWSTR         ServerIpAddress,
  [in]  DWORD          Flags,
  [in]  DHCP_OPTION_ID OptionID,
  [in]  LPWSTR         ClassName,
  [in]  LPWSTR         VendorName,
  [out] LPDHCP_OPTION  *OptionInfo
);