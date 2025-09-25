EVT_ACX_STREAM_GET_HW_LATENCY EvtAcxStreamGetHwLatency;

NTSTATUS EvtAcxStreamGetHwLatency(
  ACXSTREAM Stream,
  ULONG *FifoSize,
  ULONG *Delay
)
{...}