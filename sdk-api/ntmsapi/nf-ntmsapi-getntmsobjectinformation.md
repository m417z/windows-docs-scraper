# GetNtmsObjectInformation function

## Description

[[Removable Storage Manager](https://learn.microsoft.com/previous-versions/windows/desktop/bb540725(v=vs.85)) is no longer available as of Windows 7 and Windows Server 2008 R2.]

The
**GetNtmsObjectInformation** function returns an object's information structure for the specified object.

## Parameters

### `hSession` [in]

Handle to the session returned by the
[OpenNtmsSession](https://learn.microsoft.com/windows/desktop/api/ntmsapi/nf-ntmsapi-openntmssessiona) function.

### `lpObjectId` [in]

Unique identifier of the RSM object.

### `lpInfo` [out]

Pointer to an
[NTMS_OBJECTINFORMATION](https://learn.microsoft.com/windows/desktop/api/ntmsapi/ns-ntmsapi-ntms_objectinformationa) structure that receives the object information.

## Return value

This function returns one of the following values.

| Value | Meaning |
| --- | --- |
| **ERROR_ACCESS_DENIED** | NTMS_USE_ACCESS to the object or its container is denied. Other security errors are also possible, but they would indicate a security subsystem error.<br><br>**Windows XP:** No access rights are required. |
| **ERROR_INVALID_HANDLE** | The session handle is missing or is not valid. |
| **ERROR_INVALID_PARAMETER** | The object ID or information structure is missing, or the object information size or object type is not valid. |
| **ERROR_NOT_ENOUGH_MEMORY** | An allocation failure occurred during processing. |
| **ERROR_OBJECT_NOT_FOUND** | The object ID is not valid. |
| **ERROR_SUCCESS** | The function was successful. |

## Remarks

The information size and type of the information structure must be set correctly in the *lpInfo* parameter before you use the
**GetNtmsObjectInformation** function.

To avoid unpredictable results, applications must call the
**GetNtmsObjectInformation** function before calling the
[SetNtmsObjectInformation](https://learn.microsoft.com/windows/desktop/api/ntmsapi/nf-ntmsapi-setntmsobjectinformation) function. The
**SetNtmsObjectInformation** function updates all writable members of the
[NTMS_OBJECTINFORMATION](https://learn.microsoft.com/windows/desktop/api/ntmsapi/ns-ntmsapi-ntms_objectinformationa) structure, therefore the application is responsible for providing a value for all writable members.

The following is the list of objects that require special access rights.

| Object | Access |
| --- | --- |
| NTMS_CHANGER | Requires NTMS_USE_ACCESS to the library. |
| NTMS_CHANGER_TYPE | Requires NTMS_USE_ACCESS to the computer. |
| NTMS_COMPUTER | Requires NTMS_USE_ACCESS to the computer. |
| NTMS_DRIVE | Requires NTMS_USE_ACCESS to the library. |
| NTMS_DRIVE_TYPE | Requires NTMS_USE_ACCESS to the computer. |
| NTMS_IEDOOR | Requires NTMS_USE_ACCESS to the library. |
| NTMS_IEPORT | Requires NTMS_USE_ACCESS to the library. |
| NTMS_LIBRARY | Requires NTMS_USE_ACCESS to the library. |
| NTMS_LIBREQUEST | Requires NTMS_USE_ACCESS to the library. |
| NTMS_LOGICAL_MEDIA | Requires NTMS_USE_ACCESS to the media pool of the logical media. |
| NTMS_MEDIA_TYPE | Requires NTMS_USE_ACCESS to the computer. |
| NTMS_OPREQUEST | Requires NTMS_USE_ACCESS to the computer. |
| NTMS_PARTITION | Requires NTMS_USE_ACCESS to the media pool of the side. |
| NTMS_PHYSICAL_MEDIA | Requires NTMS_USE_ACCESS to the media pool. |
| NTMS_STORAGESLOT | Requires NTMS_USE_ACCESS to the library. |

## See also

[GetNtmsObjectSecurity](https://learn.microsoft.com/windows/desktop/api/ntmsapi/nf-ntmsapi-getntmsobjectsecurity)

[NTMS_OBJECTINFORMATION](https://learn.microsoft.com/windows/desktop/api/ntmsapi/ns-ntmsapi-ntms_objectinformationa)

[Object Management Functions](https://learn.microsoft.com/previous-versions/windows/desktop/rsm/removable-storage-manager-functions)

[SetNtmsObjectInformation](https://learn.microsoft.com/windows/desktop/api/ntmsapi/nf-ntmsapi-setntmsobjectinformation)