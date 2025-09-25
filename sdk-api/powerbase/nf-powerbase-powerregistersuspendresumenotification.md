# PowerRegisterSuspendResumeNotification function

## Description

Registers to receive notification when the system is suspended or resumed.

## Parameters

### `Flags` [in]

 This parameter must be **DEVICE_NOTIFY_CALLBACK**.

### `Recipient` [in]

This parameter is a pointer to a [DEVICE_NOTIFY_SUBSCRIBE_PARAMETERS](https://learn.microsoft.com/windows/win32/api/powrprof/ns-powrprof-device_notify_subscribe_parameters) structure. In this case, the callback function is [DeviceNotifyCallbackRoutine](https://learn.microsoft.com/windows/desktop/api/powrprof/nc-powrprof-device_notify_callback_routine). When the **Callback** function executes, the *Type* parameter is set indicating the type of event that occurred. Possible values include **PBT_APMSUSPEND**, **PBT_APMRESUMESUSPEND**, and **PBT_APMRESUMEAUTOMATIC** - see [Power Management Events](https://learn.microsoft.com/windows/desktop/Power/power-management-events) for more info. The *Setting* parameter is not used with suspend/resume notifications.

### `RegistrationHandle` [out]

A handle to the registration. Use this handle to unregister for notifications.

## Return value

Returns ERROR_SUCCESS (zero) if the call was successful, and a nonzero value if the call failed.

## See also

[DEVICE_NOTIFY_CALLBACK_ROUTINE](https://learn.microsoft.com/windows/desktop/api/powrprof/nc-powrprof-device_notify_callback_routine)

[DEVICE_NOTIFY_SUBSCRIBE_PARAMETERS](https://learn.microsoft.com/windows/win32/api/powrprof/ns-powrprof-device_notify_subscribe_parameters)

[PowerUnregisterSuspendResumeNotification](https://learn.microsoft.com/windows/desktop/api/powerbase/nf-powerbase-powerunregistersuspendresumenotification)