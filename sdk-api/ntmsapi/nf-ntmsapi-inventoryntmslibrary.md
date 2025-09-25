# InventoryNtmsLibrary function

## Description

[[Removable Storage Manager](https://learn.microsoft.com/previous-versions/windows/desktop/bb540725(v=vs.85)) is no longer available as of Windows 7 and Windows Server 2008 R2.]

The
**InventoryNtmsLibrary** function queues an inventory of the specified library. If the library is busy, RSM queues
**InventoryNtmsLibrary** and returns success.

## Parameters

### `hSession` [in]

Handle to the session returned by the
[OpenNtmsSession](https://learn.microsoft.com/windows/desktop/api/ntmsapi/nf-ntmsapi-openntmssessiona) function.

### `lpLibraryId` [in]

Unique identifier of a library object.

### `dwAction` [in]

Action to perform. This parameter can be one of the following values.

| Value | Meaning |
| --- | --- |
| **NTMS_INVENTORY_OMID** | A full on-media inventory is performed. Each side of each medium must be mounted into a drive. This is a time consuming process. |
| **NTMS_INVENTORY_FAST** | If the library has a bar-code reader installed, this flag causes a bar-code inventory to be performed. If the library does not have a bar-code reader, this flag causes a differential inventory to be performed (slots are classified). |
| **NTMS_INVENTORY_DEFAULT** | Use the **InventoryMethod** specified in the library object (see [NTMS_LIBRARYINFORMATION](https://learn.microsoft.com/windows/desktop/api/ntmsapi/ns-ntmsapi-ntms_libraryinformation)). |
| **NTMS_INVENTORY_STOP** | Stop the current inventory in the specified library. |

## Return value

This function returns one of the following values.

| Value | Meaning |
| --- | --- |
| **ERROR_ACCESS_DENIED** | Access to one or more RSM objects is denied. |
| **ERROR_DEVICE_NOT_AVAILABLE** | The library is not currently connected. |
| **ERROR_INVALID_HANDLE** | The value specified in the *hSession* parameter is not valid. |
| **ERROR_INVALID_LIBRARY** | The library is the offline library. |
| **ERROR_INVALID_PARAMETER** | The library ID or session ID is not valid. |
| **ERROR_NOT_CONNECTED** | Unable to connect to the RSM service. |
| **ERROR_SUCCESS** | The function was successful. |

## Remarks

Not present libraries cannot be inventoried.

The
**InventoryNtmsLibrary** function marks all the slots that currently contain a medium in the library for classification/identification. The
**InventoryNtmsLibrary** function returns when all the media is marked.

## See also

[AccessNtmsLibraryDoor](https://learn.microsoft.com/windows/desktop/api/ntmsapi/nf-ntmsapi-accessntmslibrarydoor)

[Library Control Functions](https://learn.microsoft.com/previous-versions/windows/desktop/rsm/removable-storage-manager-functions)