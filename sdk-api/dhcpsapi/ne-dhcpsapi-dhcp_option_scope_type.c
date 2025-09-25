typedef enum _DHCP_OPTION_SCOPE_TYPE {
  DhcpDefaultOptions,
  DhcpGlobalOptions,
  DhcpSubnetOptions,
  DhcpReservedOptions,
  DhcpMScopeOptions
} DHCP_OPTION_SCOPE_TYPE, *LPDHCP_OPTION_SCOPE_TYPE;