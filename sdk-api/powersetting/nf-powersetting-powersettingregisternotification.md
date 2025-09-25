# PowerSettingRegisterNotification function

## Description

Registers to receive notification when a power setting changes.

## Parameters

### `SettingGuid` [in]

A GUID that represents the power setting.

### `Flags` [in]

Information about the recipient of the notification. This parameter can be one of the following values:

| Value | Meaning |
| --- | --- |
| **DEVICE_NOTIFY_SERVICE_HANDLE** | The *Recipient* parameter is a handle to a service. Use the [CreateService](https://learn.microsoft.com/windows/desktop/api/winsvc/nf-winsvc-createservicea) or [OpenService](https://learn.microsoft.com/windows/desktop/api/winsvc/nf-winsvc-openservicea) function to obtain this handle. |
| **DEVICE_NOTIFY_CALLBACK** | The *Recipient* parameter is a pointer to a callback function to call when the power setting changes. *Recipient* in this case is expected to be of type *PDEVICE_NOTIFY_SUBSCRIBE_PARAMETERS*. |

### `Recipient` [in]

A handle to the recipient of the notifications.

### `RegistrationHandle` [out]

A handle to the registration. Use this handle to unregister for notifications.

## Return value

Returns ERROR_SUCCESS (zero) if the call was successful, and a nonzero value if the call failed.

## Remarks

Immediately after registration, the callback will be invoked with the current value of the power setting. If the registration occurs while the power setting is changing, you may receive multiple callbacks; the last callback is the most recent update.

## See also

[Power Setting GUIDs](https://learn.microsoft.com/windows/desktop/Power/power-setting-guids)

[PowerSettingUnregisterNotification](https://learn.microsoft.com/windows/desktop/api/powersetting/nf-powersetting-powersettingunregisternotification)