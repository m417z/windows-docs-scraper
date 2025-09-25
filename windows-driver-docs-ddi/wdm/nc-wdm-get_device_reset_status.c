GET_DEVICE_RESET_STATUS GetDeviceResetStatus;

NTSTATUS GetDeviceResetStatus(
  [in]  PVOID InterfaceContext,
  [out] PBOOLEAN IsResetting,
  [out] PDEVICE_BUS_SPECIFIC_RESET_TYPE ResetTypeSelected,
  [out] PDEVICE_RESET_STATUS_FLAGS Flags
)
{...}