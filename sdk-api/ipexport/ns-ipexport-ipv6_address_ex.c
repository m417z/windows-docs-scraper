typedef struct _IPV6_ADDRESS_EX {
  USHORT sin6_port;
  ULONG  sin6_flowinfo;
  USHORT sin6_addr[8];
  ULONG  sin6_scope_id;
} IPV6_ADDRESS_EX, *PIPV6_ADDRESS_EX;