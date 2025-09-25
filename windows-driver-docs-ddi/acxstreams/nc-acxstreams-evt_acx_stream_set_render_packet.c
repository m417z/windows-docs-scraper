EVT_ACX_STREAM_SET_RENDER_PACKET EvtAcxStreamSetRenderPacket;

NTSTATUS EvtAcxStreamSetRenderPacket(
  ACXSTREAM Stream,
  ULONG Packet,
  ULONG Flags,
  ULONG EosPacketLength
)
{...}