PFNUSBCAMD_SetIsoPipeState PfnusbcamdSetisopipestate;

NTSTATUS PfnusbcamdSetisopipestate(
  [in] PVOID DeviceContext,
  [in] ULONG PipeStateFlags
)
{...}