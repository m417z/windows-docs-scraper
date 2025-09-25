# WaitForNtmsOperatorRequest function

## Description

[[Removable Storage Manager](https://learn.microsoft.com/previous-versions/windows/desktop/bb540725(v=vs.85)) is no longer available as of Windows 7 and Windows Server 2008 R2.]

The
**WaitForNtmsOperatorRequest** function waits for the specified RSM operator request.

## Parameters

### `hSession` [in]

Handle to the session returned by the
[OpenNtmsSession](https://learn.microsoft.com/windows/desktop/api/ntmsapi/nf-ntmsapi-openntmssessiona) function.

### `lpRequestId` [in]

Operator request identifier created by the
[SubmitNtmsOperatorRequest](https://learn.microsoft.com/windows/desktop/api/ntmsapi/nf-ntmsapi-submitntmsoperatorrequesta) function.

### `dwTimeout` [in]

Number of milliseconds to wait. To check for an operator request, pass a time-out value of zero. If you specify a value of INFINITE, this function does not time-out.

## Return value

This function returns one of the following values.

| Value | Meaning |
| --- | --- |
| **ERROR_CANCELLED** | The operator request was canceled by an administrator. |
| **ERROR_INVALID_HANDLE** | The value specified in the *hSession* parameter is **NULL** or is not valid. |
| **ERROR_INVALID_PARAMETER** | One of the parameter values is not valid. |
| **ERROR_NOT_CONNECTED** | Unable to connect to the RSM service. |
| **ERROR_OBJECT_NOT_FOUND** | Unable to find the operator request object. Object requests are flushed from the database. Application should call a function like [AllocateNtmsMedia](https://learn.microsoft.com/previous-versions/windows/desktop/rsm/media) if RSM returns this error. |
| **ERROR_SUCCESS** | The function was successful. |
| **ERROR_TIMEOUT** | The time specified in the *dwTimeout* parameter elapsed before the completion of the operator request. |

## Remarks

Operator requests specified with the
**WaitForNtmsOperatorRequest** function are used to request media, to request that the medium be moved from one library to another, or to request RSM device service.

An application uses
**WaitForNtmsOperatorRequest** to wait for resolution of an operator request. The request can be satisfied, rejected, deleted, or timed out.

Typically, applications use the
[SubmitNtmsOperatorRequest](https://learn.microsoft.com/windows/desktop/api/ntmsapi/nf-ntmsapi-submitntmsoperatorrequesta) function to submit operator requests and use the
**WaitForNtmsOperatorRequest** function to wait for their resolution.

## See also

[CancelNtmsOperatorRequest](https://learn.microsoft.com/windows/desktop/api/ntmsapi/nf-ntmsapi-cancelntmsoperatorrequest)

[Operator Request Functions](https://learn.microsoft.com/previous-versions/windows/desktop/rsm/removable-storage-manager-functions)

[SatisfyNtmsOperatorRequest](https://learn.microsoft.com/windows/desktop/api/ntmsapi/nf-ntmsapi-satisfyntmsoperatorrequest)

[SubmitNtmsOperatorRequest](https://learn.microsoft.com/windows/desktop/api/ntmsapi/nf-ntmsapi-submitntmsoperatorrequesta)