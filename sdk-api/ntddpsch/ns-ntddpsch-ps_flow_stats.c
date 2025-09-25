typedef struct _PS_FLOW_STATS {
  ULONG         DroppedPackets;
  ULONG         PacketsScheduled;
  ULONG         PacketsTransmitted;
  LARGE_INTEGER BytesScheduled;
  LARGE_INTEGER BytesTransmitted;
} PS_FLOW_STATS, *PPS_FLOW_STATS;