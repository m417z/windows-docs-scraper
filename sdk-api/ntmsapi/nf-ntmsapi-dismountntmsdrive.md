# DismountNtmsDrive function

## Description

[[Removable Storage Manager](https://learn.microsoft.com/previous-versions/windows/desktop/bb540725(v=vs.85)) is no longer available as of Windows 7 and Windows Server 2008 R2.]

The
**DismountNtmsDrive** function queues a command to move the media in the specified drive to its storage slot. This function should be paired with the
[MountNtmsMedia](https://learn.microsoft.com/windows/desktop/api/ntmsapi/nf-ntmsapi-mountntmsmedia) function.

## Parameters

### `hSession` [in]

Handle to the session returned by the
[OpenNtmsSession](https://learn.microsoft.com/windows/desktop/api/ntmsapi/nf-ntmsapi-openntmssessiona) function.

### `lpDriveId` [in]

Unique identifier of a drive object.

## Return value

This function returns one of the following values.

| Value | Meaning |
| --- | --- |
| **ERROR_ACCESS_DENIED** | NTMS_MODIFY_ACCESS to the library is denied. Other security errors are also possible, but they would indicate a security subsystem error.<br><br>**Windows XP:** NTMS_CONTROL_ACCESS to the library is denied. Other security errors are also possible, but they would indicate a security subsystem error. |
| **ERROR_DATABASE_FAILURE** | The database is inaccessible or damaged. |
| **ERROR_DATABASE_FULL** | The database is full. |
| **ERROR_DEVICE_NOT_AVAILABLE** | The drive or library is not enabled. |
| **ERROR_INVALID_DRIVE** | The drive ID is not valid. |
| **ERROR_INVALID_HANDLE** | The session handle is missing or is not valid. |
| **ERROR_INVALID_LIBRARY** | The library for the drive is not valid. |
| **ERROR_INVALID_PARAMETER** | The drive ID is missing. |
| **ERROR_INVALID_STATE** | The drive does not contain media. |
| **ERROR_NOT_ENOUGH_MEMORY** | An allocation failure occurred during processing. |
| **ERROR_SUCCESS** | The function was successful. |

## Remarks

If the drive specified by the
**DismountNtmsDrive** function is empty or if the media is opened, an error is returned. Otherwise, the media is returned to its slot.

Dismount requests to stand alone drives place the drive in the dismountable state and return success.

## See also

[Library Control Functions](https://learn.microsoft.com/previous-versions/windows/desktop/rsm/removable-storage-manager-functions)