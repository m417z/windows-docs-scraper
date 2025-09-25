NTSTATUS WdfDeviceInitRegisterPnpStateChangeCallback(
  [in] PWDFDEVICE_INIT                              DeviceInit,
  [in] WDF_DEVICE_PNP_STATE                         PnpState,
  [in] PFN_WDF_DEVICE_PNP_STATE_CHANGE_NOTIFICATION EvtDevicePnpStateChange,
  [in] ULONG                                        CallbackTypes
);