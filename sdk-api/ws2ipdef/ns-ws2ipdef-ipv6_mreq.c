typedef struct ipv6_mreq {
  IN6_ADDR ipv6mr_multiaddr;
  ULONG    ipv6mr_interface;
} IPV6_MREQ, *PIPV6_MREQ;