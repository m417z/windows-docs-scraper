typedef struct _QOS_FLOW_FUNDAMENTALS {
  BOOL   BottleneckBandwidthSet;
  UINT64 BottleneckBandwidth;
  BOOL   AvailableBandwidthSet;
  UINT64 AvailableBandwidth;
  BOOL   RTTSet;
  UINT32 RTT;
} QOS_FLOW_FUNDAMENTALS, *PQOS_FLOW_FUNDAMENTALS;