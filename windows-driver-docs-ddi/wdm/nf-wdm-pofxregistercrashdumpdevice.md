# PoFxRegisterCrashdumpDevice function

## Description

The **PoFxRegisterCrashdumpDevice** routine registers a crash-dump device.

## Parameters

### `Handle`

A handle that represents the registration of the crash-dump device with the Windows [power management framework](https://learn.microsoft.com/windows-hardware/drivers/ddi/_kernel/#device-power-management) (PoFx). The device driver previously received this handle from the [PoFxRegisterDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-pofxregisterdevice) routine.

## Return value

**PoFxRegisterCrashdumpDevice** returns STATUS_SUCCESS if the routine successfully registers the crash-dump device. Possible error return values include the following status codes.

| Return value | Description |
| --- | --- |
| STATUS_INVALID_PARAMETER | Not a valid handle value. |
| STATUS_UNSUCCESSFUL | There is no PEP for this device. |

## Remarks

This routine is called by the driver for a crash-dump device to inform PoFx that the device is part of the crash-dump device chain. Several devices (storage controller, PCI controller, and so on) might need to be turned on so that the Windows kernel can write a crash-dump file to disk. When a fatal system error occurs, the kernel tries to turn on the crash-dump devices and save the crash-dump file.

The driver must call [PoFxRegisterDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-pofxregisterdevice) to register the device with PoFx before calling **PoFxRegisterCrashdumpDevice**.

The driver for a crash-dump device can call the [PoFxPowerOnCrashdumpDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-pofxpoweroncrashdumpdevice) routine to request that the PEP turn the device on.

For more information about crash dumps, see [Kernel-Mode Dump Files](https://learn.microsoft.com/windows-hardware/drivers/debugger/kernel-mode-dump-files).

**PoFxRegisterCrashdumpDevice** must be called at IRQL = PASSIVE_LEVEL.

## See also

[PoFxPowerOnCrashdumpDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-pofxpoweroncrashdumpdevice)

[PoFxRegisterDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-pofxregisterdevice)