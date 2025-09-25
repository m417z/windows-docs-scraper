# PoFxReportDevicePoweredOn function

## Description

The **PoFxReportDevicePoweredOn** routine notifies the power management framework (PoFx) that the device completed the requested transition to the D0 (fully on) power state.

## Parameters

### `Handle` [in]

A handle that represents the registration of the device with the power management framework (PoFx). The device driver previously received this handle from the [PoFxRegisterDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-pofxregisterdevice) routine.

## Remarks

The driver for a registered device must call **PoFxReportDevicePoweredOn** after any of the following occurrences:

* PoFx calls the driver's [DevicePowerRequiredCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-po_fx_device_power_required_callback) callback routine to notify the driver that the device must enter the D0 power state.
* PoFx calls the driver's [DirectedPowerUpCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-po_fx_directed_power_up_callback) callback routine to notify the driver that the device must enter the D0 power state.
* PoFx sends the driver an S0 IRP (an [IRP_MN_SET_POWER](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mn-set-power) request) to notify the driver of a pending system transition to the S0 power state.

In response to either occurrence, the driver sends D0 IRP (an **IRP_MN_SET_POWER** request) down its device stack to initiate a transition to the D0 power state, if the device is not already in the D0 state. After the driver completes (and all lower drivers complete) the transition to the D0 state, the driver calls **PoFxReportDevicePoweredOn** to notify PoFx.

The driver must call **PoFxReportDevicePoweredOn** regardless of whether no D0 IRP is required, the D0 IRP request fails, the dispatched D0 IRP succeeds or fails, or the S0 IRP succeeds or fails.

For power required / directed power up callback, the **PoFxReportDevicePoweredOn** call can occur either during or after the callback call.

For an S0 IRP request, the driver must complete this request as soon as possible, switch the device to the D0 power state, and call **PoFxReportDevicePoweredOn**. For more information, see [Handling a System Set-Power IRP in a Device Power Policy Owner](https://learn.microsoft.com/windows-hardware/drivers/kernel/handling-a-system-set-power-irp-in-a-device-power-policy-owner).

On entry to **PoFxReportDevicePoweredOn**, the device might be in an uninitialized D0 power state in which all of the components in the device are turned on. In response to the **PoFxReportDevicePoweredOn** call, PoFx configures the device in an initialized D0 state. During this configuration, PoFx switches as many components as it can to low-power Fx power states.

## See also

[DevicePowerRequiredCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-po_fx_device_power_required_callback)

[IRP_MN_SET_POWER](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mn-set-power)

[PoFxRegisterDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-pofxregisterdevice)