# CleanNtmsDrive function

## Description

[[Removable Storage Manager](https://learn.microsoft.com/previous-versions/windows/desktop/bb540725(v=vs.85)) is no longer available as of Windows 7 and Windows Server 2008 R2.]

The
**CleanNtmsDrive** function queues a cleaning request for the specified drive for cleaning.

## Parameters

### `hSession` [in]

Handle to the session returned by the
[OpenNtmsSession](https://learn.microsoft.com/windows/desktop/api/ntmsapi/nf-ntmsapi-openntmssessiona) function.

### `lpDriveId` [in]

Unique identifier of the drive to be cleaned.

## Return value

This function returns one of the following values.

| Value | Meaning |
| --- | --- |
| **ERROR_ACCESS_DENIED** | NTMS_CONTROL_ACCESS to the library is denied. Other security errors are also possible, but they would indicate a security subsystem error. |
| **ERROR_DATABASE_FAILURE** | The database is inaccessible or damaged. |
| **ERROR_DATABASE_FULL** | The database is full. |
| **ERROR_INVALID_DRIVE** | The drive ID is not valid. |
| **ERROR_INVALID_HANDLE** | The session handle is missing or is not valid. |
| **ERROR_INVALID_LIBRARY** | The library for the drive is not valid. |
| **ERROR_INVALID_PARAMETER** | The drive ID is missing. |
| **ERROR_NOT_ENOUGH_MEMORY** | An allocation failure occurred during processing. |
| **ERROR_RESOURCE_DISABLED** | The drive or the library is not enabled. |
| **ERROR_SUCCESS** | The cleaning was queued successfully. |

## Remarks

If the drive you selected in the
**CleanNtmsDrive** function is a stand-alone drive, the drive is marked as cleaned and the time is noted in the
[RSM Database](https://learn.microsoft.com/previous-versions/windows/desktop/rsm/rsm-database).

Queued cleaning requests are deleted when the service is restarted.

## See also

[Cleaner Management Functions](https://learn.microsoft.com/previous-versions/windows/desktop/rsm/removable-storage-manager-functions)

[EjectNtmsCleaner](https://learn.microsoft.com/windows/desktop/api/ntmsapi/nf-ntmsapi-ejectntmscleaner)

[InjectNtmsCleaner](https://learn.microsoft.com/windows/desktop/api/ntmsapi/nf-ntmsapi-injectntmscleaner)

[ReleaseNtmsCleanerSlot](https://learn.microsoft.com/windows/desktop/api/ntmsapi/nf-ntmsapi-releasentmscleanerslot)

[ReserveNtmsCleanerSlot](https://learn.microsoft.com/windows/desktop/api/ntmsapi/nf-ntmsapi-reserventmscleanerslot)