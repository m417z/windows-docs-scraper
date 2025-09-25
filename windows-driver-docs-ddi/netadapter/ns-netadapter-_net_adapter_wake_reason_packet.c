typedef struct _NET_ADAPTER_WAKE_REASON_PACKET {
  ULONG     Size;
  ULONG     PatternId;
  ULONG     OriginalPacketSize;
  WDFMEMORY WakePacket;
} NET_ADAPTER_WAKE_REASON_PACKET;