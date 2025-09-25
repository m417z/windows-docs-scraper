EVT_ACX_STREAM_ALLOCATE_RTPACKETS EvtAcxStreamAllocateRtpackets;

NTSTATUS EvtAcxStreamAllocateRtpackets(
  ACXSTREAM Stream,
  ULONG PacketCount,
  ULONG PacketSize,
  PACX_RTPACKET *Packets
)
{...}