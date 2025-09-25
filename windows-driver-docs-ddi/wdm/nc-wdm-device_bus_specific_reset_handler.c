DEVICE_BUS_SPECIFIC_RESET_HANDLER DeviceBusSpecificResetHandler;

NTSTATUS DeviceBusSpecificResetHandler(
  [in] PVOID InterfaceContext,
  [in] const GUID *BusType,
  [in] DEVICE_BUS_SPECIFIC_RESET_TYPE ResetTypeSelected,
  [in] PBUS_SPECIFIC_RESET_FLAGS Flags,
  [in] PVOID ResetParameters
)
{...}