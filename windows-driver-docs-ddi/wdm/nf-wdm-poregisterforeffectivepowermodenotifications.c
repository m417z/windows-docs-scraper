NTSTATUS PoRegisterForEffectivePowerModeNotifications(
  ULONG                             Version,
  PPO_EFFECTIVE_POWER_MODE_CALLBACK Callback,
  PVOID                             Context,
  PO_EPM_HANDLE                     *RegistrationHandle,
  PDEVICE_OBJECT                    DeviceObject
);