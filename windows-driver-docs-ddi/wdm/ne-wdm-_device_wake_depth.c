typedef enum _DEVICE_WAKE_DEPTH {
  DeviceWakeDepthNotWakeable,
  DeviceWakeDepthD0,
  DeviceWakeDepthD1,
  DeviceWakeDepthD2,
  DeviceWakeDepthD3hot,
  DeviceWakeDepthD3cold,
  DeviceWakeDepthMaximum
} DEVICE_WAKE_DEPTH, *PDEVICE_WAKE_DEPTH;