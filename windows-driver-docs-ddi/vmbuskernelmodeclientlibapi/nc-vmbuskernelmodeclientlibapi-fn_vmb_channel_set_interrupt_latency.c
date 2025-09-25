FN_VMB_CHANNEL_SET_INTERRUPT_LATENCY FnVmbChannelSetInterruptLatency;

NTSTATUS FnVmbChannelSetInterruptLatency(
  VMBCHANNEL Channel,
  UINT16 Latency,
  PUINT16 OriginalLatency
)
{...}