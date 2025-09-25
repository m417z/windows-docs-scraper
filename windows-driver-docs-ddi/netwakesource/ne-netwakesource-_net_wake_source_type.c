typedef enum _NET_WAKE_SOURCE_TYPE {
  NetWakeSourceTypeBitmapPattern = 1,
  NetWakeSourceTypeMagicPacket = 2,
  NetWakeSourceTypeMediaChange = 3,
  NetWakeSourceTypePacketFilterMatch = 4,
  NetWakeSourceTypeEapolPacket = 5
} NET_WAKE_SOURCE_TYPE;