PFNUSBCAMD_BulkReadWrite PfnusbcamdBulkreadwrite;

NTSTATUS PfnusbcamdBulkreadwrite(
  [in] PVOID DeviceContext,
  [in] USHORT PipeIndex,
  [in] PVOID Buffer,
  [in] ULONG BufferLength,
  [in] PCOMMAND_COMPLETE_FUNCTION CommandComplete,
  [in] PVOID CommandContext
)
{...}