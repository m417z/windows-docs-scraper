typedef struct _QOS_PACKET_PRIORITY {
  ULONG ConformantDSCPValue;
  ULONG NonConformantDSCPValue;
  ULONG ConformantL2Value;
  ULONG NonConformantL2Value;
} QOS_PACKET_PRIORITY, *PQOS_PACKET_PRIORITY;