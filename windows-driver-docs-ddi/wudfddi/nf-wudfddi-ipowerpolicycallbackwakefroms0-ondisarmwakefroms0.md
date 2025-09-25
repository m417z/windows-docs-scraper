# IPowerPolicyCallbackWakeFromS0::OnDisarmWakeFromS0

## Description

[**Warning:** UMDF 2 is the latest version of UMDF and supersedes UMDF 1. All new UMDF drivers should be written using UMDF 2. No new features are being added to UMDF 1 and there is limited support for UMDF 1 on newer versions of Windows 10. Universal Windows drivers must use UMDF 2. For more info, see [Getting Started with UMDF](https://learn.microsoft.com/windows-hardware/drivers/wdf/getting-started-with-umdf-version-2).]

A driver's **OnDisarmWakeFromS0** event callback function disarms (that is, disables) a device's ability to trigger a wake signal while in a low-power device state, if the system remains in the [system working state](https://learn.microsoft.com/windows-hardware/drivers/kernel/system-working-state-s0) (S0).

## Parameters

### `pWdfDevice` [in]

A pointer to the [IWDFDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nn-wudfddi-iwdfdevice) interface of the device object that represents one of the driver's devices.

## Remarks

Your driver must provide an **OnDisarmWakeFromS0** callback function if the driver supports the [IPowerPolicyCallbackWakeFromS0](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nn-wudfddi-ipowerpolicycallbackwakefroms0) interface.

If the driver provides an **OnDisarmWakeFromS0** callback function, the framework calls it after the bus driver determines that an event has awakened the device, and after the bus driver subsequently completes the [wait/wake IRP](https://learn.microsoft.com/windows-hardware/drivers/kernel/sending-a-wait-wake-irp). Before calling the driver's **OnDisarmWakeFromS0** callback function, the framework calls the driver's [IPnpCallback::OnD0Entry](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-ipnpcallback-ond0entry) and [IPowerPolicyCallbackWakeFromS0::OnWakeFromS0Triggered](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-ipowerpolicycallbackwakefroms0-onwakefroms0triggered) callback functions.

The **OnDisarmWakeFromS0** callback function must perform any hardware operations that are needed to disable the device's ability to trigger a wake signal after the power is lowered.

For more information about when the framework calls this callback function, see [PnP and Power Management Scenarios in UMDF](https://learn.microsoft.com/windows-hardware/drivers/wdf/pnp-and-power-management-scenarios-in-umdf).

For more information about this callback function, see [Supporting Idle Power-Down in UMDF-based Drivers](https://learn.microsoft.com/windows-hardware/drivers/wdf/supporting-idle-power-down-in-umdf-drivers).

## See also

[IPowerPolicyCallbackWakeFromS0](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nn-wudfddi-ipowerpolicycallbackwakefroms0)

[IPowerPolicyCallbackWakeFromS0::OnArmWakeFromS0](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-ipowerpolicycallbackwakefroms0-onarmwakefroms0)

[IPowerPolicyCallbackWakeFromS0::OnWakeFromS0Triggered](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-ipowerpolicycallbackwakefroms0-onwakefroms0triggered)