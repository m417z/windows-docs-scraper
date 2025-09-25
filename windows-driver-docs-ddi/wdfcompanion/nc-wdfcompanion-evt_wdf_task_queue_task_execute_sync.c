EVT_WDF_TASK_QUEUE_TASK_EXECUTE_SYNC EvtWdfTaskQueueTaskExecuteSync;

NTSTATUS EvtWdfTaskQueueTaskExecuteSync(
  [in]            WDFTASKQUEUE Queue,
  [in, optional]  PVOID InputBuffer,
  [out, optional] PVOID OutputBuffer,
  [in]            size_t InputBufferLength,
  [in]            size_t OutputBufferLength,
  [in]            size_t *BytesWritten,
  [in]            ULONG TaskOperationCode
)
{...}