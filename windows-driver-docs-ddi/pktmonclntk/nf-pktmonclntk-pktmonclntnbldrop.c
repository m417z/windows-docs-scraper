VOID PktMonClntNblDrop(
  PKTMON_COMPONENT_CONTEXT         *CompContext,
  PNET_BUFFER_LIST                 NetBufferList,
  PKTMON_PACKET_TYPE               PacketType,
  PKTMON_PACKET_HEADER_INFORMATION *PacketHeaderInformation,
  BOOLEAN                          UseOnlyFirstNbl,
  PKTMON_DIRECTION                 Direction,
  INT                              DropReason,
  INT                              LocationCode
);