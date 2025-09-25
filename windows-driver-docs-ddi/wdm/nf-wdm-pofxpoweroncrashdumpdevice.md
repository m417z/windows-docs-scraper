# PoFxPowerOnCrashdumpDevice function

## Description

The **PoFxPowerOnCrashdumpDevice** routine requests that a crash-dump device be turned on.

## Parameters

### `Handle` [in]

A handle that represents the registration of the crash-dump device with the Windows [power management framework](https://learn.microsoft.com/windows-hardware/drivers/ddi/_kernel/#device-power-management) (PoFx). The device driver previously received this handle from the [PoFxRegisterDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-pofxregisterdevice) routine.

### `Context` [in, optional]

A pointer to a device-specific context. This pointer is passed as an input parameter to the [PowerOnDumpDeviceCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/nc-pepfx-pepcallbackpoweroncrashdumpdevice) callback routine that is implemented by the platform extension plug-in (PEP) for the device. The context information is stored in a format that is defined by the device driver and is understood by the PEP. This context is opaque to the operating system. The driver can set this parameter to NULL if the PEP does not require a context.

## Return value

**PoFxPowerOnCrashdumpDevice** returns STATUS_SUCCESS if the routine succeeds in turning on power to the device. Possible error return values include the following status codes.

| Return value | Description |
| --- | --- |
| STATUS_INVALID_PARAMETER | Not a valid handle value. |
| STATUS_UNSUCCESSFUL | The PEP for this device does not implement a *PowerOnDumpDeviceCallback* callback routine; or the PEP failed to turn on the device. |

## Remarks

The driver for a crash-dump device calls this routine to request that the platform extension plug-in (PEP) turn the device on so that a crash dump can be saved. All devices in the crash-dump device chain (which might include a storage controller, a PCI controller, and so on) must be turned on before a crash-dump file can be written to disk.

For more information about crash dumps, see [Kernel-Mode Dump Files](https://learn.microsoft.com/windows-hardware/drivers/debugger/kernel-mode-dump-files).

This routine can be called at IRQL <= HIGH_LEVEL.

## See also

[PoFxRegisterDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-pofxregisterdevice)

[PowerOnDumpDeviceCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/nc-pepfx-pepcallbackpoweroncrashdumpdevice)