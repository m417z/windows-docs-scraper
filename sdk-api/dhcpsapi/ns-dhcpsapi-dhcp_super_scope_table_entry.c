typedef struct _DHCP_SUPER_SCOPE_TABLE_ENTRY {
  DHCP_IP_ADDRESS SubnetAddress;
  DWORD           SuperScopeNumber;
  DWORD           NextInSuperScope;
  LPWSTR          SuperScopeName;
} DHCP_SUPER_SCOPE_TABLE_ENTRY, *LPDHCP_SUPER_SCOPE_TABLE_ENTRY;