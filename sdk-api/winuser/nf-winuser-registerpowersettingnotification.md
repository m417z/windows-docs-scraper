# RegisterPowerSettingNotification function

## Description

Registers the application to receive power setting notifications for the specific power setting event.

## Parameters

### `hRecipient` [in]

Handle indicating where the power setting notifications are to be sent. For interactive applications, the
*Flags* parameter should be zero, and the *hRecipient* parameter
should be a window handle. For services, the *Flags* parameter should be one, and the
*hRecipient* parameter should be a **SERVICE_STATUS_HANDLE**
as returned from
[RegisterServiceCtrlHandlerEx](https://learn.microsoft.com/windows/desktop/api/winsvc/nf-winsvc-registerservicectrlhandlerexa).

### `PowerSettingGuid` [in]

The **GUID** of the power setting for which notifications are to be sent. For more information see [Registering for Power
Events](https://learn.microsoft.com/windows/desktop/Power/registering-for-power-events).

### `Flags` [in]

| Value | Meaning |
| --- | --- |
| **DEVICE_NOTIFY_WINDOW_HANDLE**<br><br>0 | Notifications are sent using [WM_POWERBROADCAST](https://learn.microsoft.com/windows/desktop/Power/wm-powerbroadcast) messages with a *wParam* parameter of [PBT_POWERSETTINGCHANGE](https://learn.microsoft.com/windows/desktop/Power/pbt-powersettingchange). |
| **DEVICE_NOTIFY_SERVICE_HANDLE**<br><br>1 | Notifications are sent to the [HandlerEx](https://learn.microsoft.com/windows/desktop/api/winsvc/nc-winsvc-lphandler_function_ex) callback function with a *dwControl* parameter of **SERVICE_CONTROL_POWEREVENT** and a *dwEventType* of [PBT_POWERSETTINGCHANGE](https://learn.microsoft.com/windows/desktop/Power/pbt-powersettingchange). |

## Return value

Returns a notification handle for unregistering for power notifications. If the function fails, the return value is NULL. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## See also

[Power Management Functions](https://learn.microsoft.com/windows/desktop/Power/power-management-functions)

[Registering for Power Events](https://learn.microsoft.com/windows/desktop/Power/registering-for-power-events)

[UnregisterPowerSettingNotification](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-unregisterpowersettingnotification)