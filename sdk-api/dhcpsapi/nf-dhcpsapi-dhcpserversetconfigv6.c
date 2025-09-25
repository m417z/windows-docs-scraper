DWORD DHCP_API_FUNCTION DhcpServerSetConfigV6(
  [in] DHCP_CONST WCHAR             *ServerIpAddress,
  [in] LPDHCP_OPTION_SCOPE_INFO6    ScopeInfo,
  [in] DWORD                        FieldsToSet,
  [in] LPDHCP_SERVER_CONFIG_INFO_V6 ConfigInfo
);