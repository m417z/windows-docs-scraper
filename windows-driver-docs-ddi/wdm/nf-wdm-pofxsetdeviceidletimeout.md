# PoFxSetDeviceIdleTimeout function

## Description

The **PoFxSetDeviceIdleTimeout** routine specifies the minimum time interval from when the last component of the device enters the idle condition to when the power management framework (PoFx) calls the driver's [DevicePowerNotRequiredCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-po_fx_device_power_not_required_callback) routine.

## Parameters

### `Handle` [in]

A handle that represents the registration of the device with PoFx. The device driver previously received this handle from the [PoFxRegisterDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-pofxregisterdevice) routine.

### `IdleTimeout` [in]

The idle time-out interval in 100-nanosecond units. For more information, see Remarks.

## Remarks

This routine specifies a time-out interval for PoFx to apply to future calls to the driver's [DevicePowerNotRequiredCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-po_fx_device_power_not_required_callback) callback routine. By default, this time-out interval is zero, in which case PoFx might call the *DevicePowerNotRequiredCallback* routine just as soon as the device is ready to switch to a low-power Dx state. However, a driver might prefer to delay this transition and to keep the device in the D0 power state for some additional time-out interval. In this case, if the device becomes active before the end of the time-out interval, and is therefore required to stay in the D0 state, the pending *DevicePowerNotRequiredCallback* call is no longer required and is canceled by PoFx.

For example, to improve performance and reduce wear, a storage device driver might want to prevent a spinning drive from entering D3 and slowing down until the drive has been idle for a sufficiently long time. To simplify this driver's implementation of the *DevicePowerNotRequiredCallback* callback routine, the **PoFxSetDeviceIdleTimeout** routine enables the driver to automatically delay the D3 transition without requiring the driver to set up a timer.

The time-out interval starts when all components of the device complete their transitions to the idle condition. Typically, PoFx waits until the end of the time-out interval to call the *DevicePowerNotRequiredCallback* routine. However, if PoFx is preparing to enter a low-power system state, PoFx might end the time-out interval early. In any case, when PoFx calls the driver's *DevicePowerNotRequiredCallback* routine, the driver should switch to the low-power Dx state without further delay.

The device driver can call **PoFxSetDeviceIdleTimeout** each time a change in conditions requires a change in the idle time-out interval. After each call, the new idle time-out interval remains in effect until the driver calls **PoFxSetDeviceIdleTimeout** again to update it.

## See also

[DevicePowerNotRequiredCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-po_fx_device_power_not_required_callback)

[PoFxRegisterDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-pofxregisterdevice)