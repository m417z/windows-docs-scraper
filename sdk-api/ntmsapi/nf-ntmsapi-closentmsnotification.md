# CloseNtmsNotification function

## Description

[[Removable Storage Manager](https://learn.microsoft.com/previous-versions/windows/desktop/bb540725(v=vs.85)) is no longer available as of Windows 7 and Windows Server 2008 R2.]

The
**CloseNtmsNotification** function closes the specified open notification channel.

## Parameters

### `hNotification` [in]

Notification handle returned by the
[OpenNtmsNotification](https://learn.microsoft.com/windows/desktop/api/ntmsapi/nf-ntmsapi-openntmsnotification) function.

## Return value

This function returns one of the following values.

| Value | Meaning |
| --- | --- |
| **ERROR_DATABASE_FAILURE** | The database query or update failed. |
| **ERROR_INVALID_HANDLE** | The value specified in the *hNotification* parameter is not valid. |
| **ERROR_INVALID_PARAMETER** | The *hNotification* parameter is **NULL**. |
| **ERROR_NOT_CONNECTED** | Unable to connect to the RSM service. |
| **ERROR_SUCCESS** | The function was successful. |

## Remarks

If the
**CloseNtmsNotification** function is called while there is an outstanding call to the
[WaitForNtmsNotification](https://learn.microsoft.com/windows/desktop/api/ntmsapi/nf-ntmsapi-waitforntmsnotification) function, an error returns.

## See also

[Database Notification Functions](https://learn.microsoft.com/previous-versions/windows/desktop/rsm/removable-storage-manager-functions)

[OpenNtmsNotification](https://learn.microsoft.com/windows/desktop/api/ntmsapi/nf-ntmsapi-openntmsnotification)

[WaitForNtmsNotification](https://learn.microsoft.com/windows/desktop/api/ntmsapi/nf-ntmsapi-waitforntmsnotification)