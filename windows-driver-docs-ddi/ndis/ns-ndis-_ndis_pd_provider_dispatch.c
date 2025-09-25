typedef struct _NDIS_PD_PROVIDER_DISPATCH {
  NDIS_OBJECT_HEADER                         Header;
  ULONG                                      Flags;
  NDIS_PD_ALLOCATE_QUEUE_HANDLER             NdisPDAllocateQueue;
  NDIS_PD_FREE_QUEUE_HANDLER                 NdisPDFreeQueue;
  NDIS_PD_ACQUIRE_RECEIVE_QUEUES_HANDLER     NdisPDAcquireReceiveQueues;
  NDIS_PD_RELEASE_RECEIVE_QUEUES_HANDLER     NdisPDReleaseReceiveQueues;
  NDIS_PD_ALLOCATE_COUNTER_HANDLER           NdisPDAllocateCounter;
  NDIS_PD_FREE_COUNTER_HANDLER               NdisPDFreeCounter;
  NDIS_PD_QUERY_COUNTER_HANDLER              NdisPDQueryCounter;
  NDIS_PD_SET_RECEIVE_FILTER_HANDLER         NdisPDSetReceiveFilter;
  NDIS_PD_CLEAR_RECEIVE_FILTER_HANDLER       NdisPDClearReceiveFilter;
  NDIS_PD_REQUEST_DRAIN_NOTIFICATION_HANDLER NdisPDRequestDrainNotification;
  NDIS_PD_QUEUE_CONTROL_HANDLER              NdisPDQueueControl;
  NDIS_PD_PROVIDER_CONTROL_HANDLER           NdisPDProviderControl;
} NDIS_PD_PROVIDER_DISPATCH;