typedef union {
  ULONG  Value;
  struct {
    ULONG AddressAvailable : 1;
    ULONG GatewayAvailable : 1;
    ULONG DnsServerAvailable : 1;
    ULONG MTUAvailable : 1;
  };
} WWAN_IP_CONFIGURATION_FLAGS;