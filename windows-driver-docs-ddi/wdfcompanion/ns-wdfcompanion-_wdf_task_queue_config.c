typedef struct _WDF_TASK_QUEUE_CONFIG {
  ULONG                                Size;
  USHORT                               TaskQueueId;
  WDF_TASK_QUEUE_DISPATCH_TYPE         DispatchType;
  PFN_WDF_TASK_QUEUE_TASK_EXECUTE_SYNC EvtTaskExecuteSync;
} WDF_TASK_QUEUE_CONFIG, *PWDF_TASK_QUEUE_CONFIG;