typedef struct _NDIS_QOS_SQ_STATS {
  NDIS_OBJECT_HEADER Header;
  ULONG              Flags;
  NDIS_QOS_SQ_ID     SqId;
  NDIS_QOS_SQ_TYPE   SqType;
  UINT64             BytesTransmitted[NDIS_QOS_MAXIMUM_TRAFFIC_CLASSES];
  UINT64             PktsTransmitted[NDIS_QOS_MAXIMUM_TRAFFIC_CLASSES];
} NDIS_QOS_SQ_STATS, *PNDIS_QOS_SQ_STATS;