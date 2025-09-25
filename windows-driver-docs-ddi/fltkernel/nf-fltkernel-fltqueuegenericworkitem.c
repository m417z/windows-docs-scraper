NTSTATUS FLTAPI FltQueueGenericWorkItem(
  [in]           PFLT_GENERIC_WORKITEM         FltWorkItem,
  [in]           PVOID                         FltObject,
  [in]           PFLT_GENERIC_WORKITEM_ROUTINE WorkerRoutine,
  [in]           WORK_QUEUE_TYPE               QueueType,
  [in, optional] PVOID                         Context
);