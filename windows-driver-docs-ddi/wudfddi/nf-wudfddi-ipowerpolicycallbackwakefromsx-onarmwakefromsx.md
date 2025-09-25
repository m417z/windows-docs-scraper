# IPowerPolicyCallbackWakeFromSx::OnArmWakeFromSx

## Description

[**Warning:** UMDF 2 is the latest version of UMDF and supersedes UMDF 1. All new UMDF drivers should be written using UMDF 2. No new features are being added to UMDF 1 and there is limited support for UMDF 1 on newer versions of Windows 10. Universal Windows drivers must use UMDF 2. For more info, see [Getting Started with UMDF](https://learn.microsoft.com/windows-hardware/drivers/wdf/getting-started-with-umdf-version-2).]

A driver's **OnArmWakeFromSx** event callback function arms (that is, enables) a device so that it can trigger a wake signal while in a low-power device state. The wake signal causes the device to enter its working state (D0) and the system to enter its working state (S0).

## Parameters

### `pWdfDevice` [in]

A pointer to the [IWDFDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nn-wudfddi-iwdfdevice) interface of the device object that represents one of the driver's devices.

## Return value

If the operation is successful, the **OnArmWakeFromSx** callback function must return S_OK or another status value for which SUCCEEDED(*status*) equals **TRUE**. Otherwise it must return a status value for which SUCCEEDED(*status*) equals **FALSE**.

If SUCCEEDED(status) equals **FALSE**, the framework calls the driver's [IPowerPolicyCallbackWakeFromSx::OnDisarmWakeFromSx](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-ipowerpolicycallbackwakefromsx-ondisarmwakefromsx) callback function. (The framework does not report a device failure to the PnP manager.)

## Remarks

Your driver must provide an **OnArmWakeFromSx** callback function if the driver supports the [IPowerPolicyCallbackWakeFromSx](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nn-wudfddi-ipowerpolicycallbackwakefromsx) interface.

This callback function handles device-specific operations that are needed to enable the device to detect an external event that triggers a wake signal on the bus. The kernel-mode bus driver handles bus-specific operations, such as enabling the PCI bus's Power Management Event (PME) signal.

If a driver has registered an **OnArmWakeFromSx** callback function, the framework calls it while the device is still in the D0 device power state, before the bus driver lowers the device's power state but after the framework has sent a [wait/wake IRP](https://learn.microsoft.com/windows-hardware/drivers/kernel/sending-a-wait-wake-irp) on behalf of the driver.

The process occurs in the following sequence:

1. The framework determines that the system is about to enter a low-power system state.
2. The framework calls the driver's **OnArmWakeFromSx** callback function.
3. The framework asks the driver for the device's bus to lower the device's power.

Immediately before a device enters a low-power state, the framework calls the driver's [IPnpCallback::OnD0Exit](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-ipnpcallback-ond0exit) callback function.

For more information about when the framework calls this callback function, see [PnP and Power Management Scenarios in UMDF](https://learn.microsoft.com/windows-hardware/drivers/wdf/pnp-and-power-management-scenarios-in-umdf).

You do not need to provide an **OnArmWakeFromSx** callback function if your device does not require special hardware operations that enable the device to trigger a wake signal.

For more information about this callback function, see [Supporting System Wake-Up in UMDF-based Drivers](https://learn.microsoft.com/windows-hardware/drivers/wdf/supporting-system-wake-up-in-umdf-drivers).

## See also

[IPowerPolicyCallbackWakeFromSx](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nn-wudfddi-ipowerpolicycallbackwakefromsx)

[IPowerPolicyCallbackWakeFromSx::OnDisarmWakeFromSx](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-ipowerpolicycallbackwakefromsx-ondisarmwakefromsx)

[IPowerPolicyCallbackWakeFromSx::OnWakeFromSxTriggered](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-ipowerpolicycallbackwakefromsx-onwakefromsxtriggered)