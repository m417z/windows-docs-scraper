# CancelNtmsOperatorRequest function

## Description

[[Removable Storage Manager](https://learn.microsoft.com/previous-versions/windows/desktop/bb540725(v=vs.85)) is no longer available as of Windows 7 and Windows Server 2008 R2.]

The
**CancelNtmsOperatorRequest** function cancels the specified RSM operator request.

## Parameters

### `hSession` [in]

Handle to the session returned by the
[OpenNtmsSession](https://learn.microsoft.com/windows/desktop/api/ntmsapi/nf-ntmsapi-openntmssessiona) function.

### `lpRequestId` [in]

Unique identifier of the operator request to be canceled.

To retrieve the list of existing operator requests, use the
[EnumerateNtmsObject](https://learn.microsoft.com/windows/desktop/api/ntmsapi/nf-ntmsapi-enumeratentmsobject) function. You can also use the identifier returned by the
[SubmitNtmsOperatorRequest](https://learn.microsoft.com/windows/desktop/api/ntmsapi/nf-ntmsapi-submitntmsoperatorrequesta) function.

## Return value

This function returns one of the following values.

| Value | Meaning |
| --- | --- |
| **ERROR_ACCESS_DENIED** | The user that tried to execute this function does not have administrator privileges. Only an administrator of the RSM server can cancel operator requests. |
| **ERROR_INVALID_HANDLE** | The session handle is missing or is not valid. |
| **ERROR_INVALID_PARAMETER** | The request identifier is missing. |
| **ERROR_INVALID_STATE** | The request has already been completed or canceled. |
| **ERROR_OBJECT_NOT_FOUND** | The operator request object ID was not found. This error can occur if the request ID is not valid. |
| **ERROR_SUCCESS** | The operator request has been canceled. |

## See also

[Operator Request Functions](https://learn.microsoft.com/previous-versions/windows/desktop/rsm/removable-storage-manager-functions)

[SatisfyNtmsOperatorRequest](https://learn.microsoft.com/windows/desktop/api/ntmsapi/nf-ntmsapi-satisfyntmsoperatorrequest)

[SubmitNtmsOperatorRequest](https://learn.microsoft.com/windows/desktop/api/ntmsapi/nf-ntmsapi-submitntmsoperatorrequesta)