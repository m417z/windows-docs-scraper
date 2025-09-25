typedef enum _NDIS_MAC_PACKET_TYPE {
  NdisMacPacketTypeUndefined,
  NdisMacPacketTypeUnicast,
  NdisMacPacketTypeMulticast,
  NdisMacPacketTypeBroadcast,
  NdisMacPacketTypeMaximum
} NDIS_MAC_PACKET_TYPE, *PNDIS_MAC_PACKET_TYPE;