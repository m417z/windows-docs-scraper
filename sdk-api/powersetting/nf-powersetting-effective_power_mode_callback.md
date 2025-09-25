# EFFECTIVE_POWER_MODE_CALLBACK function

## Description

Function class for effective power mode callback.

## Parameters

### `Mode`

Indicates the effective power mode the system is running in

### `Context`

User-specified opaque context. This context would have been passed in at registration in PowerRegisterForEffectivePowerModeNotifications.

## Remarks

Immediately after registration, this callback will be invoked with the current value of the power setting. If the registration occurs while the power setting is changing, you may receive multiple callbacks; the last callback is the most recent update.

## See also

[EFFECTIVE_POWER_MODE](https://learn.microsoft.com/windows/win32/api/powersetting/ne-powersetting-effective_power_mode)

[PowerRegisterForEffectivePowerModeNotifications](https://learn.microsoft.com/windows/win32/api/powersetting/nf-powersetting-powerregisterforeffectivepowermodenotifications)

[PowerUnregisterFromEffectivePowerModeNotifications](https://learn.microsoft.com/windows/win32/api/powersetting/nf-powersetting-powerunregisterfromeffectivepowermodenotifications)