DEVICE_RESET_HANDLER DeviceResetHandler;

NTSTATUS DeviceResetHandler(
  [in]           PVOID InterfaceContext,
  [in]           DEVICE_RESET_TYPE ResetType,
  [in]           ULONG Flags,
  [in, optional] PVOID ResetParameters
)
{...}