typedef struct _NDIS_PD_QUEUE_PARAMETERS {
  NDIS_OBJECT_HEADER     Header;
  ULONG                  Flags;
  NDIS_PD_QUEUE_TYPE     QueueType;
  ULONG                  QueueSize;
  ULONG                  ReceiveDataLength;
  GROUP_AFFINITY         Affinity;
  ULONG                  TrafficClassId;
  ULONG                  MaximumPartialBufferCount;
  NDIS_PD_COUNTER_HANDLE CounterHandle;
} NDIS_PD_QUEUE_PARAMETERS;