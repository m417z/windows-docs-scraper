# DeleteNtmsMediaPool function

## Description

[[Removable Storage Manager](https://learn.microsoft.com/previous-versions/windows/desktop/bb540725(v=vs.85)) is no longer available as of Windows 7 and Windows Server 2008 R2.]

The
**DeleteNtmsMediaPool** function deletes the specified application media pool.

## Parameters

### `hSession` [in]

Handle to the session returned by the
[OpenNtmsSession](https://learn.microsoft.com/windows/desktop/api/ntmsapi/nf-ntmsapi-openntmssessiona) function.

### `lpPoolId` [in]

Unique identifier of the media pool.

## Return value

This function returns one of the following values.

| Value | Meaning |
| --- | --- |
| **ERROR_ACCESS_DENIED** | NTMS_MODIFY_ACCESS to the media pool is denied. Other security errors are also possible, but they indicate a security subsystem error.<br><br>**Windows XP:** NTMS_CONTROL_ACCESS to the media pool is denied. Other security errors are also possible, but they indicate a security subsystem error. |
| **ERROR_DATABASE_FAILURE** | The database is inaccessible or damaged. |
| **ERROR_INVALID_HANDLE** | The session handle is missing or is not valid. |
| **ERROR_INVALID_MEDIA_POOL** | Unable to open existing media pool, or attempting to delete free, import, or unrecognized media pools. |
| **ERROR_INVALID_PARAMETER** | The media pool ID is missing. |
| **ERROR_NOT_EMPTY** | The media pool must be empty to be deleted. |
| **ERROR_NOT_ENOUGH_MEMORY** | An allocation failure occurred during processing. |
| **ERROR_SUCCESS** | The function was successful. |

## Remarks

Only empty media pools can be deleted with the
**DeleteNtmsMediaPool** function.

Free, unrecognized, and import media pools are managed by RSM and cannot be deleted with
**DeleteNtmsMediaPool**.

## See also

[CreateNtmsMediaPool](https://learn.microsoft.com/windows/desktop/api/ntmsapi/nf-ntmsapi-createntmsmediapool)

[Media Services Functions](https://learn.microsoft.com/previous-versions/windows/desktop/rsm/removable-storage-manager-functions)

[MoveToNtmsMediaPool](https://learn.microsoft.com/windows/desktop/api/ntmsapi/nf-ntmsapi-movetontmsmediapool)