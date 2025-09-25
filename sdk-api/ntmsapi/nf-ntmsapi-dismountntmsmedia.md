# DismountNtmsMedia function

## Description

[[Removable Storage Manager](https://learn.microsoft.com/previous-versions/windows/desktop/bb540725(v=vs.85)) is no longer available as of Windows 7 and Windows Server 2008 R2.]

The
**DismountNtmsMedia** function queues a command to move the specified media in a drive to its storage. This function should be paired with the
[MountNtmsMedia](https://learn.microsoft.com/windows/desktop/api/ntmsapi/nf-ntmsapi-mountntmsmedia) function.

## Parameters

### `hSession` [in]

Handle to the session returned by the
[OpenNtmsSession](https://learn.microsoft.com/windows/desktop/api/ntmsapi/nf-ntmsapi-openntmssessiona) function.

### `lpMediaId` [in]

Array of at least one logical medium or side.

### `dwCount` [in]

Number of media identifiers in the *lpMediaId* parameter.

### `dwOptions` [in]

Options. This parameter can be the following value.

| Value | Meaning |
| --- | --- |
| **NTMS_DISMOUNT_DEFERRED** | Marks media state as Dismountable, and keeps the medium in the drive. Subsequent mount requests are satisfied using dismounted or dismountable drives. The default is to dismount immediately. |
| **NTMS_DISMOUNT_IMMEDIATE** | Dismount the drive immediately. |

## Return value

This function returns one of the following values.

| Value | Meaning |
| --- | --- |
| **ERROR_ACCESS_DENIED** | NTMS_USE_ACCESS to the media pool or library that contains the media is denied. Other security errors are also possible, but they would indicate a security subsystem error. |
| **ERROR_DATABASE_FAILURE** | The database is inaccessible or damaged. |
| **ERROR_DATABASE_FULL** | The database is full. |
| **ERROR_DEVICE_NOT_AVAILABLE** | One or more resources required to perform the dismount are not currently available (probably disabled). |
| **ERROR_INVALID_LIBRARY** | The library that contains the media is not valid. |
| **ERROR_INVALID_MEDIA** | At least one of the specified media is not valid. |
| **ERROR_INVALID_STATE** | An unexpected media or device state occurred during dismount. |
| **ERROR_MEDIA_OFFLINE** | The specified media is offline. |
| **ERROR_MEDIA_NOT_AVAILABLE** | One or more media resources required to perform the mount are not currently available (probably disabled). |
| **ERROR_NOT_ENOUGH_MEMORY** | A memory allocation failure occurred during processing. |
| **ERROR_SUCCESS** | The media dismount has been queued. |
| **ERROR_TIMEOUT** | The time-out event expired while the application attempted to acquire one or more resources. |

## Remarks

An application must use the
**DismountNtmsMedia** function to release the drive resource after the application has used the specified medium. Unreleased media cannot be used by other RSM sessions.

The
**DismountNtmsMedia** function returns as soon as the operation is queued with RSM. The application can wait for the side state to become idle.

## See also

[Media Services Functions](https://learn.microsoft.com/previous-versions/windows/desktop/rsm/removable-storage-manager-functions)

[MountNtmsMedia](https://learn.microsoft.com/windows/desktop/api/ntmsapi/nf-ntmsapi-mountntmsmedia)