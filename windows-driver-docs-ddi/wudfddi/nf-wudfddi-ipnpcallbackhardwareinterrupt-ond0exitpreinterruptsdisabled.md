# IPnpCallbackHardwareInterrupt::OnD0ExitPreInterruptsDisabled

## Description

> [!WARNING]
> UMDF 2 is the latest version of UMDF and supersedes UMDF 1. All new UMDF drivers should be written using UMDF 2. No new features are being added to UMDF 1 and there is limited support for UMDF 1 on newer versions of Windows 10. Universal Windows drivers must use UMDF 2. For more info, see [Getting Started with UMDF](https://learn.microsoft.com/windows-hardware/drivers/wdf/getting-started-with-umdf-version-2).

A driver's **OnD0ExitPreInterruptsDisabled** event callback function performs device-specific operations that are required before the driver disables the device's hardware interrupts.

## Parameters

### `pDevice`

A pointer to an [IWDFDevice3](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nn-wudfddi-iwdfdevice3) interface.

### `TargetState` [in]

A [WDF_POWER_DEVICE_STATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/ne-wdfdevice-_wdf_power_device_state) enumerator value that identifies the target device power state that the device is about to enter.

## Return value

If successful, **OnD0ExitPreInterruptsDisabled**, returns S_OK. Otherwise, it returns an appropriate failure status.

## See also

- [Enabling and Disabling Interrupts](https://learn.microsoft.com/windows-hardware/drivers/wdf/enabling-and-disabling-interrupts)
- [IPnpCallbackHardwareInterrupt](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nn-wudfddi-ipnpcallbackhardwareinterrupt)
- [OnD0EntryPostInterruptsEnabled](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-ipnpcallbackhardwareinterrupt-ond0entrypostinterruptsenabled)