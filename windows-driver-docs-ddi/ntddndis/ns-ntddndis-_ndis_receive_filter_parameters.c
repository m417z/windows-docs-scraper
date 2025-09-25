typedef struct _NDIS_RECEIVE_FILTER_PARAMETERS {
  NDIS_OBJECT_HEADER       Header;
  ULONG                    Flags;
  NDIS_RECEIVE_FILTER_TYPE FilterType;
  NDIS_RECEIVE_QUEUE_ID    QueueId;
  NDIS_RECEIVE_FILTER_ID   FilterId;
  ULONG                    FieldParametersArrayOffset;
  ULONG                    FieldParametersArrayNumElements;
  ULONG                    FieldParametersArrayElementSize;
  ULONG                    RequestedFilterIdBitCount;
  ULONG                    MaxCoalescingDelay;
  NDIS_NIC_SWITCH_VPORT_ID VPortId;
} NDIS_RECEIVE_FILTER_PARAMETERS, *PNDIS_RECEIVE_FILTER_PARAMETERS;