typedef struct _WWAN_IP_ADDRESS_STATE {
  WWAN_IP_CONFIGURATION_FLAGS IPv4Flags;
  WWAN_IP_CONFIGURATION_FLAGS IPv6Flags;
  ULONG                       IPv4MTU;
  ULONG                       IPv6MTU;
  PWWAN_IPADDRESS_ENTRY       IpTable;
  ULONG                       IpCount;
  PWWAN_IPADDRESS_ENTRY       GatewayTable;
  ULONG                       GatewayCount;
  PWWAN_IPADDRESS_ENTRY       DnsTable;
  ULONG                       DnsCount;
} WWAN_IP_ADDRESS_STATE, *PWWAN_IP_ADDRESS_STATE;