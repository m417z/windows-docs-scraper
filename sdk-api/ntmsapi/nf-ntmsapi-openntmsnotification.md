# OpenNtmsNotification function

## Description

[[Removable Storage Manager](https://learn.microsoft.com/previous-versions/windows/desktop/bb540725(v=vs.85)) is no longer available as of Windows 7 and Windows Server 2008 R2.]

The
**OpenNtmsNotification** function opens a channel to receive RSM object change notifications for objects of the specified type.

## Parameters

### `hSession` [in]

Handle to the session returned by the
[OpenNtmsSession](https://learn.microsoft.com/windows/desktop/api/ntmsapi/nf-ntmsapi-openntmssessiona) function.

### `dwType` [in]

RSM object type for notification. For a list of values, see
[NtmsObjectsTypes](https://learn.microsoft.com/windows/desktop/api/ntmsapi/ne-ntmsapi-ntmsobjectstypes).

## Return value

The
**OpenNtmsNotification** function returns a notification handle that you pass to the
[WaitForNtmsNotification](https://learn.microsoft.com/windows/desktop/api/ntmsapi/nf-ntmsapi-waitforntmsnotification) or
[CloseNtmsNotification](https://learn.microsoft.com/windows/desktop/api/ntmsapi/nf-ntmsapi-closentmsnotification) functions.

For extended error information, call the
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) function. This function can return one of the following values.

| Value | Meaning |
| --- | --- |
| **ERROR_ACCESS_DENIED** | NTMS_USE_ACCESS to the computer is denied. Other security errors are also possible, but they would indicate a security subsystem error.<br><br>**Windows XP:** No access rights are required. |
| **ERROR_DATABASE_FAILURE** | The database query or update failed. |
| **ERROR_INVALID_HANDLE** | The value specified in the *hSession* parameter is **NULL** or is not valid. |
| **ERROR_NOT_CONNECTED** | Unable to connect to the RSM service. |
| **ERROR_SUCCESS** | The function was successful. |
| **INVALID_HANDLE_VALUE** | The function failed. |

## See also

[CloseNtmsNotification](https://learn.microsoft.com/windows/desktop/api/ntmsapi/nf-ntmsapi-closentmsnotification)

[Database Notification Functions](https://learn.microsoft.com/previous-versions/windows/desktop/rsm/removable-storage-manager-functions)

[WaitForNtmsNotification](https://learn.microsoft.com/windows/desktop/api/ntmsapi/nf-ntmsapi-waitforntmsnotification)