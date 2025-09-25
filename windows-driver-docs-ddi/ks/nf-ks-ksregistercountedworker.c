KSDDKAPI NTSTATUS KsRegisterCountedWorker(
  [in]  WORK_QUEUE_TYPE  WorkQueueType,
  [in]  PWORK_QUEUE_ITEM CountedWorkItem,
  [out] PKSWORKER        *Worker
);