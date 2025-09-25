# SetNtmsMediaComplete function

## Description

[[Removable Storage Manager](https://learn.microsoft.com/previous-versions/windows/desktop/bb540725(v=vs.85)) is no longer available as of Windows 7 and Windows Server 2008 R2.]

The
**SetNtmsMediaComplete** function marks a piece of logical media as complete.

## Parameters

### `hSession` [in]

Handle to the session returned by the
[OpenNtmsSession](https://learn.microsoft.com/windows/desktop/api/ntmsapi/nf-ntmsapi-openntmssessiona) function.

### `lpMediaId` [in]

Unique identifier of a piece of logical media.

## Return value

This function returns one of the following values.

| Value | Meaning |
| --- | --- |
| **ERROR_ACCESS_DENIED** | NTMS_CONTROL_ACCESS to the media's media pool is denied. Other security errors are also possible, but they would indicate a security subsystem error. <br><br>**Windows XP:** NTMS_MODIFY_ACCESS to the media's media pool is denied. Other security errors are also possible, but they would indicate a security subsystem error. |
| **ERROR_DATABASE_FAILURE** | The database is inaccessible or damaged. |
| **ERROR_DATABASE_FULL** | The database is full. |
| **ERROR_INVALID_HANDLE** | The session handle is missing or is not valid. |
| **ERROR_INVALID_MEDIA** | The media identifier is not valid. |
| **ERROR_INVALID_MEDIA_POOL** | The media pool for the media is not valid. |
| **ERROR_INVALID_PARAMETER** | The media identifier is missing. |
| **ERROR_INVALID_STATE** | The media is not in the allocated state or is currently mounted. |
| **ERROR_NOT_ENOUGH_MEMORY** | An allocation failure occurred during processing. |
| **ERROR_SUCCESS** | The function was successful. |

## Remarks

The
**SetNtmsMediaComplete** function marks the specified medium as Complete. An application marks the medium as Complete when the application is no longer going to write to the medium. Complete media cannot be mounted with the NTMS_MOUNT_WRITE flag.

The
**SetNtmsMediaComplete** function is typically used when an application reaches the end of media. Media that is mounted or in use cannot be marked as complete.

## See also

[Media Services Functions](https://learn.microsoft.com/previous-versions/windows/desktop/rsm/removable-storage-manager-functions)

[MountNtmsMedia](https://learn.microsoft.com/windows/desktop/api/ntmsapi/nf-ntmsapi-mountntmsmedia)