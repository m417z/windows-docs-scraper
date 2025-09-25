NTSTATUS RxCancelTimerRequest(
  [in] IN PRDBSS_DEVICE_OBJECT     pDeviceObject,
  [in] IN PRX_WORKERTHREAD_ROUTINE Routine,
  [in] IN PVOID                    pContext
);