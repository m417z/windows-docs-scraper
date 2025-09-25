typedef struct _L2CAP_EXTENDED_FLOW_SPEC {
  UCHAR  Identifier;
  UCHAR  ServiceType;
  USHORT MaxSDUSize;
  ULONG  SDUInterArrivalTime;
  ULONG  AccessLatency;
  ULONG  FlushTimeout;
} L2CAP_EXTENDED_FLOW_SPEC, *PL2CAP_EXTENDED_FLOW_SPEC;