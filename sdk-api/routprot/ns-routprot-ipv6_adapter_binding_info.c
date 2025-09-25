typedef struct IPV6_ADAPTER_BINDING_INFO {
  ULONG              AddressCount;
  IN6_ADDR           RemoteAddress;
  ULONG              Mtu;
  ULONGLONG          Speed;
  IPV6_LOCAL_BINDING Address[0];
} IPV6_ADAPTER_BINDING_INFO, *PIPV6_ADAPTER_BINDING_INFO;