# PowerUnregisterFromEffectivePowerModeNotifications function

## Description

Unregisters from effective power mode change notifications. This function is intended to be called from cleanup code and will wait for all callbacks to complete before unregistering.

## Parameters

### `RegistrationHandle`

The handle corresponding to a single power mode registration. This handle should have been saved by the caller after the call to [PowerRegisterForEffectivePowerModeNotifications](https://learn.microsoft.com/windows/win32/api/powersetting/nf-powersetting-powerregisterforeffectivepowermodenotifications) and passed in here.

## Return value

Returns S_OK (zero) if the call was successful, and a nonzero value if the call failed.

## Remarks

Immediately after registration, the callback will be invoked with the current value of the power setting. If the registration occurs while the power setting is changing, you may receive multiple callbacks; the last callback is the most recent update.

## See also

[PowerRegisterForEffectivePowerModeNotifications](https://learn.microsoft.com/windows/win32/api/powersetting/nf-powersetting-powerregisterforeffectivepowermodenotifications)