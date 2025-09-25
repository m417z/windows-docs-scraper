typedef struct _NET_PACKET_GSO {
  union {
    struct {
      UINT32 Mss : 20;
      UINT32 Reserved0 : 12;
    } TCP;
    struct {
      UINT32 Mss : 20;
      UINT32 Reserved0 : 12;
    } UDP;
  } DUMMYUNIONNAME;
} NET_PACKET_GSO;