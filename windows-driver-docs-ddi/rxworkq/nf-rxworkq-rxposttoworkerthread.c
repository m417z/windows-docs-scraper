NTSTATUS RxPostToWorkerThread(
  [in] IN PRDBSS_DEVICE_OBJECT     pMRxDeviceObject,
  [in] IN WORK_QUEUE_TYPE          WorkQueueType,
  [in] IN PRX_WORK_QUEUE_ITEM      pWorkQueueItem,
  [in] IN PRX_WORKERTHREAD_ROUTINE Routine,
  [in] IN PVOID                    pContext
);