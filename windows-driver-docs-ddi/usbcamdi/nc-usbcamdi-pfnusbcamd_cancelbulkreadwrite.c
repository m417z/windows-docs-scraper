PFNUSBCAMD_CancelBulkReadWrite PfnusbcamdCancelbulkreadwrite;

NTSTATUS PfnusbcamdCancelbulkreadwrite(
  [in] PVOID DeviceContext,
  [in] ULONG PipeIndex
)
{...}