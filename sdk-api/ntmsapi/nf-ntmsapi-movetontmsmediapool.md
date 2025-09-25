# MoveToNtmsMediaPool function

## Description

[[Removable Storage Manager](https://learn.microsoft.com/previous-versions/windows/desktop/bb540725(v=vs.85)) is no longer available as of Windows 7 and Windows Server 2008 R2.]

The
**MoveToNtmsMediaPool** function moves the specified medium from its current media pool to the specified media pool.

## Parameters

### `hSession` [in]

Handle to the session returned by the
[OpenNtmsSession](https://learn.microsoft.com/windows/desktop/api/ntmsapi/nf-ntmsapi-openntmssessiona) function.

### `lpMediaId` [in]

Unique identifier of a piece of physical media.

### `lpPoolId` [in]

Unique identifier of the destination media pool.

## Return value

This function returns one of the following values.

| Value | Meaning |
| --- | --- |
| **ERROR_ACCESS_DENIED** | NTMS_CONTROL_ACCESS to the media's media pool is denied. Other security errors are also possible, but they would indicate a security subsystem error.<br><br>**Windows XP:** NTMS_MODIFY_ACCESS to the source media's media pool or the destination media pool is denied. Other security errors are also possible, but they would indicate a security subsystem error. |
| **ERROR_BUSY** | At least one side of the media is in use or currently unavailable. |
| **ERROR_DATABASE_FAILURE** | The database is inaccessible or damaged. |
| **ERROR_DATABASE_FULL** | The database is full. |
| **ERROR_INVALID_HANDLE** | The session handle is missing or is not valid. |
| **ERROR_INVALID_MEDIA_POOL** | The destination media pool is not valid; the media pool is nonexistent; or the media in the unrecognized or import pool may only be moved to the free pool. |
| **ERROR_INVALID_MEDIA** | The source media or implied source media pool is not valid. |
| **ERROR_INVALID_PARAMETER** | The media ID or media pool ID is missing. |
| **ERROR_MEDIA_INCOMPATIBLE** | The media type of the source differs from the media type of the destination media pool. |
| **ERROR_NOT_ENOUGH_MEMORY** | An allocation failure occurred during processing. |
| **ERROR_SUCCESS** | The function was successful. |

## Remarks

The destination pool specified in the
**MoveToNtmsMediaPool** function must be of the same media type and have compatible security.

RSM writes an on-media identifier to media before moving the media into the free media pool.

A medium having a partition in the Completed, Allocated, or Reserved state may not be moved to the Free media pool. A medium may be moved to an Import pool only if all the partitions of the medium are in the Import state.

**Windows Server 2003:** If the free pool is the source pool, NTMS_USE_ACCESS to the free pool and NTMS_CONTROL_ACCESS to the destination pool is required. Otherwise, NTMS_CONTROL_ACCESS is required on both source and destination pool. If the free pool is the destination pool, NTMS_CONTROL_ACCESS to the source pool and NTMS_USER_ACCESS to the free pool is required. Otherwise, NTMS_CONTROL_ACCESS is required on both source and destination pools.

## See also

[AllocateNtmsMedia](https://learn.microsoft.com/previous-versions/windows/desktop/rsm/media)

[CreateNtmsMediaPool](https://learn.microsoft.com/windows/desktop/api/ntmsapi/nf-ntmsapi-createntmsmediapool)

[Media Services Functions](https://learn.microsoft.com/previous-versions/windows/desktop/rsm/removable-storage-manager-functions)