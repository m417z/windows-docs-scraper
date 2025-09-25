NTSTATUS RxPostOneShotTimerRequest(
  [in] IN PRDBSS_DEVICE_OBJECT     pDeviceObject,
  [in] IN PRX_WORK_ITEM            pWorkItem,
  [in] IN PRX_WORKERTHREAD_ROUTINE Routine,
  [in] IN PVOID                    pContext,
  [in] IN LARGE_INTEGER            TimeInterval
);