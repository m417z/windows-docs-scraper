typedef struct _WNV_IP_ADDRESS {
  union {
    IN_ADDR  v4;
    IN6_ADDR v6;
    UCHAR    Addr[sizeof(IN6_ADDR)];
  } IP;
} WNV_IP_ADDRESS, *PWNV_IP_ADDRESS;