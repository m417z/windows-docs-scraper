# AccessNtmsLibraryDoor function

## Description

[[Removable Storage Manager](https://learn.microsoft.com/previous-versions/windows/desktop/bb540725(v=vs.85)) is no longer available as of Windows 7 and Windows Server 2008 R2.]

The
**AccessNtmsLibraryDoor** function unlocks the door of the specified library. If the library is busy, RSM queues the request and returns successfully.

## Parameters

### `hSession` [in]

Handle to the session returned by the
[OpenNtmsSession](https://learn.microsoft.com/windows/desktop/api/ntmsapi/nf-ntmsapi-openntmssessiona) function.

### `lpLibraryId` [in]

Unique identifier of the library object. This library must support door access.

### `dwAction` [in]

Action to perform. This parameter can be one of the following values.

| Value | Meaning |
| --- | --- |
| **NTMS_INVENTORY_NONE** | After the user closes the door, no inventory is performed. However, if a mount-label check fails, an inventory will be performed. |
| **NTMS_INVENTORY_OMID** | After the user closes the door, a full on-media inventory is performed. This can be time consuming because each side of each medium must be mounted. |
| **NTMS_INVENTORY_FAST** | If the library has a bar-code reader installed, this flag causes bar-code inventory to be performed. If the library does not have a bar-code reader, this flag causes a differential inventory to be performed. The OMIDs are checked on each medium placed in an empty slot while the door is open. |
| **NTMS_INVENTORY_DEFAULT** | Use the **InventoryMethod** specified in the library object (see [NTMS_LIBRARYINFORMATION](https://learn.microsoft.com/windows/desktop/api/ntmsapi/ns-ntmsapi-ntms_libraryinformation)). |

## Return value

This function returns one of the following values.

| Value | Meaning |
| --- | --- |
| **ERROR_ACCESS_DENIED** | NTMS_CONTROL_ACCESS to the library is denied. Other security errors are also possible, but they would indicate a security subsystem error. |
| **ERROR_DATABASE_FAILURE** | The database is inaccessible or damaged. |
| **ERROR_DATABASE_FULL** | The database is full. |
| **ERROR_INVALID_HANDLE** | The session ID is missing or is not valid. |
| **ERROR_INVALID_PARAMETER** | The library ID is missing. |
| **ERROR_LIBRARY_OFFLINE** | The library ID references an offline library without a door. |
| **ERROR_NOT_ENOUGH_MEMORY** | An allocation failure occurred during processing. |
| **ERROR_RESOURCE_DISABLED** | The library is disabled. |
| **ERROR_RESOURCE_NOT_PRESENT** | The library does not have a door. |
| **ERROR_SUCCESS** | Door access is queued. |

## Remarks

Some libraries provide no means for RSM to programmatically lock and unlock their doors. The behavior of this function with these libraries is identical to its behavior with libraries that RSM can unlock and lock.

## See also

[EjectNtmsMedia](https://learn.microsoft.com/windows/desktop/api/ntmsapi/nf-ntmsapi-ejectntmsmedia)

[InjectNtmsMedia](https://learn.microsoft.com/windows/desktop/api/ntmsapi/nf-ntmsapi-injectntmsmedia)

[Library Control Functions](https://learn.microsoft.com/previous-versions/windows/desktop/rsm/removable-storage-manager-functions)