PSHED_PI_CLEAR_ERROR_RECORD PshedPiClearErrorRecord;

NTSTATUS PshedPiClearErrorRecord(
  [in, out, optional] PVOID PluginContext,
  [in]                ULONG Flags,
  [in]                ULONGLONG ErrorRecordId
)
{...}