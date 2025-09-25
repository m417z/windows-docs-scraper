# _PEP_DEVICE_STARTED structure (pepfx.h)

## Description

The **PEP_DEVICE_STARTED** structure identifies a device whose driver has completed its registration with the Windows [power management framework](https://learn.microsoft.com/windows-hardware/drivers/ddi/_kernel/#device-power-management) (PoFx).

## Members

### `DeviceHandle` [in]

A PEPHANDLE value that identifies the device. The PEP supplied this handle in response to a previous [PEP_DPM_REGISTER_DEVICE](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_pep_register_crashdump_device) notification.

## Remarks

This structure is used by the [PEP_DPM_DEVICE_STARTED](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_pep_device_started) notification. The **DeviceHandle** member of this structure contains an input value that is supplied by PoFx.

## See also

[PEP_DPM_DEVICE_STARTED](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_pep_device_started)

[PEP_DPM_REGISTER_DEVICE](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_pep_register_crashdump_device)