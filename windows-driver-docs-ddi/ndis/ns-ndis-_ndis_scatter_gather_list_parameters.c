typedef struct _NDIS_SCATTER_GATHER_LIST_PARAMETERS {
  NDIS_OBJECT_HEADER           Header;
  ULONG                        Flags;
  NDIS_RECEIVE_QUEUE_ID        QueueId;
  NDIS_SHARED_MEMORY_USAGE     SharedMemoryUsage;
  PMDL                         Mdl;
  PVOID                        CurrentVa;
  ULONG                        Length;
  NDIS_PROCESS_SG_LIST_HANDLER ProcessSGListHandler;
  PVOID                        Context;
  PSCATTER_GATHER_LIST         ScatterGatherListBuffer;
  ULONG                        ScatterGatherListBufferSize;
  ULONG                        ScatterGatherListBufferSizeNeeded;
} NDIS_SCATTER_GATHER_LIST_PARAMETERS, *PNDIS_SCATTER_GATHER_LIST_PARAMETERS;