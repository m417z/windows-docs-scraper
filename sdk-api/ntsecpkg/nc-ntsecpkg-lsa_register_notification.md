# LSA_REGISTER_NOTIFICATION callback function

## Description

Provides a mechanism whereby the [security package](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) is notified. Notification can occur at fixed intervals, when an event object is signaled, or during certain system events.

## Parameters

### `StartFunction` [in]

The function that is called to accept notification.

### `Parameter` [in]

The argument of the function specified in the *StartFunction* parameter.

### `NotificationType` [in]

Specifies the type of notification. The following table lists the valid values.

| Value | Meaning |
| --- | --- |
| **NOTIFIER_TYPE_INTERVAL** | Notify at fixed intervals. Use the *IntervalMinutes* parameter to indicate the interval length. |
| **NOTIFIER_TYPE_HANDLE_WAIT** | Notify when the event handle specified by the *WaitEvent* parameter is signaled. |
| **NOTIFIER_TYPE_STATE_CHANGE** | Notify when there is a change in the machine's domain or installation type. |
| **NOTIFIER_TYPE_NOTIFY_EVENT** | Notify when a security event takes place. Use the *NotificationClass* parameter to specify the event of interest. |
| **NOTIFIER_TYPE_IMMEDIATE** | Notify immediately. This value implies NOTIFIER_FLAG_ONE_SHOT. |

### `NotificationClass` [in]

Specifies the class of events that generate notifications. Specify zero unless the *NotificationType* parameter is set to NOTIFIER_TYPE_NOTIFY_EVENT.

| Value | Meaning |
| --- | --- |
| **NOTIFY_CLASS_PACKAGE_CHANGE** | A package was loaded, or a new package was selected as the preferred package. For more information, see Remarks. |
| **NOTIFY_CLASS_ROLE_CHANGE** | Reserved for internal use. |
| **NOTIFY_CLASS_DOMAIN_CHANGE** | Reserved for internal use. |

### `NotificationFlags` [in]

Specifies flags that control notification behavior.

| Value | Meaning |
| --- | --- |
| **NOTIFIER_FLAG_NEW_THREAD** | Wait for notification using a new thread. |
| **NOTIFIER_FLAG_ONE_SHOT** | Notify only once. |
| **NOTIFIER_FLAG_SECONDS** | The *IntervalMinutes* parameter specifies seconds. |

### `IntervalMinutes` [in]

Specifies the time delay between notifications.

### `WaitEvent` [in]

Optional. Handle to an event object. When the object is signaled, the notification occurs. This value is used in conjunction with the *NotificationType* value NOTIFIER_TYPE_HANDLE_WAIT.

## Return value

If the function succeeds, the return value is a handle to the notification.

If the function fails, the return value is **NULL**.

## Remarks

If you specify the NOTIFY_CLASS_PACKAGE_CHANGE value for the *NotificationClass* parameter, the following values represent valid changes.

| Value | Description |
| --- | --- |
| SECPKG_PACKAGE_CHANGE_LOAD | A package was loaded. |
| SECPKG_PACKAGE_CHANGE_UNLOAD | A package was unloaded. |
| SECPKG_PACKAGE_CHANGE_SELECT | A new package became the preferred [security package](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly). |

A pointer to the **RegisterNotification** function is available in the
[LSA_SECPKG_FUNCTION_TABLE](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/ns-ntsecpkg-lsa_secpkg_function_table) structure received by the
[SpInitialize](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/nc-ntsecpkg-spinitializefn) function.

## See also

[LSA_SECPKG_FUNCTION_TABLE](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/ns-ntsecpkg-lsa_secpkg_function_table)

[SpInitialize](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/nc-ntsecpkg-spinitializefn)