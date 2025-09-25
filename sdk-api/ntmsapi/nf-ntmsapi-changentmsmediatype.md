# ChangeNtmsMediaType function

## Description

[[Removable Storage Manager](https://learn.microsoft.com/previous-versions/windows/desktop/bb540725(v=vs.85)) is no longer available as of Windows 7 and Windows Server 2008 R2.]

The
**ChangeNtmsMediaType** function moves the specified PMID to the specified target media pool and sets the PMID's media type identifier to the media type of the target media pool.

## Parameters

### `hSession` [in]

Handle to the session returned by the
[OpenNtmsSession](https://learn.microsoft.com/windows/desktop/api/ntmsapi/nf-ntmsapi-openntmssessiona) function.

### `lpMediaId` [in]

Unique identifier of the physical media to be moved.

### `lpPoolId` [in]

Unique identifier of the media pool from which the media is to be allocated.

## Return value

This function returns one of the following values.

| Value | Meaning |
| --- | --- |
| **ERROR_ACCESS_DENIED** | NTMS_MODIFY_ACCESS to the computer or the media's media pool is denied. Other security errors are possible, but they would indicate a security subsystem error.<br><br>**Windows XP:**  NTMS_MODIFY_ACCESS to the media's media pool is denied. |
| **ERROR_DATABASE_FAILURE** | The database is inaccessible or damaged. |
| **ERROR_DATABASE_FULL** | The database is full. |
| **ERROR_INVALID_HANDLE** | The session handle is missing or is not valid. |
| **ERROR_INVALID_MEDIA_POOL** | The media pool ID is not valid. |
| **ERROR_INVALID_PARAMETER** | The media pool or media ID is missing. |
| **ERROR_NOT_ENOUGH_MEMORY** | An allocation failure occurred during processing. |
| **ERROR_SUCCESS** | The function was successful. |

## Remarks

The
**ChangeNtmsMediaType** function uses the same policy for moving media as the
[MoveToNtmsMediaPool](https://learn.microsoft.com/windows/desktop/api/ntmsapi/nf-ntmsapi-movetontmsmediapool) function (unrecognized media can only be moved to the free pool).

## See also

[AddNtmsMediaType](https://learn.microsoft.com/windows/desktop/api/ntmsapi/nf-ntmsapi-addntmsmediatype)

[DeleteNtmsMediaType](https://learn.microsoft.com/windows/desktop/api/ntmsapi/nf-ntmsapi-deletentmsmediatype)

[Media Services Functions](https://learn.microsoft.com/previous-versions/windows/desktop/rsm/removable-storage-manager-functions)