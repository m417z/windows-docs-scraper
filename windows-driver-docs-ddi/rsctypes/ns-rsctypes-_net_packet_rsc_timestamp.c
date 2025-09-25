typedef struct _NET_PACKET_RSC_TIMESTAMP {
  union {
    struct {
      UINT32 RscTcpTimestampDelta;
    } TCP;
  } DUMMYUNIONNAME;
} NET_PACKET_RSC_TIMESTAMP;