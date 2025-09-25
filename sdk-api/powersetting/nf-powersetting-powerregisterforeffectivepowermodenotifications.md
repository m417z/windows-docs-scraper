# PowerRegisterForEffectivePowerModeNotifications function

## Description

Registers a callback to receive effective power mode change notifications.

## Parameters

### `Version`

Supplies the maximum effective power mode version the caller understands. If the effective power mode comes from a later version, it is reduced to a compatible version that is then passed to the callback.

The following values can be passed in:
- EFFECTIVE_POWER_MODE_V1 is available starting with Windows 10, version 1809 and tracks the performance power slider and battery saver states.
- EFFECTIVE_POWER_MODE_V2 is available starting with Windows 10, version 1903 and tracks the performance power slider, battery saver, game mode and windows mixed reality power states.

### `Callback`

A pointer to the callback to call when the effective power mode changes. This will also be called once upon registration to supply the current mode. If multiple callbacks are registered using this API, those callbacks can be called concurrently.

### `Context`

Caller-specified opaque context.

### `RegistrationHandle`

A handle to the registration. Use this handle to unregister for notifications.

## Return value

Returns S_OK (zero) if the call was successful, and a nonzero value if the call failed.

## Remarks

Immediately after registration, the callback will be invoked with the current value of the power setting. If the registration occurs while the power mode is changing, you may receive multiple callbacks; the last callback is the most recent update.