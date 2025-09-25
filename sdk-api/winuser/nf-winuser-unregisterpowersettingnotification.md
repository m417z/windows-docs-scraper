# UnregisterPowerSettingNotification function

## Description

Unregisters the power setting notification.

## Parameters

### `Handle` [in]

The handle returned from the [RegisterPowerSettingNotification](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-registerpowersettingnotification) function.

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## See also

[Power Management Functions](https://learn.microsoft.com/windows/desktop/Power/power-management-functions)

[RegisterPowerSettingNotification](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-registerpowersettingnotification)