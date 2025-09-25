# IPowerPolicyCallbackWakeFromSx::OnWakeFromSxTriggered

## Description

[**Warning:** UMDF 2 is the latest version of UMDF and supersedes UMDF 1. All new UMDF drivers should be written using UMDF 2. No new features are being added to UMDF 1 and there is limited support for UMDF 1 on newer versions of Windows 10. Universal Windows drivers must use UMDF 2. For more info, see [Getting Started with UMDF](https://learn.microsoft.com/windows-hardware/drivers/wdf/getting-started-with-umdf-version-2).]

A driver's **OnWakeFromSxTriggered** event callback function informs the driver that its device, which had previously entered a low-power device state because system power was reduced, might have triggered a wake signal.

## Parameters

### `pWdfDevice` [in]

A pointer to the [IWDFDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nn-wudfddi-iwdfdevice) interface of the device object that represents one of the driver's devices.

## Remarks

Your driver must provide an **OnWakeFromSxTriggered** callback function if the driver supports the [IPowerPolicyCallbackWakeFromSx](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nn-wudfddi-ipowerpolicycallbackwakefromsx) interface.

If the driver has registered this callback, the framework calls it after calling the driver's [IPnpCallback::OnD0Entry](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-ipnpcallback-ond0entry) callback function and before calling the driver's [IPowerPolicyCallbackWakeFromSx::OnDisarmWakeFromSx](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-ipowerpolicycallbackwakefromsx-ondisarmwakefromsx) callback function.

System hardware (BIOSes, motherboards, bus adapters) can sometimes drop a wake signal before the bus driver detects it, even though the signal wakes up the system. In such cases, the driver's **OnWakeFromSxTriggered** callback function will not be called even though the driver's device triggered a wake signal.

For more information about this callback function, see [Supporting System Wake-Up in UMDF-based Drivers](https://learn.microsoft.com/windows-hardware/drivers/wdf/supporting-system-wake-up-in-umdf-drivers).

## See also

[IPowerPolicyCallbackWakeFromSx](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nn-wudfddi-ipowerpolicycallbackwakefromsx)

[IPowerPolicyCallbackWakeFromSx::OnArmWakeFromSx](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-ipowerpolicycallbackwakefromsx-onarmwakefromsx)

[IPowerPolicyCallbackWakeFromSx::OnDisarmWakeFromSx](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-ipowerpolicycallbackwakefromsx-ondisarmwakefromsx)