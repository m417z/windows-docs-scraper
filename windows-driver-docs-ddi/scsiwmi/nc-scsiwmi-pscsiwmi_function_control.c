PSCSIWMI_FUNCTION_CONTROL PscsiwmiFunctionControl;

BOOLEAN PscsiwmiFunctionControl(
  [in] PVOID DeviceContext,
  [in] PSCSIWMI_REQUEST_CONTEXT RequestContext,
  [in] ULONG GuidIndex,
  [in] SCSIWMI_ENABLE_DISABLE_CONTROL Function,
  [in] BOOLEAN Enable
)
{...}