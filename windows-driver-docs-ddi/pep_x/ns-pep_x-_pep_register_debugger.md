# _PEP_REGISTER_DEBUGGER structure (pep_x.h)

## Description

The **PEP_REGISTER_DEBUGGER** structure identifies a registered device that is a core system resource that provides debugger transport.

## Members

### `DeviceHandle` [in]

A **PEPHANDLE** value that identifies the device. The PEP supplied this handle in response to a previous [PEP_DPM_REGISTER_DEVICE](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_pep_register_crashdump_device) notification.

## Remarks

This structure is used by the [PEP_DPM_REGISTER_DEBUGGER](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_pep_register_debugger) notification. The **DeviceHandle** member contains an input value that is supplied by the Windows [power management framework](https://learn.microsoft.com/windows-hardware/drivers/ddi/_kernel/#device-power-management) (PoFx).

## See also

[PEP_DPM_REGISTER_DEBUGGER](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_pep_register_debugger)

[PEP_DPM_REGISTER_DEVICE](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_pep_register_crashdump_device)