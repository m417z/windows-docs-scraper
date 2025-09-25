typedef struct in6_addr {
  union {
    UCHAR  Byte[16];
    USHORT Word[8];
  } u;
} IN6_ADDR, *PIN6_ADDR, *LPIN6_ADDR;