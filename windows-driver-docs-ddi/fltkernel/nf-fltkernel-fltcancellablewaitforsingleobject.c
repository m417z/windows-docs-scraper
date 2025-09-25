NTSTATUS FLTAPI FltCancellableWaitForSingleObject(
  [in]           PVOID              Object,
  [in, optional] PLARGE_INTEGER     Timeout,
  [in, optional] PFLT_CALLBACK_DATA CallbackData
);