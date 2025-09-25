ULONG StorPortIsDeviceOperationAllowed(
  [in]  PVOID         HwDeviceExtension,
  [in]  PSTOR_ADDRESS Address,
  [in]  LPCGUID       DeviceOperation,
  [out] ULONG         *AllowedFlag
);