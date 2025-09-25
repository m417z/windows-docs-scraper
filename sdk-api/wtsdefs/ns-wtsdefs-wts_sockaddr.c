typedef struct _WTS_SOCKADDR {
#if ...
  USHORT sin_family;
#else
  USHORT sin_family;
#endif
  union {
    struct {
      USHORT sin_port;
      ULONG  in_addr;
      UCHAR  sin_zero[8];
    } ipv4;
    struct {
      USHORT sin6_port;
      ULONG  sin6_flowinfo;
      USHORT sin6_addr[8];
      ULONG  sin6_scope_id;
    } ipv6;
  } u;
} _WTS_SOCKADDR, WTS_SOCKADDR, *PWTS_SOCKADDR, _WRDS_SOCKADDR;