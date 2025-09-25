# DeleteNtmsLibrary function

## Description

[[Removable Storage Manager](https://learn.microsoft.com/previous-versions/windows/desktop/bb540725(v=vs.85)) is no longer available as of Windows 7 and Windows Server 2008 R2.]

The
**DeleteNtmsLibrary** function deletes a library, and all the devices contained in the library, from the RSM database. All media in the library is moved to the offline library.

## Parameters

### `hSession` [in]

Handle to the session returned by the
[OpenNtmsSession](https://learn.microsoft.com/windows/desktop/api/ntmsapi/nf-ntmsapi-openntmssessiona) function.

### `lpLibraryId` [in]

Unique identifier of the library to be deleted.

## Return value

This function returns one of the following values.

| Value | Meaning |
| --- | --- |
| **ERROR_ACCESS_DENIED** | NTMS_MODIFY_ACCESS to the library is denied. Other security errors are also possible, but they would indicate a security subsystem error. |
| **ERROR_DATABASE_FAILURE** | The database is inaccessible or damaged. |
| **ERROR_DATABASE_FULL** | The database is full. |
| **ERROR_INVALID_HANDLE** | The session handle is missing or is not valid. |
| **ERROR_INVALID_LIBRARY** | The library identifier is not valid. |
| **ERROR_INVALID_PARAMETER** | There is a missing media identifier. |
| **ERROR_NOT_ENOUGH_MEMORY** | There was an allocation failure during processing. |
| **ERROR_SUCCESS** | The function was successful. |

## Remarks

If the library referenced by the
**DeleteNtmsLibrary** function contains media, the media is moved to the offline library.

You can use
**DeleteNtmsLibrary** to remove libraries that are no longer connected to the RSM server.

## See also

[Library Control Functions](https://learn.microsoft.com/previous-versions/windows/desktop/rsm/removable-storage-manager-functions)