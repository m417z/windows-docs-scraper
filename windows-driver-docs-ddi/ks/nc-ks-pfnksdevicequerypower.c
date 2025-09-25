PFNKSDEVICEQUERYPOWER Pfnksdevicequerypower;

NTSTATUS Pfnksdevicequerypower(
  [in] PKSDEVICE Device,
  [in] PIRP Irp,
  [in] DEVICE_POWER_STATE DeviceTo,
  [in] DEVICE_POWER_STATE DeviceFrom,
  [in] SYSTEM_POWER_STATE SystemTo,
  [in] SYSTEM_POWER_STATE SystemFrom,
  [in] POWER_ACTION Action
)
{...}