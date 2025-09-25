# _PEP_REGISTER_CRASHDUMP_DEVICE structure (pepfx.h)

## Description

The **PEP_REGISTER_CRASHDUMP_DEVICE** structure provides a callback routine to turn on a crash-dump device.

## Members

### `PowerOnDumpDeviceCallback` [out]

A pointer to a [PowerOnDumpDeviceCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/nc-pepfx-pepcallbackpoweroncrashdumpdevice) callback routine that is implemented by the platform extension plug-in (PEP). This routine handles requests from the Windows kernel to turn on the crash-dump device so that a crash dump can be saved. For more information, see [Kernel-Mode Dump Files](https://learn.microsoft.com/windows-hardware/drivers/debugger/kernel-mode-dump-files).

### `DeviceHandle` [in]

A PEPHANDLE value that identifies the crash-dump device. The PEP supplied this handle in response to a previous [PEP_DPM_REGISTER_DEVICE](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_pep_register_crashdump_device) notification.

## Remarks

This structure is used by the [PEP_DPM_REGISTER_CRASHDUMP_DEVICE](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_pep_register_crashdump_device) notification. The **DeviceHandle** member of the structure contains an input value that is supplied by the Windows [power management framework](https://learn.microsoft.com/windows-hardware/drivers/ddi/_kernel/#device-power-management) (PoFx) when this notification is sent to the PEP. The **PowerOnDumpDeviceCallbackmember** contains an output value that the PEP writes to the structure in response to the notification.

## See also

[PEP_DPM_REGISTER_CRASHDUMP_DEVICE](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_pep_register_crashdump_device)

[PEP_DPM_REGISTER_DEVICE](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_pep_register_crashdump_device)

[PowerOnDumpDeviceCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/nc-pepfx-pepcallbackpoweroncrashdumpdevice)