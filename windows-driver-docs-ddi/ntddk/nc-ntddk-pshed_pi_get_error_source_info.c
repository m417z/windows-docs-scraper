PSHED_PI_GET_ERROR_SOURCE_INFO PshedPiGetErrorSourceInfo;

NTSTATUS PshedPiGetErrorSourceInfo(
  [in, out, optional] PVOID PluginContext,
  [in, out]           PWHEA_ERROR_SOURCE_DESCRIPTOR ErrorSource
)
{...}