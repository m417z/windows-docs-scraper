PFNKSDEVICESETPOWER Pfnksdevicesetpower;

void Pfnksdevicesetpower(
  [in] PKSDEVICE Device,
  [in] PIRP Irp,
  [in] DEVICE_POWER_STATE To,
  [in] DEVICE_POWER_STATE From
)
{...}