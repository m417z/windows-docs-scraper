# SetNtmsObjectInformation function

## Description

[[Removable Storage Manager](https://learn.microsoft.com/previous-versions/windows/desktop/bb540725(v=vs.85)) is no longer available as of Windows 7 and Windows Server 2008 R2.]

The
**SetNtmsObjectInformation** function changes the information structure of the specified object.

## Parameters

### `hSession` [in]

Handle to the session returned by the
[OpenNtmsSession](https://learn.microsoft.com/windows/desktop/api/ntmsapi/nf-ntmsapi-openntmssessiona) function.

### `lpObjectId` [in]

Unique identifier of the RSM object.

### `lpInfo` [in]

Pointer to an
[NTMS_OBJECTINFORMATION](https://learn.microsoft.com/windows/desktop/api/ntmsapi/ns-ntmsapi-ntms_objectinformationa) structure.

## Return value

This function returns one of the following values.

| Value | Meaning |
| --- | --- |
| **ERROR_ACCESS_DENIED** | NTMS_MODIFY_ACCESS or NTMS_CONTROL_ACCESS is denied to the object being written or no modifications are allowed to the object type specified. See Remarks. |
| **ERROR_SUCCESS** | The function was successful. |
| **ERROR_DATABASE_FAILURE** | The database is inaccessible or damaged. |
| **ERROR_DATABASE_FULL** | The database is full. |
| **ERROR_INVALID_HANDLE** | The session handle is missing or is not valid. |
| **ERROR_INVALID_PARAMETER** | The object ID or information structure is missing, or the object information size or object type is not valid. |
| **ERROR_NOT_ENOUGH_MEMORY** | An allocation failure occurred during processing. |
| **ERROR_OBJECT_NOT_FOUND** | The object ID is not valid. |

## Remarks

The information size and type must be set before you can use
**SetNtmsObjectInformation**.

All writable properties for the object are read from the
[NTMS_OBJECTINFORMATION](https://learn.microsoft.com/windows/desktop/api/ntmsapi/ns-ntmsapi-ntms_objectinformationa) structure and written to the database without regard for any write operations that have occurred between the time this application called the
[GetNtmsObjectInformation](https://learn.microsoft.com/windows/desktop/api/ntmsapi/nf-ntmsapi-getntmsobjectinformation) function and the
**SetNtmsObjectInformation** function. Because of this you can lose changes.

To avoid unpredictable results, applications must call
[GetNtmsObjectInformation](https://learn.microsoft.com/windows/desktop/api/ntmsapi/nf-ntmsapi-getntmsobjectinformation) before calling
**SetNtmsObjectInformation**. As noted above,
**SetNtmsObjectInformation** updates all writable members, therefore the application is responsible for providing a value for all writable members.

The following is the list of objects that have members that can be updated.

| Object | Members |
| --- | --- |
| NTMS_CHANGER | **szDescription** Requires NTMS_MODIFY_ACCESS to the library.<br><br>**Windows XP:**  No access rights are required. |
| NTMS_CHANGER_TYPE | **szDescription** Requires NTMS_MODIFY_ACCESS to the computer.<br><br>**Windows XP:**  No access rights are required. |
| NTMS_COMPUTER | **dwMediaPoolPolicy****dwLibRequestFlags****dwLibRequestPurgeTime****dwOpRequestFlags****dwOpRequestPurgeTime****szDescription** Requires NTMS_MODIFY_ACCESS to the computer.<br><br>**Windows XP:**  No access rights are required. |
| NTMS_DRIVE | **dwDeferDismountDelay****szDescription** Requires NTMS_MODIFY_ACCESS to the library.<br><br>**Windows XP:**  No access rights are required. |
| NTMS_DRIVE_TYPE | **szDescription** Requires NTMS_MODIFY_ACCESS to the computer.<br><br>**Windows XP:**  No access rights are required. |
| NTMS_IEDOOR | **MaxOpenSecs****szDescription** Requires NTMS_MODIFY_ACCESS to the library.<br><br>**Windows XP:**  No access rights are required. |
| NTMS_IEPORT | **MaxExtendSecs****szDescription** Requires NTMS_MODIFY_ACCESS to the library.<br><br>**Windows XP:**  No access rights are required. |
| NTMS_LIBRARY | **AutoRecovery****dwCleanerUsesRemaining****dwFlags****InventoryMethod****szDescription****szName** Requires NTMS_CONTROL_ACCESS to the library. |
| NTMS_LIBREQUEST | **szDescription** Requires NTMS_MODIFY_ACCESS to the library.<br><br>**Windows XP:**  No access rights are required. |
| NTMS_LOGICAL_MEDIA | **szDescription****szName** Requires NTMS_MODIFY_ACCESS to the media pool of the logical media.<br><br>**Windows XP:**  No access rights are required. |
| NTMS_MEDIA_POOL | **AllocationPolicy****DeallocationPolicy****dwMaxAllocates****MediaType****szDescription****szName** Requires NTMS_MODIFY_ACCESS to the media pool.<br><br>**Windows XP:**  Requires NTMS_CONTROL_ACCESS to the media pool. |
| NTMS_MEDIA_TYPE | **szDescription** Requires NTMS_MODIFY_ACCESS to the computer.<br><br>**Windows XP:**  No access rights are required. |
| NTMS_OPREQUEST | **szDescription** Requires NTMS_MODIFY_ACCESS to the computer.<br><br>**Windows XP:**  No access rights are required. |
| NTMS_PARTITION | **szName****szDescription** Requires NTMS_MODIFY_ACCESS to the media pool of the side.<br><br>**Windows XP:**  Requires NTMS_CONTROL_ACCESS to the media pool of the side. |
| NTMS_PHYSICAL_MEDIA | **szDescription****szName** Requires NTMS_MODIFY_ACCESS to the media pool.<br><br>**Windows XP:**  No access rights are required. |
| NTMS_STORAGESLOT | **szDescription** Requires NTMS_MODIFY_ACCESS to the library.<br><br>**Windows XP:**  No access rights are required. |

## See also

[GetNtmsObjectInformation](https://learn.microsoft.com/windows/desktop/api/ntmsapi/nf-ntmsapi-getntmsobjectinformation)

[GetNtmsObjectSecurity](https://learn.microsoft.com/windows/desktop/api/ntmsapi/nf-ntmsapi-getntmsobjectsecurity)

[NTMS_OBJECTINFORMATION](https://learn.microsoft.com/windows/desktop/api/ntmsapi/ns-ntmsapi-ntms_objectinformationa)

[Object Management Functions](https://learn.microsoft.com/previous-versions/windows/desktop/rsm/removable-storage-manager-functions)