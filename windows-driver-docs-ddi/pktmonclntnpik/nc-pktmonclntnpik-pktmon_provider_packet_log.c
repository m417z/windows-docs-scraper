PKTMON_PROVIDER_PACKET_LOG PktmonProviderPacketLog;

VOID PktmonProviderPacketLog(
  VOID *ProviderBindingContext,
  HANDLE EdgeHandle,
  const PKTMON_PACKET_LOG_IN *PacketLog,
  const PKTMON_PACKET_CONTEXT_IN *Context
)
{...}