# DecommissionNtmsMedia function

## Description

[[Removable Storage Manager](https://learn.microsoft.com/previous-versions/windows/desktop/bb540725(v=vs.85)) is no longer available as of Windows 7 and Windows Server 2008 R2.]

The
**DecommissionNtmsMedia** function moves a side from the Available state to the Decommissioned state.

## Parameters

### `hSession` [in]

Handle to the session returned by the
[OpenNtmsSession](https://learn.microsoft.com/windows/desktop/api/ntmsapi/nf-ntmsapi-openntmssessiona) function.

### `lpMediaId` [in]

Unique identifier of a side of a piece of physical media.

## Return value

| Value | Meaning |
| --- | --- |
| **ERROR_ACCESS_DENIED** | NTMS_CONTROL_ACCESS to the media's media pool is denied. Other security errors are also possible, but they would indicate a security subsystem error.<br><br>**Windows XP:** NTMS_MODIFY_ACCESS to the media's media pool is denied. Other security errors are also possible, but they would indicate a security subsystem error. |
| **ERROR_DATABASE_FAILURE** | The database is inaccessible or damaged. |
| **ERROR_DATABASE_FULL** | The database is full. |
| **ERROR_INVALID_HANDLE** | The session handle is missing or is not valid. |
| **ERROR_INVALID_MEDIA** | The media identifier is not valid. |
| **ERROR_INVALID_MEDIA_POOL** | The media pool for media is not valid. |
| **ERROR_INVALID_PARAMETER** | The media identifier is missing. |
| **ERROR_INVALID_STATE** | The media is not in the Available state. |
| **ERROR_NOT_ENOUGH_MEMORY** | An allocation failure occurred during processing. |
| **ERROR_SUCCESS** | The function was successful. |

## Remarks

Media decommissioned by the
**DecommissionNtmsMedia** function is recognized by RSM but the decommissioned media does not contain any data and is never again used.

Only media that is in the Available state can be decommissioned. For more information, see
[Media Life Cycle](https://learn.microsoft.com/previous-versions/windows/desktop/rsm/media-life-cycle).

## See also

[AllocateNtmsMedia](https://learn.microsoft.com/previous-versions/windows/desktop/rsm/media)

[Media Services Functions](https://learn.microsoft.com/previous-versions/windows/desktop/rsm/removable-storage-manager-functions)