typedef struct _ACX_RTPACKET {
  ULONG                 Size;
  WDF_MEMORY_DESCRIPTOR RtPacketBuffer;
  ULONG                 RtPacketOffset;
  ULONG                 RtPacketSize;
} ACX_RTPACKET, *PACX_RTPACKET;