# DEVICE_NOTIFY_CALLBACK_ROUTINE callback function

## Description

An application's
*DeviceNotifyCallbackRoutine*
callback function is used for receiving power notifications.

## Parameters

### `Context`

The context provided when registering for the power notification.

### `Type`

The type of power event that caused this notification.

### `Setting`

The value of this parameter depends on the type of notification subscribed to.

## Return value

This function returns a Windows error code.

## See also

[DEVICE_NOTIFY_SUBSCRIBE_PARAMETERS](https://learn.microsoft.com/windows/win32/api/powrprof/ns-powrprof-device_notify_subscribe_parameters)

[PowerRegisterSuspendResumeNotification](https://learn.microsoft.com/windows/desktop/api/powerbase/nf-powerbase-powerregistersuspendresumenotification)