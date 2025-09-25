NTSTATUS FLTAPI FltQueueDeferredIoWorkItem(
  [in] PFLT_DEFERRED_IO_WORKITEM         FltWorkItem,
  [in] PFLT_CALLBACK_DATA                Data,
  [in] PFLT_DEFERRED_IO_WORKITEM_ROUTINE WorkerRoutine,
  [in] WORK_QUEUE_TYPE                   QueueType,
  [in] PVOID                             Context
);