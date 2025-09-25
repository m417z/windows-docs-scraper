typedef struct _NDIS_QOS_PARAMETERS {
  NDIS_OBJECT_HEADER Header;
  ULONG              Flags;
  ULONG              NumTrafficClasses;
  UCHAR              PriorityAssignmentTable[NDIS_QOS_MAXIMUM_PRIORITIES];
  UCHAR              TcBandwidthAssignmentTable[NDIS_QOS_MAXIMUM_TRAFFIC_CLASSES];
  UCHAR              TsaAssignmentTable[NDIS_QOS_MAXIMUM_TRAFFIC_CLASSES];
  ULONG              PfcEnable;
  ULONG              NumClassificationElements;
  ULONG              ClassificationElementSize;
  ULONG              FirstClassificationElementOffset;
} NDIS_QOS_PARAMETERS, *PNDIS_QOS_PARAMETERS;