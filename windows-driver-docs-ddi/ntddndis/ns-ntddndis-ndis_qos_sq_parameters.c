typedef struct _NDIS_QOS_SQ_PARAMETERS {
  NDIS_OBJECT_HEADER Header;
  ULONG              Flags;
  NDIS_QOS_SQ_ID     SqId;
  NDIS_QOS_SQ_TYPE   SqType;
  BOOLEAN            TcEnabledTable[NDIS_QOS_MAXIMUM_TRAFFIC_CLASSES];
  ULONG              TcTransmitBandwidthCapTable[NDIS_QOS_MAXIMUM_TRAFFIC_CLASSES];
  ULONG              TcTransmitBandwidthReservationTable[NDIS_QOS_MAXIMUM_TRAFFIC_CLASSES];
  ULONG              TcReceiveBandwidthCapTable[NDIS_QOS_MAXIMUM_TRAFFIC_CLASSES];
  ULONG              CrossTcTransmitBandwidthCap;
  ULONG              MaxNumSqInputs;
} NDIS_QOS_SQ_PARAMETERS, *PNDIS_QOS_SQ_PARAMETERS;