PFNUSBCAMD_WaitOnDeviceEvent PfnusbcamdWaitondeviceevent;

NTSTATUS PfnusbcamdWaitondeviceevent(
  [in] PVOID DeviceContext,
  [in] ULONG PipeIndex,
  [in] PVOID Buffer,
  [in] ULONG BufferLength,
  [in] PCOMMAND_COMPLETE_FUNCTION EventComplete,
  [in] PVOID EventContext,
  [in] BOOLEAN LoopBack
)
{...}