typedef struct sockaddr_in6 {
  ADDRESS_FAMILY sin6_family;
  USHORT         sin6_port;
  ULONG          sin6_flowinfo;
  IN6_ADDR       sin6_addr;
  union {
    ULONG    sin6_scope_id;
    SCOPE_ID sin6_scope_struct;
  };
} SOCKADDR_IN6_LH, *PSOCKADDR_IN6_LH, *LPSOCKADDR_IN6_LH;