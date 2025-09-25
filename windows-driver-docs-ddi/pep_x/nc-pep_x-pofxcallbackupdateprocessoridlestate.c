POFXCALLBACKUPDATEPROCESSORIDLESTATE Pofxcallbackupdateprocessoridlestate;

NTSTATUS Pofxcallbackupdateprocessoridlestate(
  [in] POHANDLE ProcessorHandle,
  [in] ULONG ProcessorState,
  [in] PPEP_PROCESSOR_IDLE_STATE_UPDATE Update
)
{...}