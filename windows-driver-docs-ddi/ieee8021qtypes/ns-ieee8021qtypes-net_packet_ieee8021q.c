typedef struct _NET_PACKET_IEEE8021Q {
  UINT16 PriorityCodePoint : 3;
  UINT16 VlanIdentifier : 12;
  UINT8  TxTagging : 2;
} NET_PACKET_IEEE8021Q;