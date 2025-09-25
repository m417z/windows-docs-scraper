typedef struct _NDIS_QOS_OFFLOAD_CAPABILITIES {
  NDIS_OBJECT_HEADER Header;
  ULONG              Flags;
  ULONG              SupportedSqTypes;
  BOOLEAN            TransmitCapSupported[NDIS_QOS_MAXIMUM_TRAFFIC_CLASSES];
  BOOLEAN            TransmitReservationSupported[NDIS_QOS_MAXIMUM_TRAFFIC_CLASSES];
  BOOLEAN            ReceiveCapSupported[NDIS_QOS_MAXIMUM_TRAFFIC_CLASSES];
  BOOLEAN            TransmitGftCapSupported[NDIS_QOS_MAXIMUM_TRAFFIC_CLASSES];
  BOOLEAN            ReceiveGftCapSupported[NDIS_QOS_MAXIMUM_TRAFFIC_CLASSES];
  BOOLEAN            TcSupportedTable[NDIS_QOS_MAXIMUM_TRAFFIC_CLASSES];
  ULONG              NumStandardSqsSupported;
  ULONG              NumGftSqsSupported;
  ULONG              ReservationGranularitySupported;
  ULONG              MaxNumSqInputs;
  BOOLEAN            CrossTcTransmitMaxCapSupported;
} NDIS_QOS_OFFLOAD_CAPABILITIES, *PNDIS_QOS_OFFLOAD_CAPABILITIES;