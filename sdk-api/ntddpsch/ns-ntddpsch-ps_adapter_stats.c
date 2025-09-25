typedef struct _PS_ADAPTER_STATS {
  ULONG OutOfPackets;
  ULONG FlowsOpened;
  ULONG FlowsClosed;
  ULONG FlowsRejected;
  ULONG FlowsModified;
  ULONG FlowModsRejected;
  ULONG MaxSimultaneousFlows;
} PS_ADAPTER_STATS, *PPS_ADAPTER_STATS;