typedef enum _USB_NOTIFICATION_TYPE {
  EnumerationFailure,
  InsufficentBandwidth,
  InsufficentPower,
  OverCurrent,
  ResetOvercurrent,
  AcquireBusInfo,
  AcquireHubName,
  AcquireControllerName,
  HubOvercurrent,
  HubPowerChange,
  HubNestedTooDeeply,
  ModernDeviceInLegacyHub
} USB_NOTIFICATION_TYPE;