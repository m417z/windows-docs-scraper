# SERVICE_NOTIFY_2W structure

## Description

Represents service status notification information. It is used by the [NotifyServiceStatusChange](https://learn.microsoft.com/windows/desktop/api/winsvc/nf-winsvc-notifyservicestatuschangea) function.

## Members

### `dwVersion`

The structure version. This member must be **SERVICE_NOTIFY_STATUS_CHANGE** (2).

### `pfnNotifyCallback`

A pointer to the callback function. For more information, see Remarks.

### `pContext`

Any user-defined data to be passed to the callback function.

### `dwNotificationStatus`

A value that indicates the notification status. If this member is **ERROR_SUCCESS**, the notification has succeeded and the **ServiceStatus** member contains valid information. If this member is **ERROR_SERVICE_MARKED_FOR_DELETE**, the service has been marked for deletion and the service handle used by [NotifyServiceStatusChange](https://learn.microsoft.com/windows/desktop/api/winsvc/nf-winsvc-notifyservicestatuschangea) must be closed.

### `ServiceStatus`

A [SERVICE_STATUS_PROCESS](https://learn.microsoft.com/windows/desktop/api/winsvc/ns-winsvc-service_status_process) structure that contains the service status information. This member is only valid if **dwNotificationStatus** is **ERROR_SUCCESS**.

### `dwNotificationTriggered`

If **dwNotificationStatus** is **ERROR_SUCCESS**, this member contains a bitmask of the notifications that triggered this call to the callback function.

### `pszServiceNames`

If **dwNotificationStatus** is **ERROR_SUCCESS** and the notification is **SERVICE_NOTIFY_CREATED** or **SERVICE_NOTIFY_DELETED**, this member is valid and it is a **MULTI_SZ** string that contains one or more service names. The names of the created services will have a '/' prefix so you can distinguish them from the names of the deleted services.

If this member is valid, the notification callback function must free the string using the [LocalFree](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-localfree) function.

## Remarks

The callback function is declared as follows:

``` syntax
typedef VOID( CALLBACK * PFN_SC_NOTIFY_CALLBACK ) (
    IN PVOID pParameter
);
```

The callback function receives a pointer to the **SERVICE_NOTIFY** structure provided by the caller.

> [!NOTE]
> The winsvc.h header defines SERVICE_NOTIFY_2 as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[NotifyServiceStatusChange](https://learn.microsoft.com/windows/desktop/api/winsvc/nf-winsvc-notifyservicestatuschangea)

[SERVICE_STATUS_PROCESS](https://learn.microsoft.com/windows/desktop/api/winsvc/ns-winsvc-service_status_process)