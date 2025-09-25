PSHED_PI_CLEAR_ERROR_STATUS PshedPiClearErrorStatus;

NTSTATUS PshedPiClearErrorStatus(
  [in, out, optional] PVOID PluginContext,
  [in]                PWHEA_ERROR_SOURCE_DESCRIPTOR ErrorSource,
  [in]                ULONG BufferLength,
  [in]                PWHEA_ERROR_RECORD ErrorRecord
)
{...}