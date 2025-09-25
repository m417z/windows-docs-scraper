VOID IoQueueWorkItemEx(
  [in]           __drv_aliasesMem PIO_WORKITEM IoWorkItem,
  [in]           PIO_WORKITEM_ROUTINE_EX       WorkerRoutine,
  [in]           WORK_QUEUE_TYPE               QueueType,
  [in, optional] __drv_aliasesMem PVOID        Context
);