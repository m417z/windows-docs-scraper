# SwapNtmsMedia function

## Description

[[Removable Storage Manager](https://learn.microsoft.com/previous-versions/windows/desktop/bb540725(v=vs.85)) is no longer available as of Windows 7 and Windows Server 2008 R2.]

The
**SwapNtmsMedia** function swaps the sides associated with the two specified LMIDs. The specified LMIDs must be in the same media pool.

## Parameters

### `hSession` [in]

Handle to the session returned by the
[OpenNtmsSession](https://learn.microsoft.com/windows/desktop/api/ntmsapi/nf-ntmsapi-openntmssessiona) function.

### `lpMediaId1` [in]

Unique identifier of a piece of logical media (LMID).

### `lpMediaId2` [in]

Unique identifier of a piece of logical media (LMID).

## Return value

This function returns one of the following values.

| Value | Meaning |
| --- | --- |
| **ERROR_ACCESS_DENIED** | NTMS_MODIFY_ACCESS to either media's media pool is denied. Other security errors are also possible, but they would indicate a security subsystem error. |
| **ERROR_BAD_FORMAT** | No media label library recognizes the media label. |
| **ERROR_DATABASE_FAILURE** | The database is inaccessible or damaged. |
| **ERROR_DATABASE_FULL** | The database is full. |
| **ERROR_INVALID_HANDLE** | The session handle is missing or is not valid. |
| **ERROR_INVALID_MEDIA** | At least one of the media IDs is not valid. |
| **ERROR_INVALID_MEDIA_POOL** | One or more media pools for the logical media are not valid. |
| **ERROR_INVALID_PARAMETER** | At least one media identifier is missing. |
| **ERROR_NOT_ENOUGH_MEMORY** | An allocation failure occurred during processing. |
| **ERROR_SUCCESS** | The function was successful. |

## Remarks

The
**SwapNtmsMedia** function is used to update physical media without affecting the application.

The media for both LMIDs must not be in use for this function to succeed.

## See also

[AllocateNtmsMedia](https://learn.microsoft.com/previous-versions/windows/desktop/rsm/media)

[Media Services Functions](https://learn.microsoft.com/previous-versions/windows/desktop/rsm/removable-storage-manager-functions)