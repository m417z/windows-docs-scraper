typedef enum _NDIS_PM_WOL_PACKET {
  NdisPMWoLPacketUnspecified,
  NdisPMWoLPacketBitmapPattern,
  NdisPMWoLPacketMagicPacket,
  NdisPMWoLPacketIPv4TcpSyn,
  NdisPMWoLPacketIPv6TcpSyn,
  NdisPMWoLPacketEapolRequestIdMessage,
  NdisPMWoLPacketMaximum
} NDIS_PM_WOL_PACKET, *PNDIS_PM_WOL_PACKET;