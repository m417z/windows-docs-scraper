DWORD DHCP_API_FUNCTION DhcpServerGetConfigV6(
  [in]  DHCP_CONST WCHAR             *ServerIpAddress,
  [in]  LPDHCP_OPTION_SCOPE_INFO6    ScopeInfo,
  [out] LPDHCP_SERVER_CONFIG_INFO_V6 *ConfigInfo
);