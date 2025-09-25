# IPowerPolicyCallbackWakeFromS0::OnArmWakeFromS0

## Description

[**Warning:** UMDF 2 is the latest version of UMDF and supersedes UMDF 1. All new UMDF drivers should be written using UMDF 2. No new features are being added to UMDF 1 and there is limited support for UMDF 1 on newer versions of Windows 10. Universal Windows drivers must use UMDF 2. For more info, see [Getting Started with UMDF](https://learn.microsoft.com/windows-hardware/drivers/wdf/getting-started-with-umdf-version-2).]

A driver's **OnArmWakeFromS0** callback function arms (that is, enables) a device so that it can trigger a wake signal while in a low-power device state, if the system remains in the [system working state](https://learn.microsoft.com/windows-hardware/drivers/kernel/system-working-state-s0) (S0).

## Parameters

### `pWdfDevice` [in]

A pointer to the **IWDFDevice** interface of the device object that represents one of the driver's devices.

## Return value

If the operation is successful, the **OnArmWakeFromS0** callback function must return S_OK or another status value for which SUCCEEDED(*status*) equals **TRUE**. Otherwise it must return a status value for which SUCCEEDED(*status*) equals **FALSE**.

If SUCCEEDED(status) equals **FALSE**, the framework calls the driver's [IPowerPolicyCallbackWakeFromS0::OnDisarmWakeFromS0](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-ipowerpolicycallbackwakefroms0-ondisarmwakefroms0) callback function. (The framework does not report a device failure to the PnP manager.)

## Remarks

Your driver must provide an **OnArmWakeFromS0** callback function if the driver supports the [IPowerPolicyCallbackWakeFromS0](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nn-wudfddi-ipowerpolicycallbackwakefroms0) interface.

The **OnArmWakeFromS0** callback function handles device-specific operations that are needed to enable the device to detect an external event that triggers a wake signal on the bus. The kernel-mode bus driver handles bus-specific operations, such as enabling the PCI bus's Power Management Event (PME) signal.

If the driver has registered an **OnArmWakeFromS0** callback function, the framework calls it while the device is still in the D0 device power state, before the bus driver lowers the device's power state but after the framework has sent a [wait/wake IRP](https://learn.microsoft.com/windows-hardware/drivers/kernel/sending-a-wait-wake-irp) on behalf of the driver.

The process occurs in the following sequence:

1. The framework determines that the device has been idle for a preset amount of time.
2. The framework calls the driver's **OnArmWakeFromS0** callback function.
3. The framework requests the driver for the device's bus to lower the device's power.

Immediately before your device enters a low power state, the framework will call your driver's [IPnpCallback::OnD0Exit](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-ipnpcallback-ond0exit) callback function.

For more information about when the framework calls this callback function, see [PnP and Power Management Scenarios in UMDF](https://learn.microsoft.com/windows-hardware/drivers/wdf/pnp-and-power-management-scenarios-in-umdf).

You do not need to provide an **OnArmWakeFromS0** callback function if your device:

* Is a USB device that supports "selective suspend."
* Cannot be powered down while the system remains fully powered.
* Does not require special hardware operations that enable the device to trigger a wake signal.

If your device supports USB "selective suspend" and if your driver specifies **IdleUsbSelectiveSuspend** when it calls [IWDFDevice2::AssignS0IdleSettings](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfdevice2-assigns0idlesettings), the framework sends a "selective suspend" request to the USB bus driver when the device has been idle for a preset amount of time.

For more information about this callback function, see [Supporting Idle Power-Down in UMDF-based Drivers](https://learn.microsoft.com/windows-hardware/drivers/wdf/supporting-idle-power-down-in-umdf-drivers).

## See also

[IPowerPolicyCallbackWakeFromS0](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nn-wudfddi-ipowerpolicycallbackwakefroms0)

[IPowerPolicyCallbackWakeFromS0::OnDisarmWakeFromS0](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-ipowerpolicycallbackwakefroms0-ondisarmwakefroms0)

[IPowerPolicyCallbackWakeFromS0::OnWakeFromS0Triggered](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-ipowerpolicycallbackwakefroms0-onwakefroms0triggered)