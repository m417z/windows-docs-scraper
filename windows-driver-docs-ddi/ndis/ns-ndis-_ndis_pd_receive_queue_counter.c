typedef struct _NDIS_PD_RECEIVE_QUEUE_COUNTER {
  ULONG64 PacketsReceived;
  ULONG64 BytesReceived;
  ULONG64 PacketsDropped;
} NDIS_PD_RECEIVE_QUEUE_COUNTER;