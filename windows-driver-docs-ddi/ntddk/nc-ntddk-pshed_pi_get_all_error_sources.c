PSHED_PI_GET_ALL_ERROR_SOURCES PshedPiGetAllErrorSources;

NTSTATUS PshedPiGetAllErrorSources(
  [in, out, optional] PVOID PluginContext,
  [in, out]           PULONG Count,
  [in, out]           PWHEA_ERROR_SOURCE_DESCRIPTOR *ErrorSrcs,
  [in, out]           PULONG Length
)
{...}