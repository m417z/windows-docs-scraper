PRM_INVOKE_HANDLER PrmInvokeHandler;

NTSTATUS PrmInvokeHandler(
  [in]  LPGUID HandlerGuid,
  [in]  PVOID ParameterBuffer,
  [in]  ULONG Reserved,
  [out] PULONG64 EfiStatus
)
{...}