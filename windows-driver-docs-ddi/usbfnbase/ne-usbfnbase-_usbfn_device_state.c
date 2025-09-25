typedef enum _USBFN_DEVICE_STATE {
  UsbfnDeviceStateMinimum,
  UsbfnDeviceStateAttached,
  UsbfnDeviceStateDefault,
  UsbfnDeviceStateDetached,
  UsbfnDeviceStateAddressed,
  UsbfnDeviceStateConfigured,
  UsbfnDeviceStateSuspended,
  UsbfnDeviceStateStateMaximum
} USBFN_DEVICE_STATE, *PUSBFN_DEVICE_STATE;