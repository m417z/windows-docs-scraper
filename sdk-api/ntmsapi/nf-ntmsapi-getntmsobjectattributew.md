# GetNtmsObjectAttributeW function

## Description

[[Removable Storage Manager](https://learn.microsoft.com/previous-versions/windows/desktop/bb540725(v=vs.85)) is no longer available as of Windows 7 and Windows Server 2008 R2.]

The
**GetNtmsObjectAttribute** function retrieves the extended attribute (named private data) from the specified RSM object.

## Parameters

### `hSession` [in]

Handle to the session returned by the
[OpenNtmsSession](https://learn.microsoft.com/windows/desktop/api/ntmsapi/nf-ntmsapi-openntmssessiona) function.

### `lpObjectId` [in]

Unique identifier of the object from which to retrieve the data.

### `dwType` [in]

RSM object type. For a list of object types, see
[NtmsObjectsTypes](https://learn.microsoft.com/windows/desktop/api/ntmsapi/ne-ntmsapi-ntmsobjectstypes).

### `lpAttributeName` [in]

Name of the extended attribute whose data is to be retrieved.

### `lpAttributeData` [out]

Pointer to the buffer that receives the data.

### `lpAttributeSize` [in, out]

Size of the data buffer on input, in bytes. On output, the actual size of the data, in bytes.

## Return value

This function returns one of the following values.

| Value | Meaning |
| --- | --- |
| **ERROR_ACCESS_DENIED** | NTMS_USE_ACCESS to the object or its container is denied. Other security errors are also possible, but they would indicate a security subsystem error.<br><br>**Windows XP:** No access rights are required. |
| **ERROR_DATABASE_FAILURE** | The database query or update failed. |
| **ERROR_INSUFFICIENT_BUFFER** | The buffer size is not correctly specified. The correct size is returned in the *lpAttributeSize* parameter. |
| **ERROR_INVALID_HANDLE** | The value specified in the *hSession* parameter is **NULL** or is not valid. |
| **ERROR_INVALID_PARAMETER** | The pointer is **NULL** or is not valid. |
| **ERROR_NOT_CONNECTED** | Unable to connect to the RSM service. |
| **ERROR_OBJECT_NOT_FOUND** | The specified attribute was not found. |
| **ERROR_SUCCESS** | The function was successful. |

## Remarks

The
**GetNtmsObjectAttribute** function must be executed on the RSM server. Because the buffer of bytes is unmarshaled between systems of different architectures, remote execution of this function may result in unpredictable results.

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
| NTMS_MEDIA_POOL | Requires NTMS_USE_ACCESS to the media pool. |
| NTMS_MEDIA_TYPE | Requires NTMS_USE_ACCESS to the computer. |
| NTMS_OPREQUEST | Requires NTMS_USE_ACCESS to the computer. |
| NTMS_PARTITION | Requires NTMS_USE_ACCESS to the media pool of the side. |
| NTMS_PHYSICAL_MEDIA | Requires NTMS_USE_ACCESS to the media pool. |
| NTMS_STORAGESLOT | Requires NTMS_USE_ACCESS to the library. |

> [!NOTE]
> The ntmsapi.h header defines GetNtmsObjectAttribute as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[EnumerateNtmsObject](https://learn.microsoft.com/windows/desktop/api/ntmsapi/nf-ntmsapi-enumeratentmsobject)

[Object Management Functions](https://learn.microsoft.com/previous-versions/windows/desktop/rsm/removable-storage-manager-functions)

[SetNtmsObjectAttribute](https://learn.microsoft.com/windows/desktop/api/ntmsapi/nf-ntmsapi-setntmsobjectattributea)