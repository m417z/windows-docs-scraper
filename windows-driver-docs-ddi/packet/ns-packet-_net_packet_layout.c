typedef struct _NET_PACKET_LAYOUT {
  UINT16 Layer2HeaderLength : 7;
  UINT16 Layer3HeaderLength : 9;
  UINT8  Layer4HeaderLength : 8;
  UINT8  Layer2Type : 4;
  UINT8  Layer3Type : 4;
  UINT8  Layer4Type : 4;
  UINT8  Reserved0 : 4;
} NET_PACKET_LAYOUT;