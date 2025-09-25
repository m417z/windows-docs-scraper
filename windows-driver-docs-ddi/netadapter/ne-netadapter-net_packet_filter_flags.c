typedef enum _NET_PACKET_FILTER_FLAGS {
  NetPacketFilterFlagDirected = 0x00000001,
  NetPacketFilterFlagMulticast = 0x00000002,
  NetPacketFilterFlagAllMulticast = 0x00000004,
  NetPacketFilterFlagBroadcast = 0x00000008,
  NetPacketFilterFlagPromiscuous = 0x00000020
} NET_PACKET_FILTER_FLAGS;