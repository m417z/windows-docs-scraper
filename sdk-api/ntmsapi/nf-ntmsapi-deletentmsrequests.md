# DeleteNtmsRequests function

## Description

[[Removable Storage Manager](https://learn.microsoft.com/previous-versions/windows/desktop/bb540725(v=vs.85)) is no longer available as of Windows 7 and Windows Server 2008 R2.]

The
**DeleteNtmsRequests** function deletes a request or a list of requests from the RSM database. Library or operator requests that are in a completed, failed, refused, or canceled state are removed. Submitted requests, queued requests, waiting requests, and in progress requests cannot be deleted.

## Parameters

### `hSession` [in]

Handle to the session returned by the
[OpenNtmsSession](https://learn.microsoft.com/windows/desktop/api/ntmsapi/nf-ntmsapi-openntmssessiona) function.

### `lpRequestId` [in]

List of identifiers of the library and operator requests to be deleted.

### `dwType` [in]

Request type. This parameter can be one of the following values.

| Value | Meaning |
| --- | --- |
| **NTMS_LIBREQUEST** | Library request. |
| **NTMS_OPREQUEST** | Operator request. |

### `dwCount` [in]

Number of requests in the list.

## Return value

This function returns one of the following values.

| Value | Meaning |
| --- | --- |
| **ERROR_ACCESS_DENIED** | NTMS_MODIFY_ACCESS to the computer is denied. Other security errors are also possible, but they would indicate a security subsystem error.<br><br>**Windows XP:** NTMS_CONTROL_ACCESS to the computer is denied. Other security errors are also possible, but they would indicate a security subsystem error. |
| **ERROR_DATABASE_FAILURE** | Database is inaccessible or damaged. |
| **ERROR_DATABASE_FULL** | Database is full. |
| **ERROR_INVALID_PARAMETER** | The type identifier is not valid. |
| **ERROR_INVALID_HANDLE** | The session handle is missing or is not valid. |
| **ERROR_NOT_ENOUGH_MEMORY** | Memory allocation failure during processing. |
| **ERROR_SUCCESS** | The function executed successfully. |

## Remarks

An error is not returned if a request or list of requests is not found.

## See also

[Library Control Functions](https://learn.microsoft.com/previous-versions/windows/desktop/rsm/removable-storage-manager-functions)