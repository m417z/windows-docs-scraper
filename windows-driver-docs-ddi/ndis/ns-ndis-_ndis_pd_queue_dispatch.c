typedef struct _NDIS_PD_QUEUE_DISPATCH {
  NDIS_OBJECT_HEADER                            Header;
  ULONG                                         Flags;
  NDIS_PD_POST_AND_DRAIN_BUFFER_LIST_HANDLER    PDPostAndDrainBufferList;
  NDIS_PD_QUERY_QUEUE_DEPTH_HANDLER             PDQueryQueueDepth;
  NDIS_PD_FLUSH_QUEUE_HANDLER                   PDFlushQueue;
  NDIS_PD_POST_AND_DRAIN_BUFFER_LIST_EX_HANDLER PDPostAndDrainBufferListEx;
} NDIS_PD_QUEUE_DISPATCH;