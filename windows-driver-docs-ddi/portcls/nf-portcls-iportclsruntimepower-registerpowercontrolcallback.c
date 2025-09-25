NTSTATUS RegisterPowerControlCallback(
  [in]           PDEVICE_OBJECT                      _DeviceObject,
  [in]           PCPFNRUNTIME_POWER_CONTROL_CALLBACK _Callback,
  [in, optional] PVOID                               _Context
);