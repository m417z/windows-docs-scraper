PKTMON_PROVIDER_PACKET_DROP PktmonProviderPacketDrop;

VOID PktmonProviderPacketDrop(
  VOID *ProviderBindingContext,
  HANDLE CompHandle,
  const PKTMON_PACKET_LOG_IN *PacketLog,
  const PKTMON_DROP_REPORT_IN *DropReport,
  const PKTMON_PACKET_CONTEXT_IN *Context
)
{...}