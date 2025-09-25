WMI_EXECUTE_METHOD_CALLBACK WmiExecuteMethodCallback;

NTSTATUS WmiExecuteMethodCallback(
  [in]      PDEVICE_OBJECT DeviceObject,
  [in]      PIRP Irp,
  [in]      ULONG GuidIndex,
  [in]      ULONG InstanceIndex,
  [in]      ULONG MethodId,
  [in]      ULONG InBufferSize,
  [in]      ULONG OutBufferSize,
  [in, out] PUCHAR Buffer
)
{...}