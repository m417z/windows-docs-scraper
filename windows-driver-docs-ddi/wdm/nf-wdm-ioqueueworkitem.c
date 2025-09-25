VOID IoQueueWorkItem(
  [in]           __drv_aliasesMem PIO_WORKITEM IoWorkItem,
  [in]           PIO_WORKITEM_ROUTINE          WorkerRoutine,
  [in]           WORK_QUEUE_TYPE               QueueType,
  [in, optional] __drv_aliasesMem PVOID        Context
);