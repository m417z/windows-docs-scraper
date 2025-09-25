POFXCALLBACKPROCESSORIDLEVETO Pofxcallbackprocessoridleveto;

NTSTATUS Pofxcallbackprocessoridleveto(
  [in] POHANDLE ProcessorHandle,
  [in] ULONG ProcessorState,
  [in] ULONG VetoReason,
  [in] BOOLEAN Increment
)
{...}