# IdentifyNtmsSlot function

## Description

[[Removable Storage Manager](https://learn.microsoft.com/previous-versions/windows/desktop/bb540725(v=vs.85)) is no longer available as of Windows 7 and Windows Server 2008 R2.]

The
**IdentifyNtmsSlot** function identifies the media in the specified slot in a library. The command returns when the identification is complete.

## Parameters

### `hSession` [in]

Handle to the session returned by the
[OpenNtmsSession](https://learn.microsoft.com/windows/desktop/api/ntmsapi/nf-ntmsapi-openntmssessiona) function.

### `lpSlotId` [in]

Unique identifier of the slot object to be identified.

### `dwOption` [in]

This parameter can be one of the following values.

| Value | Meaning |
| --- | --- |
| **NTMS_DISMOUNT_DEFERRED** | Leave the media in the drive after the media identification is complete, as if it had been dismounted with the "deferred" option. |
| **NTMS_DISMOUNT_IMMEDIATE** | Dismount the media in the drive after the media identification is complete. |

## Return value

This function returns one of the following values.

| Value | Meaning |
| --- | --- |
| **ERROR_ACCESS_DENIED** | Access to one or more RSM objects is denied. |
| **ERROR_INVALID_HANDLE** | The value specified in the *hSession* parameter is not valid. |
| **ERROR_INVALID_PARAMETER** | The slot ID or the *dwOption* is not valid. |
| **ERROR_SUCCESS** | The function was successful. |

## Remarks

If the slot is empty the function returns ERROR_SUCCESS, but no new media records appear.

## See also

[InventoryNtmsLibrary](https://learn.microsoft.com/windows/desktop/api/ntmsapi/nf-ntmsapi-inventoryntmslibrary)

[Library Control Functions](https://learn.microsoft.com/previous-versions/windows/desktop/rsm/removable-storage-manager-functions)