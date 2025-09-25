VOID WdfControlDeviceInitSetShutdownNotification(
  [in] PWDFDEVICE_INIT                      DeviceInit,
  [in] PFN_WDF_DEVICE_SHUTDOWN_NOTIFICATION Notification,
  [in] UCHAR                                Flags
);