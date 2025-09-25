PSHED_PI_FINALIZE_ERROR_RECORD PshedPiFinalizeErrorRecord;

NTSTATUS PshedPiFinalizeErrorRecord(
  [in, out, optional] PVOID PluginContext,
  [in]                PWHEA_ERROR_SOURCE_DESCRIPTOR ErrorSource,
  [in]                ULONG BufferLength,
  [in, out]           PWHEA_ERROR_RECORD ErrorRecord
)
{...}