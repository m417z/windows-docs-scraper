# DeleteNtmsMediaType function

## Description

[[Removable Storage Manager](https://learn.microsoft.com/previous-versions/windows/desktop/bb540725(v=vs.85)) is no longer available as of Windows 7 and Windows Server 2008 R2.]

The
**DeleteNtmsMediaType** function deletes the specified media type relation from the specified library, provided that the library does not contain any physical media objects of the specified media type.

## Parameters

### `hSession` [in]

Handle to the session returned by the
[OpenNtmsSession](https://learn.microsoft.com/windows/desktop/api/ntmsapi/nf-ntmsapi-openntmssessiona) function.

### `lpMediaTypeId` [in]

Unique identifier of a media type to delete from a library.

### `lpLibId` [in]

Unique identifier of the library from which to delete the media type.

## Return value

This function returns one of the following values.

| Value | Meaning |
| --- | --- |
| **ERROR_ACCESS_DENIED** | NTMS_MODIFY_ACCESS to the library is denied. Other security errors are possible, but indicate a security subsystem error.<br><br>**Windows XP:** NTMS_CONTROL_ACCESS to the library is denied. Other security errors are possible, but indicate a security subsystem error. |
| **ERROR_DATABASE_FAILURE** | The database is inaccessible or damaged. |
| **ERROR_DATABASE_FULL** | The database is full. |
| **ERROR_INVALID_HANDLE** | The session handle is missing or is not valid. |
| **ERROR_INVALID_LIBRARY** | The library ID is not valid. |
| **ERROR_INVALID_PARAMETER** | The media type or library ID is missing. |
| **ERROR_NOT_ENOUGH_MEMORY** | An allocation failure occurred during processing. |
| **ERROR_SUCCESS** | The function was successful. |

## Remarks

If there are no physical media objects of the specified media type in the RSM system and there are no library objects that contain the specified media type relation in the RSM system, the system media pools for that media type will be deleted. Inability to delete the system media pools does not cause the
**DeleteNtmsMediaType** function to fail.

## See also

[AddNtmsMediaType](https://learn.microsoft.com/windows/desktop/api/ntmsapi/nf-ntmsapi-addntmsmediatype)

[Media Services Functions](https://learn.microsoft.com/previous-versions/windows/desktop/rsm/removable-storage-manager-functions)