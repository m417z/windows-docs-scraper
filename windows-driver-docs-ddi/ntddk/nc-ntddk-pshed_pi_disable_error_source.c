PSHED_PI_DISABLE_ERROR_SOURCE PshedPiDisableErrorSource;

NTSTATUS PshedPiDisableErrorSource(
  [in, out, optional] PVOID PluginContext,
  [in]                PWHEA_ERROR_SOURCE_DESCRIPTOR ErrorSource
)
{...}