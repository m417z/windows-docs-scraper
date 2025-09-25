PSHED_PI_GET_INJECTION_CAPABILITIES PshedPiGetInjectionCapabilities;

NTSTATUS PshedPiGetInjectionCapabilities(
  [in, out, optional] PVOID PluginContext,
  [out]               PWHEA_ERROR_INJECTION_CAPABILITIES Capabilities
)
{...}