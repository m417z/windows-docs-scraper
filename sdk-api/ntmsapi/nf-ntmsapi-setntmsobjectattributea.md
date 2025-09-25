# SetNtmsObjectAttributeA function

## Description

[[Removable Storage Manager](https://learn.microsoft.com/previous-versions/windows/desktop/bb540725(v=vs.85)) is no longer available as of Windows 7 and Windows Server 2008 R2.]

The
**SetNtmsObjectAttribute** function creates an extended attribute (named private data) in the specified RSM object.

## Parameters

### `hSession` [in]

Handle to the session returned by the
[OpenNtmsSession](https://learn.microsoft.com/windows/desktop/api/ntmsapi/nf-ntmsapi-openntmssessiona) function.

### `lpObjectId` [in]

GUID of the RSM object for which the extended attribute is to be created.

### `dwType` [in]

RSM object type. For a list of object types, see
[NtmsObjectsTypes](https://learn.microsoft.com/windows/desktop/api/ntmsapi/ne-ntmsapi-ntmsobjectstypes).

### `lpAttributeName` [in]

Name of the extended attribute to be created.

### `lpAttributeData` [in]

User-defined data.

### `dwAttributeSize` [in]

Size of the *lpAttributeData* buffer, in bytes.

## Return value

This function returns one of the following values.

| Value | Meaning |
| --- | --- |
| **ERROR_ACCESS_DENIED** | NTMS_MODIFY_ACCESS is denied to the object or no modifications are allowed for the specified object type (see Remarks). Other security errors are also possible, but they would indicate a security subsystem error.<br><br>**Windows XP:** No access rights are required. |
| **ERROR_DATABASE_FAILURE** | The database update failed. |
| **ERROR_INVALID_HANDLE** | The value specified in the *hSession* parameter is **NULL** or is not valid. |
| **ERROR_INVALID_NAME** | The name or attribute is not valid. The NTMS_MAXATTR_NAMELEN value defines the maximum attribute name length. The length includes a **NULL**. |
| **ERROR_INVALID_PARAMETER** | The pointer is **NULL** or is not valid. |
| **ERROR_NO_DATA** | The attribute specified is greater than or equal to NTMS_MAXATTR_LENGTH. |
| **ERROR_NOT_CONNECTED** | Unable to connect to the RSM service. |
| **ERROR_OBJECT_NOT_FOUND** | The GUID is not valid. |
| **ERROR_SUCCESS** | The function was successful. |

## Remarks

The
**SetNtmsObjectAttribute** function must be executed on the specified RSM server. Because the buffer of bytes is unmarshaled between systems of different architectures, remote execution of this function can result in unpredictable results.

To delete an attribute, perform a set of the attribute with a length of zero.

The following is the list of objects that require special access rights.

| Object | Access |
| --- | --- |
| NTMS_CHANGER | Requires NTMS_MODIFY_ACCESS to the library. |
| NTMS_CHANGER_TYPE | Requires NTMS_MODIFY_ACCESS to the computer. |
| NTMS_COMPUTER | Requires NTMS_MODIFY_ACCESS to the computer. |
| NTMS_DRIVE | Requires NTMS_MODIFY_ACCESS to the library. |
| NTMS_DRIVE_TYPE | Requires NTMS_MODIFY_ACCESS to the computer. |
| NTMS_IEDOOR | Requires NTMS_MODIFY_ACCESS to the library. |
| NTMS_IEPORT | Requires NTMS_MODIFY_ACCESS to the library. |
| NTMS_LIBRARY | Requires NTMS_MODIFY_ACCESS to the library. |
| NTMS_LIBREQUEST | Requires NTMS_MODIFY_ACCESS to the library. |
| NTMS_LOGICAL_MEDIA | Requires NTMS_MODIFY_ACCESS to the media pool of the logical media. |
| NTMS_MEDIA_POOL | Requires NTMS_MODIFY_ACCESS to the media pool. |
| NTMS_MEDIA_TYPE | Requires NTMS_MODIFY_ACCESS to the computer. |
| NTMS_OPREQUEST | Requires NTMS_MODIFY_ACCESS to the computer. |
| NTMS_PARTITION | Requires NTMS_MODIFY_ACCESS to the media pool of the side. |
| NTMS_PHYSICAL_MEDIA | Requires NTMS_MODIFY_ACCESS to the media pool. |
| NTMS_STORAGESLOT | Requires NTMS_MODIFY_ACCESS to the library. |

> [!NOTE]
> The ntmsapi.h header defines SetNtmsObjectAttribute as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[EnumerateNtmsObject](https://learn.microsoft.com/windows/desktop/api/ntmsapi/nf-ntmsapi-enumeratentmsobject)

[GetNtmsObjectAttribute](https://learn.microsoft.com/windows/desktop/api/ntmsapi/nf-ntmsapi-getntmsobjectattributea)

[Object Management Functions](https://learn.microsoft.com/previous-versions/windows/desktop/rsm/removable-storage-manager-functions)