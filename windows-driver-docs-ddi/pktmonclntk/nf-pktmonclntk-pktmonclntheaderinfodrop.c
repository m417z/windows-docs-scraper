VOID PktMonClntHeaderInfoDrop(
  PKTMON_COMPONENT_CONTEXT         *CompContext,
  PKTMON_PACKET_TYPE               PacketType,
  PKTMON_PACKET_HEADER_INFORMATION *PacketHeaderInformation,
  PKTMON_DIRECTION                 Direction,
  INT                              DropReason,
  INT                              LocationCode,
  PKTMON_PACKET_CONTEXT_IN         *Context
);