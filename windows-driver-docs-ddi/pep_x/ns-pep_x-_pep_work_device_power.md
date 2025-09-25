# _PEP_WORK_DEVICE_POWER structure

## Description

The **PEP_WORK_DEVICE_POWER** structure describes the new power requirements for the specified device.

## Members

### `DeviceHandle`

A handle that represents the registration of the device with the Windows [power management framework](https://learn.microsoft.com/windows-hardware/drivers/kernel/overview-of-the-power-management-framework) (PoFx). A POHANDLE value that represents the registration of the device with PoFx. The platform extension plug-in (PEP) previously received this handle from PoFx during the [PEP_DPM_REGISTER_DEVICE](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_pep_register_crashdump_device) notification that informed the PEP that the device's driver stack registered the device with PoFx.

### `PowerRequired`

Whether the device requires power. Set to TRUE if the device requires power and the device driver must bring the device back to the D0 power state. Set to FALSE if the device is not required to stay turned on and the driver is permitted to transition the device from D0 to a low-power state.

## Remarks

The **DevicePower** member of the [PEP_WORK_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_pep_work_information) structure is a **PEP_WORK_DEVICE_POWER** structure.

## See also

[PEP_DPM_REGISTER_DEVICE](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_pep_register_crashdump_device)

[PEP_WORK_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_pep_work_information)