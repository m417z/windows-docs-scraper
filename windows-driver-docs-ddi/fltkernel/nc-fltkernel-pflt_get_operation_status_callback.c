PFLT_GET_OPERATION_STATUS_CALLBACK PfltGetOperationStatusCallback;

VOID PfltGetOperationStatusCallback(
  [in]           PCFLT_RELATED_OBJECTS FltObjects,
  [in]           PFLT_IO_PARAMETER_BLOCK IopbSnapshot,
  [in]           NTSTATUS OperationStatus,
  [in, optional] PVOID RequesterContext
)
{...}