# DeallocateNtmsMedia function

## Description

[[Removable Storage Manager](https://learn.microsoft.com/previous-versions/windows/desktop/bb540725(v=vs.85)) is no longer available as of Windows 7 and Windows Server 2008 R2.]

The
**DeallocateNtmsMedia** function deallocates the side associated with the specified logical media.

## Parameters

### `hSession` [in]

Handle to the session returned by the
[OpenNtmsSession](https://learn.microsoft.com/windows/desktop/api/ntmsapi/nf-ntmsapi-openntmssessiona) function.

### `lpMediaId` [in]

Unique identifier of the logical media (LMID).

### `dwOptions`

Reserved; must be zero.

## Return value

This function returns one of the following values.

| Value | Meaning |
| --- | --- |
| **ERROR_ACCESS_DENIED** | NTMS_CONTROL_ACCESS to the media's media pool is denied. Other security errors are also possible, but they would indicate a security subsystem error.<br><br>**Windows XP:** NTMS_MODIFY_ACCESS to the media's media pool is denied. Other security errors are also possible, but they would indicate a security subsystem error. |
| **ERROR_DATABASE_FAILURE** | The database is inaccessible or damaged. |
| **ERROR_DATABASE_FULL** | The database is full. |
| **ERROR_INVALID_HANDLE** | The session handle missing or is not valid. |
| **ERROR_INVALID_MEDIA** | The LMID is not valid. |
| **ERROR_INVALID_PARAMETER** | The media or media pool ID is missing. |
| **ERROR_INVALID_PARTITION** | The LMID side is not valid. |
| **ERROR_NOT_ENOUGH_MEMORY** | An allocation failure occurred during processing. |
| **ERROR_SUCCESS** | The function was successful. |

## Remarks

When a logical medium is deallocated with the
**DeallocateNtmsMedia** function, RSM puts the side associated with the logical media in the Available or Decommissioned media state. The logical media is deleted from the system when the logical media is deallocated.

Sides are decommissioned upon deallocation if the side has been allocated the maximum number of times specified in the media pool. After media is in the Decommissioned state, it cannot be allocated again.

**Windows Server 2003:** If media is being returned to the free pool, NTMS_USE_ACCESS to the free pool and NTMS_CONTROL_ACCESS to the source pool is required. If the free pool is not the destination media pool, NTMS_CONTROL_ACCESS is required on both source and destination pools.

## See also

[AllocateNtmsMedia](https://learn.microsoft.com/previous-versions/windows/desktop/rsm/media)

[Media Services Functions](https://learn.microsoft.com/previous-versions/windows/desktop/rsm/removable-storage-manager-functions)