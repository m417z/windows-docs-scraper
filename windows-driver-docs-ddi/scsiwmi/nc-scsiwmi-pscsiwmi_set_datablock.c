PSCSIWMI_SET_DATABLOCK PscsiwmiSetDatablock;

BOOLEAN PscsiwmiSetDatablock(
  [in] PVOID DeviceContext,
  [in] PSCSIWMI_REQUEST_CONTEXT RequestContext,
  [in] ULONG GuidIndex,
  [in] ULONG InstanceIndex,
  [in] ULONG BufferSize,
  [in] PUCHAR Buffer
)
{...}