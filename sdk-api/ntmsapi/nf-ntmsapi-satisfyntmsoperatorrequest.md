# SatisfyNtmsOperatorRequest function

## Description

[[Removable Storage Manager](https://learn.microsoft.com/previous-versions/windows/desktop/bb540725(v=vs.85)) is no longer available as of Windows 7 and Windows Server 2008 R2.]

The
**SatisfyNtmsOperatorRequest** function completes the specified RSM operator request.

## Parameters

### `hSession` [in]

Handle to the session returned by the
[OpenNtmsSession](https://learn.microsoft.com/windows/desktop/api/ntmsapi/nf-ntmsapi-openntmssessiona) function.

### `lpRequestId` [in]

Operator request object ID. This value is returned by
[SubmitNtmsOperatorRequest](https://learn.microsoft.com/windows/desktop/api/ntmsapi/nf-ntmsapi-submitntmsoperatorrequesta).

## Return value

This function returns one of the following values.

| Value | Meaning |
| --- | --- |
| **ERROR_ACCESS_DENIED** | The user that tried to execute this function does not have administrator privileges. Only an administrator of the RSM server can satisfy operator requests. |
| **ERROR_OBJECT_NOT_FOUND** | The operator request object ID was not found. This error occurs if the request is completed before the operation has been satisfied or when a request ID that is not valid is specified. |
| **ERROR_SUCCESS** | The operator request has been satisfied. |

## Remarks

If an application detects that the operator did not acknowledge a satisfied operator request, the application can use the
**SatisfyNtmsOperatorRequest** function to remove the request.

For a list of the existing operator requests to cancel with the
**SatisfyNtmsOperatorRequest** function, see the
[EnumerateNtmsObject](https://learn.microsoft.com/windows/desktop/api/ntmsapi/nf-ntmsapi-enumeratentmsobject) function.

## See also

[CancelNtmsOperatorRequest](https://learn.microsoft.com/windows/desktop/api/ntmsapi/nf-ntmsapi-cancelntmsoperatorrequest)

[Operator Request Functions](https://learn.microsoft.com/previous-versions/windows/desktop/rsm/removable-storage-manager-functions)

[SubmitNtmsOperatorRequest](https://learn.microsoft.com/windows/desktop/api/ntmsapi/nf-ntmsapi-submitntmsoperatorrequesta)

[WaitForNtmsOperatorRequest](https://learn.microsoft.com/windows/desktop/api/ntmsapi/nf-ntmsapi-waitforntmsoperatorrequest)