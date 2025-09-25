# CreateNtmsMediaPool function

## Description

[[Removable Storage Manager](https://learn.microsoft.com/previous-versions/windows/desktop/bb540725(v=vs.85)) is no longer available as of Windows 7 and Windows Server 2008 R2.]

The
**CreateNtmsMediaPool** function creates a new application media pool.

## Parameters

### `hSession` [in]

Handle to the session returned by the
[OpenNtmsSession](https://learn.microsoft.com/windows/desktop/api/ntmsapi/nf-ntmsapi-openntmssessiona) function.

### `lpPoolName` [in]

Name of the new media pool. Media pool names must be unique within the scope of a single RSM database.

### `lpMediaType` [in]

Identifier for the type of media in this media pool. Use the
[EnumerateNtmsObject](https://learn.microsoft.com/windows/desktop/api/ntmsapi/nf-ntmsapi-enumeratentmsobject) function to get a list of available media types and their attributes. The application can pass a **NULL** pointer to create a media pool that contains only other media pools.

### `dwAction` [in]

Action to perform. This parameter must be one of the following values.

| Value | Meaning |
| --- | --- |
| **NTMS_OPEN_EXISTING** | Opens an existing media pool by name. Returns ERROR_OBJECT_NOT_FOUND if the pool does not exist. |
| **NTMS_OPEN_ALWAYS** | Opens an existing media pool or creates the pool if it does not exist. |
| **NTMS_CREATE_NEW** | Creates a new media pool. Returns ERROR_ALREADY_EXISTS if the pool exists. |

### `lpSecurityAttributes` [in]

Optional security descriptor used to restrict access to the pool.

### `lpPoolId` [out]

Pointer to a variable that receives the unique identifier of the media pool after the media pool is successfully created or opened.

## Return value

This function returns one of the following values.

| Value | Meaning |
| --- | --- |
| **ERROR_ACCESS_DENIED** | NTMS_CONTROL_ACCESS to the root pool or the parent media pool is denied while trying to create a new media pool. Other security errors are also possible, but they would indicate a security subsystem error.<br><br>**Windows XP:** NTMS_MODIFY_ACCESS to the parent media pool is denied while trying to create a new media pool. Other security errors are also possible, but they would indicate a security subsystem error. |
| **ERROR_ALREADY_EXISTS** | Unable to create a new media pool because one already exists with this name. |
| **ERROR_DATABASE_FAILURE** | The database is inaccessible or damaged. |
| **ERROR_DATABASE_FULL** | The database is full. Other security errors are also possible, but they would indicate a security subsystem error. |
| **ERROR_INVALID_HANDLE** | The session handle is missing or is not valid. |
| **ERROR_INVALID_MEDIA** | The selected media type is not valid. |
| **ERROR_INVALID_NAME** | The pool name syntax is not valid. (The name is too long.) |
| **ERROR_INVALID_PARAMETER** | The media pool name or media pool ID pointer is missing. |
| **ERROR_OBJECT_NOT_FOUND** | Unable to open existing media pool. |
| **ERROR_SUCCESS** | The function was successful. |

## Remarks

Free, Unrecognized, and Import media pools are created by RSM and cannot be created with the
**CreateNtmsMediaPool** function.

RSM media pools are organized as a hierarchy separated by the "\" character. Application, Free, Unrecognized, and Import media pools exist at the root of the hierarchy. RSM creates and manages the Free, Unrecognized, and Import pools. RSM creates a Free media pool for each media type available.

Application-specific media pools are created by applications. Applications create media pools for their own use under the root application pool. These media pools have file system-like names. Only the end-point of the name contains media and policy. An application can define pools such as \MyApp\Pool1 and \MyApp\Pool2. This conveys the hierarchy to the user interface and avoids duplicate names. Each pool level must be created individually; first MyApp and then Pool1 and Pool2, much like folders and files.

**Windows Server 2003:** To create a media pool, you must have NTMS_CONTROL_ACCESS to the root pool and parent pool. If a security descriptor is not provided, the pool inherits the ACEs of its parent pool (if the parent pool is not the root pool). In addition, the creator and local system accounts have full access to the pool. If the parent pool is the root pool, its ACEs are not inherited; the only ACEs in the DACL are full access for the creator and local system accounts.

## See also

[AllocateNtmsMedia](https://learn.microsoft.com/previous-versions/windows/desktop/rsm/media)

[DeleteNtmsMediaPool](https://learn.microsoft.com/windows/desktop/api/ntmsapi/nf-ntmsapi-deletentmsmediapool)

[GetNtmsObjectSecurity](https://learn.microsoft.com/windows/desktop/api/ntmsapi/nf-ntmsapi-getntmsobjectsecurity)

[Media Services Functions](https://learn.microsoft.com/previous-versions/windows/desktop/rsm/removable-storage-manager-functions)

[SetNtmsObjectSecurity](https://learn.microsoft.com/windows/desktop/api/ntmsapi/nf-ntmsapi-setntmsobjectsecurity)