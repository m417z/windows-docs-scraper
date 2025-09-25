NTSTATUS FLTAPI FltRequestOperationStatusCallback(
  [in]           PFLT_CALLBACK_DATA                 Data,
  [in]           PFLT_GET_OPERATION_STATUS_CALLBACK CallbackRoutine,
  [in, optional] PVOID                              RequesterContext
);