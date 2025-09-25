NTSTATUS FLTAPI FltPerformAsynchronousIo(
  [in, out] PFLT_CALLBACK_DATA               CallbackData,
  [in]      PFLT_COMPLETED_ASYNC_IO_CALLBACK CallbackRoutine,
  [in]      PVOID                            CallbackContext
);