# PoFxNotifySurprisePowerOn function

## Description

The **PoFxNotifySurprisePowerOn** routine notifies the power management framework (PoFx) that a device was turned on as a side effect of supplying power to some other device.

## Parameters

### `Pdo` [in]

A pointer to a [physical device object](https://learn.microsoft.com/windows-hardware/drivers/) (PDO). This parameter points to a [DEVICE_OBJECT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_device_object) structure that represents the physical device that was turned on as a side effect. The caller is always the bus driver that enumerated the PDO.

## Remarks

Device drivers should not call this routine. This routine should be called only by bus drivers.

A bus driver calls this routine to inform PoFx that a device that is not currently being used was incidentally turned on at the same time as a second device. For example, the first device might share a power rail with the second device. Thus, power cannot be supplied to the second device without supplying power, as a side effect, to the first device. Because the first device is not being used, this device should be configured to consume as little power as possible.

To request a transition to a D0 power state, a device driver sends an [IRP_MN_SET_POWER](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mn-set-power) request down its device stack. Through the PDO in this stack, the bus driver that is the parent of this device receives the request and responds by supplying power to the device. However, if the bus driver cannot turn on this device without also turning on a second, unused device, the bus driver can call **PoFxNotifySurprisePowerOn** to reduce the power consumed by the unused device.

On entry to **PoFxNotifySurprisePowerOn**, the device represented by the *Pdo* parameter is in an uninitialized D0 power state. In this state, all of the components in the device are typically turned on. In response to the **PoFxNotifySurprisePowerOn** call, PoFx configures the device in an initialized D0 state. During this configuration, PoFx switches as many components as it can to low-power Fx power states. If possible, PoFx configures the device in a "hot D3" state, which is really a D0 state in which all of the individual components in the device are turned off.

**PoFxNotifySurprisePowerOn** can configure only a device that was registered with PoFx when the device was previously turned off. However, unless the bus driver knows that a device is not registered, the bus driver should call **PoFxNotifySurprisePowerOn** when the device is turned on as a side effect.

If the bus driver fails to call this routine when the device is turned on, the device hardware might stay in the fully on state for an indefinite time, during which PoFx assumes that the device remains in the D3 (fully off) power state.

Call **PoFxNotifySurprisePowerOn** only if the device was turned on incidentally, as a side effect of turning on some other device. If the bus driver restores power to a device in response to a [DevicePowerRequiredCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-po_fx_device_power_required_callback) callback or an [IRP_MN_SET_POWER](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mn-set-power) request for a D0 transition, call the [PoFxReportDevicePoweredOn](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-pofxreportdevicepoweredon) routine instead to inform PoFx when power is restored to the device.

## See also

[DEVICE_OBJECT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_device_object)

[DevicePowerRequiredCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-po_fx_device_power_required_callback)

[IRP_MN_SET_POWER](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mn-set-power)

[PoFxReportDevicePoweredOn](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-pofxreportdevicepoweredon)