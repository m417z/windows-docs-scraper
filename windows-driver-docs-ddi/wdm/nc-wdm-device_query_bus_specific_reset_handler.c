DEVICE_QUERY_BUS_SPECIFIC_RESET_HANDLER DeviceQueryBusSpecificResetHandler;

NTSTATUS DeviceQueryBusSpecificResetHandler(
  [in]  PVOID InterfaceContext,
  [out] PULONG ResetInfoCount,
  [out] PDEVICE_BUS_SPECIFIC_RESET_INFO ResetInfoSupported
)
{...}