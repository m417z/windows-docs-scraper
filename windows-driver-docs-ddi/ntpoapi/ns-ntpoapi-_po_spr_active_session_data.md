# _PO_SPR_ACTIVE_SESSION_DATA structure

## Description

Stores information that indicates whether a System Power Report's Active Session is starting or ending.

## Members

### `Start`

A boolean value that indicates whether the session is starting or ending.

### `ActiveSessionGuid`

The Active session GUID for the session.

## Remarks

To register for System Power Report's Active Session notifications, you must call [**PowerSettingRegisterNotification**](https://learn.microsoft.com/windows/win32/api/powersetting/nf-powersetting-powersettingregisternotification) function with these values:

- _SettingGuid_: Pass GUID_SPR_ACTIVE_SESSION_CHANGE.
- _Flags_: Set to DEVICE_NOTIFY_CALLBACK.
- _Recipient_: A [**DEVICE_NOTIFY_SUBSCRIBE_PARAMETERS**](https://learn.microsoft.com/windows/win32/api/powersetting/nf-powersetting-powersettingregisternotification) structure, in which the **Callback** member is set to your implementation of the [DEVICE_NOTIFY_CALLBACK_ROUTINE](https://learn.microsoft.com/windows/win32/api/powrprof/nc-powrprof-device_notify_callback_routine) callback routine that gets called when the session starts or ends.

If the registration is successful, the [DEVICE_NOTIFY_CALLBACK_ROUTINE](https://learn.microsoft.com/windows/win32/api/powrprof/nc-powrprof-device_notify_callback_routine) callback is invoked with these value:

- _Type_: PBT_POWERSETTINGCHANGE to indicate a power setting change.
- _UpdateSetting_: Is a [**POWERBROADCAST_SETTING**](https://learn.microsoft.com/windows/win32/api/winuser/ns-winuser-powerbroadcast_setting) structure; the **PowerSetting** member is set to GUID_SPR_ACTIVE_SESSION_CHANGE, the **DataLength** member is a **_PO_SPR_ACTIVE_SESSION_DATA** structure.

## See also

[**PowerSettingRegisterNotification**](https://learn.microsoft.com/windows/win32/api/powersetting/nf-powersetting-powersettingregisternotification)

[**POWERBROADCAST_SETTING**](https://learn.microsoft.com/windows/win32/api/winuser/ns-winuser-powerbroadcast_setting)

[DEVICE_NOTIFY_CALLBACK_ROUTINE](https://learn.microsoft.com/windows/win32/api/powrprof/nc-powrprof-device_notify_callback_routine)