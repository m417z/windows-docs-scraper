# RegisterSuspendResumeNotification function

## Description

Registers to receive notification when the system is suspended or resumed. Similar to [PowerRegisterSuspendResumeNotification](https://learn.microsoft.com/windows/desktop/api/powerbase/nf-powerbase-powerregistersuspendresumenotification), but operates in user mode and can take a window handle.

## Parameters

### `hRecipient` [in]

 This parameter contains parameters for subscribing to a power notification or a window handle representing the subscribing process.

If *Flags* is **DEVICE_NOTIFY_CALLBACK**, *hRecipient* is interpreted as a pointer to a [DEVICE_NOTIFY_SUBSCRIBE_PARAMETERS](https://learn.microsoft.com/windows/win32/api/powrprof/ns-powrprof-device_notify_subscribe_parameters) structure. In this case, the callback function is [DeviceNotifyCallbackRoutine](https://learn.microsoft.com/windows/desktop/api/powrprof/nc-powrprof-device_notify_callback_routine). When the **Callback** function executes, the *Type* parameter is set indicating the type of event that occurred. Possible values include **PBT_APMSUSPEND**, **PBT_APMRESUMESUSPEND**, and **PBT_APMRESUMEAUTOMATIC** - see [Power Management Events](https://learn.microsoft.com/windows/desktop/Power/power-management-events) for more info. The *Setting* parameter is not used with suspend/resume notifications.

If *Flags* is **DEVICE_NOTIFY_WINDOW_HANDLE**, *hRecipient* is a handle to the window to deliver events to.

### `Flags` [in]

 This parameter can be **DEVICE_NOTIFY_WINDOW_HANDLE** or **DEVICE_NOTIFY_CALLBACK**.

## Return value

A handle to the registration. Use this handle to unregister for notifications.

If the function fails, the return value is NULL. To get extended error information call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## See also

[DEVICE_NOTIFY_CALLBACK_ROUTINE](https://learn.microsoft.com/windows/desktop/api/powrprof/nc-powrprof-device_notify_callback_routine)

[DEVICE_NOTIFY_SUBSCRIBE_PARAMETERS](https://learn.microsoft.com/windows/win32/api/powrprof/ns-powrprof-device_notify_subscribe_parameters)

[UnregisterSuspendResumeNotification](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-unregistersuspendresumenotification)