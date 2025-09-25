PSHED_PI_SET_ERROR_SOURCE_INFO PshedPiSetErrorSourceInfo;

NTSTATUS PshedPiSetErrorSourceInfo(
  [in, out, optional] PVOID PluginContext,
  [in]                PWHEA_ERROR_SOURCE_DESCRIPTOR ErrorSource
)
{...}