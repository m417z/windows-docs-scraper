typedef struct {
  DHCP_IPV6_ADDRESS SubnetAddress;
  ULONGLONG         NumStatelessClientsAdded;
  ULONGLONG         NumStatelessClientsRemoved;
} DHCPV6_STATELESS_SCOPE_STATS, *PDHCPV6_STATELESS_SCOPE_STATS, *LPDHCPV6_STATELESS_SCOPE_STATS;