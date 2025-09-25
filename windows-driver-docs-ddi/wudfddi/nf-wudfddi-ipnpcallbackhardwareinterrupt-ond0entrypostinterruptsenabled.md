# IPnpCallbackHardwareInterrupt::OnD0EntryPostInterruptsEnabled

## Description

> [!WARNING]
> UMDF 2 is the latest version of UMDF and supersedes UMDF 1. All new UMDF drivers should be written using UMDF 2. No new features are being added to UMDF 1 and there is limited support for UMDF 1 on newer versions of Windows 10. Universal Windows drivers must use UMDF 2. For more info, see [Getting Started with UMDF](https://learn.microsoft.com/windows-hardware/drivers/wdf/getting-started-with-umdf-version-2).

A driver's **OnD0EntryPostInterruptsEnabled** event callback function performs device-specific operations that are required when the driver enables the device's hardware interrupts.

## Parameters

### `pDevice`

A pointer to [IWDFDevice3](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nn-wudfddi-iwdfdevice3) interface.

### `PreviousState` [in]

A [WDF_POWER_DEVICE_STATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/ne-wdfdevice-_wdf_power_device_state) enumerator value that identifies the previous device power state.

## Return value

If successful, **OnD0EntryPostInterruptsEnabled** returns S_OK. Otherwise, it returns an appropriate failure status.

## See also

- [IPnpCallbackHardwareInterrupt](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nn-wudfddi-ipnpcallbackhardwareinterrupt)
- [OnD0ExitPreInterruptsDisabled](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-ipnpcallbackhardwareinterrupt-ond0exitpreinterruptsdisabled)
- [Enabling and Disabling Interrupts](https://learn.microsoft.com/windows-hardware/drivers/wdf/enabling-and-disabling-interrupts)