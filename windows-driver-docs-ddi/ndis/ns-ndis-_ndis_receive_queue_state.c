typedef struct _NDIS_RECEIVE_QUEUE_STATE {
  NDIS_OBJECT_HEADER                   Header;
  ULONG                                Flags;
  NDIS_RECEIVE_QUEUE_ID                QueueId;
  NDIS_RECEIVE_QUEUE_OPERATIONAL_STATE QueueState;
} NDIS_RECEIVE_QUEUE_STATE, *PNDIS_RECEIVE_QUEUE_STATE;