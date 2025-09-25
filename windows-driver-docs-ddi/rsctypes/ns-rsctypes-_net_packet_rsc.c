typedef struct _NET_PACKET_RSC {
  union {
    struct {
      UINT16 CoalescedSegmentCount;
      UINT16 DuplicateAckCount;
    } TCP;
    struct {
      UINT16 CoalescedSegmentCount;
      UINT16 CoalescedSegmentSize;
    } UDP;
  } DUMMYUNIONNAME;
} NET_PACKET_RSC;