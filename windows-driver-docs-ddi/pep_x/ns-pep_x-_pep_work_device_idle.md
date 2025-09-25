# _PEP_WORK_DEVICE_IDLE structure

## Description

The **PEP_WORK_DEVICE_IDLE** structure indicates whether to ignore the idle time-out for the specified device.

## Members

### `DeviceHandle`

A handle that represents the registration of the device with the Windows [power management framework](https://learn.microsoft.com/windows-hardware/drivers/kernel/overview-of-the-power-management-framework) (PoFx). A POHANDLE value that represents the registration of the device with PoFx. The platform extension plug-in (PEP) previously received this handle from PoFx during the [PEP_DPM_REGISTER_DEVICE](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_pep_register_crashdump_device) notification that informed the PEP that the device's driver stack registered the device with PoFx.

### `IgnoreIdleTimeout`

Whether to ignore the idle time-out. Set to TRUE to tell the operating system to ignore the idle time-out for this device. Set to FALSE to tell the operating system to call the device driver's [DevicePowerNotRequiredCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-po_fx_device_power_not_required_callback) callback routine after the device remains idle for the designated time-out interval. For more information, see [PoFxSetDeviceIdleTimeout](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-pofxsetdeviceidletimeout).

## Remarks

The **DeviceIdle** member of the [PEP_WORK_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_pep_work_information) structure is a **PEP_WORK_DEVICE_IDLE** structure.

## See also

[PEP_DPM_REGISTER_DEVICE](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_pep_register_crashdump_device)

[PEP_WORK_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_pep_work_information)

[PoFxSetDeviceIdleTimeout](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-pofxsetdeviceidletimeout)