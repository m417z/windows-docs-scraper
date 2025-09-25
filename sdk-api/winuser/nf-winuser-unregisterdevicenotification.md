# UnregisterDeviceNotification function

## Description

Closes the specified device notification handle.

## Parameters

### `Handle` [in]

Device notification handle returned by the
[RegisterDeviceNotification](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-registerdevicenotificationa) function.

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## See also

[Device Management Functions](https://learn.microsoft.com/windows/desktop/DevIO/device-management-functions)

[Device Notifications](https://learn.microsoft.com/windows/desktop/DevIO/device-notifications)

[RegisterDeviceNotification](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-registerdevicenotificationa)

[WM_DEVICECHANGE](https://learn.microsoft.com/windows/desktop/DevIO/wm-devicechange)