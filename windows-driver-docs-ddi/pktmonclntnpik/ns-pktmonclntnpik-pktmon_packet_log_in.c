typedef struct _PKTMON_PACKET_LOG_IN {
  PKTMON_HEADER             Header;
  VOID                      *Buffer;
  PKTMON_BUFFER_TYPE        BufferType;
  PKTMON_PACKET_TYPE        PacketType;
  PKTMON_DIRECTION          Direction;
  UINT32                    Flags;
  PKTMON_PACKET_HEADER_INFO *PacketHeaderInfo;
} PKTMON_PACKET_LOG_IN;