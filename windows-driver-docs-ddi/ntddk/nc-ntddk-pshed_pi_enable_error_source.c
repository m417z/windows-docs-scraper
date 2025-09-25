PSHED_PI_ENABLE_ERROR_SOURCE PshedPiEnableErrorSource;

NTSTATUS PshedPiEnableErrorSource(
  [in, out, optional] PVOID PluginContext,
  [in]                PWHEA_ERROR_SOURCE_DESCRIPTOR ErrorSource
)
{...}