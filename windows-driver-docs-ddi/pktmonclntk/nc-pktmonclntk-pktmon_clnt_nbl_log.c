PKTMON_CLNT_NBL_LOG PktmonClntNblLog;

VOID PktmonClntNblLog(
  PKTMON_EDGE_CONTEXT *EdgeContext,
  PNET_BUFFER_LIST NetBufferList,
  PKTMON_PACKET_TYPE PacketType,
  PKTMON_PACKET_HEADER_INFORMATION *PacketHeaderInformation,
  BOOLEAN UseOnlyFirstNbl,
  PKTMON_DIRECTION Direction
)
{...}