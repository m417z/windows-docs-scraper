PSHED_PI_WRITE_ERROR_RECORD PshedPiWriteErrorRecord;

NTSTATUS PshedPiWriteErrorRecord(
  [in, out, optional] PVOID PluginContext,
  [in]                ULONG Flags,
  [in]                ULONG RecordLength,
  [in]                PWHEA_ERROR_RECORD ErrorRecord
)
{...}