EVT_WDF_WMI_PROVIDER_FUNCTION_CONTROL EvtWdfWmiProviderFunctionControl;

NTSTATUS EvtWdfWmiProviderFunctionControl(
  [in] WDFWMIPROVIDER WmiProvider,
  [in] WDF_WMI_PROVIDER_CONTROL Control,
  [in] BOOLEAN Enable
)
{...}