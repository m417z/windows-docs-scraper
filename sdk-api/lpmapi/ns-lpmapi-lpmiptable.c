typedef struct lpmiptable {
  ULONG   ulIfIndex;
  ULONG   MediaType;
  IN_ADDR IfIpAddr;
  IN_ADDR IfNetMask;
} LPMIPTABLE;