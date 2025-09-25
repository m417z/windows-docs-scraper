PSCSIWMI_EXECUTE_METHOD PscsiwmiExecuteMethod;

BOOLEAN PscsiwmiExecuteMethod(
  [in]      PVOID DeviceContext,
  [in]      PSCSIWMI_REQUEST_CONTEXT RequestContext,
  [in]      ULONG GuidIndex,
  [in]      ULONG InstanceIndex,
  [in]      ULONG MethodId,
  [in]      ULONG InBufferSize,
  [in]      ULONG OutBufferSize,
  [in, out] PUCHAR Buffer
)
{...}