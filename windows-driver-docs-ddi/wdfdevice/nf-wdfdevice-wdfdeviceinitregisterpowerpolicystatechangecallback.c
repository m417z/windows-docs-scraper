NTSTATUS WdfDeviceInitRegisterPowerPolicyStateChangeCallback(
  [in] PWDFDEVICE_INIT                                       DeviceInit,
  [in] WDF_DEVICE_POWER_POLICY_STATE                         PowerPolicyState,
  [in] PFN_WDF_DEVICE_POWER_POLICY_STATE_CHANGE_NOTIFICATION EvtDevicePowerPolicyStateChange,
  [in] ULONG                                                 CallbackTypes
);