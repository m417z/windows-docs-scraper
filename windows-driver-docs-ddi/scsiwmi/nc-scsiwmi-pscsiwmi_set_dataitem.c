PSCSIWMI_SET_DATAITEM PscsiwmiSetDataitem;

BOOLEAN PscsiwmiSetDataitem(
  [in] PVOID DeviceContext,
  [in] PSCSIWMI_REQUEST_CONTEXT RequestContext,
  [in] ULONG GuidIndex,
  [in] ULONG InstanceIndex,
  [in] ULONG DataItemId,
  [in] ULONG BufferSize,
  [in] PUCHAR Buffer
)
{...}