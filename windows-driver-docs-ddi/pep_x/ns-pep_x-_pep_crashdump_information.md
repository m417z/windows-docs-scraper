# _PEP_CRASHDUMP_INFORMATION structure (pep_x.h)

## Description

The **PEP_CRASHDUMP_INFORMATION** structure contains information about a crash-dump device.

## Members

### `DeviceHandle` [in]

A PEPHANDLE value that identifies the crash-dump device. The platform extension plug-in (PEP) supplied this handle in response to a previous [PEP_DPM_REGISTER_DEVICE](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_pep_register_crashdump_device) notification.

### `DeviceContext` [in]

A pointer to a device-specific context. This pointer is the *Context* parameter value that the device driver previously passed to the [PoFxPowerOnCrashdumpDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-pofxpoweroncrashdumpdevice) routine. The context contains information in a format that is defined by the device driver and is understood by the PEP. The context is opaque to the operating system. This member value can be NULL if the PEP does not require a context.

## Remarks

The *CrashdumpInformation* parameter to the [PowerOnDumpDeviceCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/nc-pepfx-pepcallbackpoweroncrashdumpdevice) routine is a pointer to a **PEP_CRASHDUMP_INFORMATION** structure.

When a fatal system error occurs, the devices in the crash-dump device chain (storage controller, PCI controller, and so on) need to be turned on so that the Windows kernel can write a crash-dump file to disk.

## See also

[PEP_DPM_REGISTER_DEVICE](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_pep_register_crashdump_device)

[PoFxPowerOnCrashdumpDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-pofxpoweroncrashdumpdevice)

[PowerOnDumpDeviceCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/nc-pepfx-pepcallbackpoweroncrashdumpdevice)