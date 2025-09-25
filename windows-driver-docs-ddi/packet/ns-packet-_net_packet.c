typedef struct _NET_PACKET {
  UINT32            FragmentIndex;
  UINT16            FragmentCount;
  NET_PACKET_LAYOUT Layout;
  UINT8             Ignore : 1;
  UINT8             Scratch : 1;
  UINT8             Reserved1 : 6;
} NET_PACKET;