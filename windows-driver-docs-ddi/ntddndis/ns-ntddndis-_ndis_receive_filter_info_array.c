typedef struct _NDIS_RECEIVE_FILTER_INFO_ARRAY {
  NDIS_OBJECT_HEADER       Header;
  NDIS_RECEIVE_QUEUE_ID    QueueId;
  ULONG                    FirstElementOffset;
  ULONG                    NumElements;
  ULONG                    ElementSize;
  ULONG                    Flags;
  NDIS_NIC_SWITCH_VPORT_ID VPortId;
} NDIS_RECEIVE_FILTER_INFO_ARRAY, *PNDIS_RECEIVE_FILTER_INFO_ARRAY;