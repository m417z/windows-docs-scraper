DXGKCB_IS_DEVICE_PRESENT DxgkcbIsDevicePresent;

NTSTATUS DxgkcbIsDevicePresent(
  [in]  HANDLE DeviceHandle,
  [in]  PPCI_DEVICE_PRESENCE_PARAMETERS DevicePresenceParameters,
  [out] PBOOLEAN DevicePresent
)
{...}