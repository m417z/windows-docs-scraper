# AddNtmsMediaType function

## Description

[[Removable Storage Manager](https://learn.microsoft.com/previous-versions/windows/desktop/bb540725(v=vs.85)) is no longer available as of Windows 7 and Windows Server 2008 R2.]

The
**AddNtmsMediaType** function adds the specified media type to the specified library if there is not currently a relation in the library object. The function then creates the system
[media pools](https://learn.microsoft.com/previous-versions/windows/desktop/bb540696(v=vs.85)) if they do not exist.

## Parameters

### `hSession` [in]

Handle to the session returned by the
[OpenNtmsSession](https://learn.microsoft.com/windows/desktop/api/ntmsapi/nf-ntmsapi-openntmssessiona) function.

### `lpMediaTypeId` [in]

Unique identifier of the media type to add to the library.

### `lpLibId` [in]

Unique identifier of the library to which the media type will be added.

## Return value

This function returns one of the following values.

| Value | Meaning |
| --- | --- |
| **ERROR_ACCESS_DENIED** | NTMS_MODIFY_ACCESS to the library is denied. Other security errors are possible, but they would indicate a security subsystem error.<br><br>**Windows XP:** NTMS_CONTROL_ACCESS to the library is denied. Other security errors are possible, but they would indicate a security subsystem error. |
| **ERROR_DATABASE_FAILURE** | The database is inaccessible or damaged. |
| **ERROR_DATABASE_FULL** | The database is full. |
| **ERROR_INVALID_HANDLE** | The session handle is missing or is not valid. |
| **ERROR_INVALID_LIBRARY** | The library ID is not valid. |
| **ERROR_INVALID_MEDIA** | The media type is not valid. |
| **ERROR_INVALID_PARAMETER** | The media type or library ID is missing. |
| **ERROR_NOT_ENOUGH_MEMORY** | There was an allocation failure during processing. |
| **ERROR_SUCCESS** | The function was successful. |

## See also

[DeleteNtmsMediaType](https://learn.microsoft.com/windows/desktop/api/ntmsapi/nf-ntmsapi-deletentmsmediatype)

[Media Services Functions](https://learn.microsoft.com/previous-versions/windows/desktop/rsm/removable-storage-manager-functions)