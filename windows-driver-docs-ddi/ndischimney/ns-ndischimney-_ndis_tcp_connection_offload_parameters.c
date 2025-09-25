typedef struct _NDIS_TCP_CONNECTION_OFFLOAD_PARAMETERS {
  NDIS_OBJECT_HEADER         Header;
  NDIS_OFFLOAD_ENCAPSULATION Encapsulation;
  ULONG                      TicksPerSecond;
  UCHAR                      TcpAckFrequency;
  UCHAR                      TcpDelayedAckTicks;
  UCHAR                      TcpMaximumRetransmissions;
  UCHAR                      TcpDoubtReachabilityRetransmissions;
  ULONG                      TcpSwsPreventionTicks;
  ULONG                      TcpDuplicateAckThreshold;
  ULONG                      TcpPushTicks;
  ULONG                      NceStaleTicks;
  ULONG                      CongestionAlgorithm;
} NDIS_TCP_CONNECTION_OFFLOAD_PARAMETERS, *PNDIS_TCP_CONNECTION_OFFLOAD_PARAMETERS;