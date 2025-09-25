## Description

The **PoRegisterForEffectivePowerModeNotifications** function registers a callback to receive effective power mode change notifications.

## Parameters

### `Version`

Supplies the maximum effective power mode version the caller understands. If the effective power mode comes from a later version, it is mapped to a compatible version that is then passed to the callback.

The following values can be passed in:

- EFFECTIVE_POWER_MODE_V1 is available starting with Windows 10, version 1809 and tracks the performance power slider and energy saver states.

- EFFECTIVE_POWER_MODE_V2 is available starting with Windows 10, version 1903 and tracks the performance power slider, battery saver, game mode and windows mixed reality power states.

### `Callback`

A pointer to the callback to call when the effective power mode changes. This will also be called once upon registration to supply the current mode. If multiple callbacks are registered, those callbacks can be called concurrently.

### `Context`

Caller-specified opaque context.

### `RegistrationHandle`

This is a pointer to a variable that receives a handle to the registration. This handle can be used to unregister the callback function.

### `DeviceObject`

This is an optional parameter that, if specified, provides a registered callback (such as from a driver) with the specified device context.

## Return value

Returns **S_OK** (zero) if the call was successful, and a nonzero value if the call failed.

## Remarks

Immediately after registration, the callback will be invoked with the current value of the power setting. If the registration occurs while the power mode is changing, you may receive multiple callbacks. The last callback is the most recent update.

## See also

[**PO_EFFECTIVE_POWER_MODE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ne-wdm-po_effective_power_mode)

[PO_EFFECTIVE_POWER_MODE_CALLBACK](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-po_effective_power_mode_callback)

[PoUnregisterFromEffectivePowerModeNotifications](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-pounregisterfromeffectivepowermodenotifications)