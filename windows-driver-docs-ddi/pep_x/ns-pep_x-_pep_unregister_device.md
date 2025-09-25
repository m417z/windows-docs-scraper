# _PEP_UNREGISTER_DEVICE structure (pep_x.h)

## Description

The **PEP_UNREGISTER_DEVICE** structure identifies a device whose registration is being removed from the Windows [power management framework](https://learn.microsoft.com/windows-hardware/drivers/kernel/overview-of-the-power-management-framework) (PoFx).

## Members

### `DeviceHandle` [in]

A PEPHANDLE value that identifies the device. The PEP supplied this handle in response to a previous [PEP_DPM_REGISTER_DEVICE](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_pep_register_crashdump_device) notification.

## Remarks

This structure is used by the [PEP_DPM_UNREGISTER_DEVICE](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-peps-for-acpi-services) notification. The **DeviceHandle** member contains an input value that is supplied by the Windows [power management framework](https://learn.microsoft.com/windows-hardware/drivers/kernel/overview-of-the-power-management-framework) (PoFx).

## See also

[PEP_DPM_REGISTER_DEVICE](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_pep_register_crashdump_device)

[PEP_DPM_UNREGISTER_DEVICE](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-peps-for-acpi-services)