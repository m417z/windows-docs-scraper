NTSTATUS RxDispatchToWorkerThread(
  [in] IN PRDBSS_DEVICE_OBJECT     pMRxDeviceObject,
  [in] IN WORK_QUEUE_TYPE          WorkQueueType,
  [in] IN PRX_WORKERTHREAD_ROUTINE Routine,
  [in] IN PVOID                    pContext
);