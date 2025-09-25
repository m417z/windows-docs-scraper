PSHED_PI_ATTEMPT_ERROR_RECOVERY PshedPiAttemptErrorRecovery;

NTSTATUS PshedPiAttemptErrorRecovery(
  [in, out, optional] PVOID PluginContext,
  [in]                ULONG BufferLength,
  [in]                PWHEA_ERROR_RECORD ErrorRecord
)
{...}