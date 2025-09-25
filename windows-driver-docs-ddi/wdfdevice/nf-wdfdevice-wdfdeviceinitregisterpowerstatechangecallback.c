NTSTATUS WdfDeviceInitRegisterPowerStateChangeCallback(
  [in] PWDFDEVICE_INIT                                DeviceInit,
  [in] WDF_DEVICE_POWER_STATE                         PowerState,
  [in] PFN_WDF_DEVICE_POWER_STATE_CHANGE_NOTIFICATION EvtDevicePowerStateChange,
  [in] ULONG                                          CallbackTypes
);