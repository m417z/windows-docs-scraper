DWORD DhcpCreateOptionV5(
  [in]           LPWSTR         ServerIpAddress,
  [in]           DWORD          Flags,
  [in]           DHCP_OPTION_ID OptionId,
  [in, optional] LPWSTR         ClassName,
  [in, optional] LPWSTR         VendorName,
  [in]           LPDHCP_OPTION  OptionInfo
);