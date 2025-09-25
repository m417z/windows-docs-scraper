PSCSIWMI_QUERY_DATABLOCK PscsiwmiQueryDatablock;

BOOLEAN PscsiwmiQueryDatablock(
  [in]      PVOID Context,
  [in]      PSCSIWMI_REQUEST_CONTEXT DispatchContext,
  [in]      ULONG GuidIndex,
  [in]      ULONG InstanceIndex,
  [in]      ULONG InstanceCount,
  [in, out] PULONG InstanceLengthArray,
  [in]      ULONG BufferAvail,
  [out]     PUCHAR Buffer
)
{...}