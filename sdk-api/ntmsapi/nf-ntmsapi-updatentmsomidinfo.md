# UpdateNtmsOmidInfo function

## Description

[[Removable Storage Manager](https://learn.microsoft.com/previous-versions/windows/desktop/bb540725(v=vs.85)) is no longer available as of Windows 7 and Windows Server 2008 R2.]

The
**UpdateNtmsOmidInfo** function updates the RSM database with label information immediately after writing to the newly allocated medium.

## Parameters

### `hSession` [in]

Handle to the session returned by the
[OpenNtmsSession](https://learn.microsoft.com/windows/desktop/api/ntmsapi/nf-ntmsapi-openntmssessiona) function.

### `lpMediaId` [in]

Unique identifier of a piece of logical media.

### `labelType` [in]

Label type. This parameter can be one of the following values.

| Value | Meaning |
| --- | --- |
| **NTMS_OMID_TYPE_FILESYSTEM_INFO** | The *lpBuffer* parameter contains an NTMS_FILESYSTEM_INFO structure. This flag is used for media that contain file systems. |
| **NTMS_OMID_TYPE_RAW_LABEL** | The *lpBuffer* parameter contains the raw bytes of the application label. This flag is used for media that contain application written labels. |

### `numberOfBytes` [in]

Number of bytes sent in the *lpBuffer* parameter.

### `lpBuffer` [in]

Label information. The format of this parameter depends on the value of the *labelType* parameter.

## Return value

This function returns one of the following values.

| Value | Meaning |
| --- | --- |
| **ERROR_ACCESS_DENIED** | Access to one or more RSM objects is denied. |
| **ERROR_DATABASE_FAILURE** | The database query or update failed. |
| **ERROR_INVALID_HANDLE** | The value specified in the *hSession* parameter is not valid. |
| **ERROR_INVALID_MEDIA** | Unable to retrieve the logical media definition from the database. |
| **ERROR_INVALID_PARTITION** | Unable to retrieve the side definition from the database. |
| **ERROR_INVALID_PARAMETER** | The *lpMediaId* parameter is **NULL**. |
| **ERROR_NOT_CONNECTED** | Unable to connect to the RSM service. |
| **ERROR_SUCCESS** | The function was successful. |

## Remarks

The application updates RSM with the information supplied by the
**UpdateNtmsOmidInfo** function and RSM verifies the information in the database. The label information is stored in the RSM database with the side associated with this LMID.

The
**UpdateNtmsOmidInfo** function must be executed on the RSM server. Remote execution of this function results in an error.

For tape media *lpBuffer* must point to a buffer that holds the label just written on the tape. The data in this buffer is passed directly to the ClaimMediaLabel entry point of each MLL. One of the installed MLLs must recognize a valid label in this data.

For media with file systems, *lpBuffer* must be a pointer to a buffer that contains the following structure:

``` syntax

typedef struct {
    WCHAR   FileSystemType[64];
    WCHAR   VolumeName[256];
    DWORD   SerialNumber;
} NTMS_FILESYSTEM_INFO;
```

RSM uses this file system info as the OMID. The format utilities (LDM, explorer, format.com, and so on) effectively performs the same functionality as this call. An application that performs its own formatting or formats with a third-party file system type should only need to call
**UpdateNtmsOmidInfo** for file system media.

## See also

[On-Media-Identifier Management Functions](https://learn.microsoft.com/previous-versions/windows/desktop/rsm/removable-storage-manager-functions)