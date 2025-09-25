# PowerSettingUnregisterNotification function

## Description

Cancels a registration to receive notification when a power setting changes.

## Parameters

### `RegistrationHandle` [in, out]

A handle to a registration obtained by calling the [PowerSettingRegisterNotification](https://learn.microsoft.com/windows/desktop/api/powersetting/nf-powersetting-powersettingregisternotification) function.

## Return value

Returns ERROR_SUCCESS (zero) if the call was successful, and a nonzero value if the call failed.

## See also

[PowerSettingRegisterNotification](https://learn.microsoft.com/windows/desktop/api/powersetting/nf-powersetting-powersettingregisternotification)