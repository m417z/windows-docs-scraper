NTSTATUS FLTAPI FltCancellableWaitForMultipleObjects(
  [in]           ULONG              Count,
  [in]           PVOID []           ObjectArray,
  [in]           WAIT_TYPE          WaitType,
  [in, optional] PLARGE_INTEGER     Timeout,
  [in, optional] PKWAIT_BLOCK       WaitBlockArray,
  [in]           PFLT_CALLBACK_DATA CallbackData
);