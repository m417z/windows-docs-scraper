# DisableNtmsObject function

## Description

[[Removable Storage Manager](https://learn.microsoft.com/previous-versions/windows/desktop/bb540725(v=vs.85)) is no longer available as of Windows 7 and Windows Server 2008 R2.]

The
**DisableNtmsObject** function disables the specified RSM object.

## Parameters

### `hSession` [in]

Handle to the session returned by the
[OpenNtmsSession](https://learn.microsoft.com/windows/desktop/api/ntmsapi/nf-ntmsapi-openntmssessiona) function.

### `dwType` [in]

RSM object type. This parameter can be one of the following values from the
[NtmsObjectsTypes](https://learn.microsoft.com/windows/desktop/api/ntmsapi/ne-ntmsapi-ntmsobjectstypes) enumeration type.

| Value | Meaning |
| --- | --- |
| **NTMS_DRIVE** | Drive |
| **NTMS_LIBRARY** | Library |
| **NTMS_PHYSICAL_MEDIA** | Physical media (tape, optical disk, CD, or magnetic cartridge) |

### `lpObjectId` [in]

Unique identifier of the RSM object.

## Return value

This function returns one of the following values.

| Value | Meaning |
| --- | --- |
| **ERROR_ACCESS_DENIED** | NTMS_MODIFY_ACCESS to the library containing the object is denied. Other security errors are possible, but indicate a security subsystem error.<br><br>**Windows XP:** NTMS_CONTROL_ACCESS to the library containing the object is denied. Other security errors are possible, but indicate a security subsystem error. |
| **ERROR_DATABASE_FAILURE** | The database is inaccessible or damaged. |
| **ERROR_INVALID_HANDLE** | The session handle is missing or is not valid. |
| **ERROR_INVALID_PARAMETER** | An object ID is missing or the object type is not valid. (The object type is not valid if it is not NTMS_LIBRARY, NTMS_DRIVE, or NTMS_PHYSICAL_MEDIA.) |
| **ERROR_INVALID_STATE** | The object is already disabled. |
| **ERROR_LIBRARY_OFFLINE** | The library ID refers to an off-line library that cannot be enabled or disabled. |
| **ERROR_OBJECT_NOT_FOUND** | The object is not valid. |
| **ERROR_SUCCESS** | The disable is queued. |

## Remarks

The
**DisableNtmsObject** function queues a disable command for the specified object. The function returns successfully when the command is queued. If RSM is busy, the command can take some time to complete. When the medium is disabled, RSM renders all of the media's sides and associated logical media unavailable. All requests to disabled media return errors.

To remove a drive or media changer from service the drive or media changer must first be disabled.

All objects contained by a disabled object are also disabled. For example, disabling a piece of physical media disables all sides. Whenever possible, when a drive is disabled, the medium in the drive is removed and placed in its slot.

## See also

[EnableNtmsObject](https://learn.microsoft.com/windows/desktop/api/ntmsapi/nf-ntmsapi-enablentmsobject)

[Object Management Functions](https://learn.microsoft.com/previous-versions/windows/desktop/rsm/removable-storage-manager-functions)