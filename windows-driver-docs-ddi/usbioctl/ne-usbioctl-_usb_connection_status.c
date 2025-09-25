typedef enum _USB_CONNECTION_STATUS {
  NoDeviceConnected,
  DeviceConnected,
  DeviceFailedEnumeration,
  DeviceGeneralFailure,
  DeviceCausedOvercurrent,
  DeviceNotEnoughPower,
  DeviceNotEnoughBandwidth,
  DeviceHubNestedTooDeeply,
  DeviceInLegacyHub,
  DeviceEnumerating,
  DeviceReset
} USB_CONNECTION_STATUS, *PUSB_CONNECTION_STATUS;