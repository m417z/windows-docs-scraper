typedef struct _NET_PACKET_CHECKSUM {
  UINT8 Layer2 : 2;
  UINT8 Layer3 : 2;
  UINT8 Layer4 : 2;
  UINT8 Reserved : 2;
} NET_PACKET_CHECKSUM;