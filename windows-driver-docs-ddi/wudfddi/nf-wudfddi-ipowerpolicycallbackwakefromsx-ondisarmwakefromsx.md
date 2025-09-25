# IPowerPolicyCallbackWakeFromSx::OnDisarmWakeFromSx

## Description

[**Warning:** UMDF 2 is the latest version of UMDF and supersedes UMDF 1. All new UMDF drivers should be written using UMDF 2. No new features are being added to UMDF 1 and there is limited support for UMDF 1 on newer versions of Windows 10. Universal Windows drivers must use UMDF 2. For more info, see [Getting Started with UMDF](https://learn.microsoft.com/windows-hardware/drivers/wdf/getting-started-with-umdf-version-2).]

A driver's **OnDisarmWakeFromSx** event callback function disarms (that is, disables) a device's ability to trigger a wake signal while the device and system are in low-power states.

## Parameters

### `pWdfDevice` [in]

A pointer to the [IWDFDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nn-wudfddi-iwdfdevice) interface of the device object that represents one of the driver's devices.

## Remarks

Your driver must provide an **OnDisarmWakeFromSx** callback function if the driver supports the [IPowerPolicyCallbackWakeFromSx](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nn-wudfddi-ipowerpolicycallbackwakefromsx) interface.

If the driver has registered this callback function, the framework calls it after the framework has determined that system power is being restored, and after the bus driver completes the [wait/wake IRP](https://learn.microsoft.com/windows-hardware/drivers/kernel/sending-a-wait-wake-irp). Before calling the driver's **OnDisarmWakeFromSx** callback function, the framework calls the driver's [IPnpCallback::OnD0Entry](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-ipnpcallback-ond0entry) and [IPowerPolicyCallbackWakeFromSx::OnWakeFromSxTriggered](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-ipowerpolicycallbackwakefromsx-onwakefromsxtriggered) callback functions.

The **OnDisarmWakeFromSx** callback function must perform any hardware operations that are needed to disable the device's ability to trigger a wake signal after the power has been lowered.

For more information about when the framework calls this callback function, see [PnP and Power Management Scenarios in UMDF](https://learn.microsoft.com/windows-hardware/drivers/wdf/pnp-and-power-management-scenarios-in-umdf).

For more information about this callback function, see [Supporting System Wake-Up in UMDF-based Drivers](https://learn.microsoft.com/windows-hardware/drivers/wdf/supporting-system-wake-up-in-umdf-drivers).

## See also

[IPowerPolicyCallbackWakeFromSx](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nn-wudfddi-ipowerpolicycallbackwakefromsx)

[IPowerPolicyCallbackWakeFromSx::OnArmWakeFromSx](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-ipowerpolicycallbackwakefromsx-onarmwakefromsx)

[IPowerPolicyCallbackWakeFromSx::OnWakeFromSxTriggered](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-ipowerpolicycallbackwakefromsx-onwakefromsxtriggered)