DWORD DHCP_API_FUNCTION DhcpEnumFilterV4(
  [in]      DHCP_CONST WCHAR        *ServerIpAddress,
  [in, out] LPDHCP_ADDR_PATTERN     ResumeHandle,
  [in]      DWORD                   PreferredMaximum,
  [in]      DHCP_FILTER_LIST_TYPE   ListType,
  [out]     LPDHCP_FILTER_ENUM_INFO *EnumFilterInfo,
  [out]     DWORD                   *ElementsRead,
  [out]     DWORD                   *ElementsTotal
);