EVT_WDF_WMI_INSTANCE_EXECUTE_METHOD EvtWdfWmiInstanceExecuteMethod;

NTSTATUS EvtWdfWmiInstanceExecuteMethod(
  [in]      WDFWMIINSTANCE WmiInstance,
  [in]      ULONG MethodId,
  [in]      ULONG InBufferSize,
  [in]      ULONG OutBufferSize,
  [in, out] PVOID Buffer,
  [out]     PULONG BufferUsed
)
{...}