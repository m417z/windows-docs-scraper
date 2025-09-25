typedef enum _STREAM_MINIDRIVER_DEVICE_NOTIFICATION_TYPE {
  ReadyForNextDeviceRequest,
  DeviceRequestComplete,
  SignalMultipleDeviceEvents,
  SignalDeviceEvent,
  DeleteDeviceEvent,
  SignalMultipleDeviceInstanceEvents,
  DeviceNotificationMaximum
} STREAM_MINIDRIVER_DEVICE_NOTIFICATION_TYPE, *PSTREAM_MINIDRIVER_DEVICE_NOTIFICATION_TYPE;