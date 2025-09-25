# CloseNtmsSession function

## Description

[[Removable Storage Manager](https://learn.microsoft.com/previous-versions/windows/desktop/bb540725(v=vs.85)) is no longer available as of Windows 7 and Windows Server 2008 R2.]

The
**CloseNtmsSession** function closes the specified RSM session.

## Parameters

### `hSession` [in]

Handle to the session returned by the
[OpenNtmsSession](https://learn.microsoft.com/windows/desktop/api/ntmsapi/nf-ntmsapi-openntmssessiona) function.

## Return value

This function returns one of the following values.

| Value | Meaning |
| --- | --- |
| **ERROR_CONNECTION_UNAVAIL** | Connection to the RSM server or domain is not available. |
| **ERROR_INVALID_HANDLE** | The value specified in the *hSession* parameter is **NULL** or is not a valid session handle. |

## Remarks

The
**CloseNtmsSession** function releases all resources. Use of a closed session handle returns an error code.

If a call to the
**CloseNtmsSession** function occurs while an application has an outstanding synchronous request (for example, a mount or dismount request), the request is unwound and canceled.

## See also

[OpenNtmsSession](https://learn.microsoft.com/windows/desktop/api/ntmsapi/nf-ntmsapi-openntmssessiona)

[Session Management Functions](https://learn.microsoft.com/previous-versions/windows/desktop/rsm/removable-storage-manager-functions)