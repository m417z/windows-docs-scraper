typedef union _IN_ADDR_IPV4 {
  ULONG Addr;
  UCHAR AddrBytes[4];
} IN_ADDR_IPV4, *LPIN_ADDR_IPV4;