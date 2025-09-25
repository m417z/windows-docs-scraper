# WaitForNtmsNotification function

## Description

[[Removable Storage Manager](https://learn.microsoft.com/previous-versions/windows/desktop/bb540725(v=vs.85)) is no longer available as of Windows 7 and Windows Server 2008 R2.]

The
**WaitForNtmsNotification** function waits for the next object change notification.

## Parameters

### `hNotification` [in]

Notification handle returned by the
[OpenNtmsNotification](https://learn.microsoft.com/windows/desktop/api/ntmsapi/nf-ntmsapi-openntmsnotification) function.

### `lpNotificationInformation` [out]

Pointer to an
[NTMS_NOTIFICATIONINFORMATION](https://learn.microsoft.com/windows/desktop/api/ntmsapi/ns-ntmsapi-ntms_notificationinformation) structure that receives the notification information.

### `dwTimeout` [in]

Maximum number of milliseconds to wait. If you specify a value of INFINITE, this function will not time-out.

## Return value

This function returns one of the following values.

| Value | Meaning |
| --- | --- |
| **ERROR_DATABASE_FAILURE** | The database query or update failed. |
| **ERROR_INVALID_HANDLE** | The value specified in the *hNotification* parameter is **NULL** or is not valid. |
| **ERROR_NO_DATA** | Notification pipe failed. Attempt to set up notification again. |
| **ERROR_NOT_CONNECTED** | Unable to connect to the RSM service. |
| **ERROR_TIMEOUT** | The time-out event expired. |
| **ERROR_SUCCESS** | The function was successfully executed. |

## See also

[CloseNtmsNotification](https://learn.microsoft.com/windows/desktop/api/ntmsapi/nf-ntmsapi-closentmsnotification)

[Database Notification Functions](https://learn.microsoft.com/previous-versions/windows/desktop/rsm/removable-storage-manager-functions)

[NTMS_NOTIFICATIONINFORMATION](https://learn.microsoft.com/windows/desktop/api/ntmsapi/ns-ntmsapi-ntms_notificationinformation)

[OpenNtmsNotification](https://learn.microsoft.com/windows/desktop/api/ntmsapi/nf-ntmsapi-openntmsnotification)