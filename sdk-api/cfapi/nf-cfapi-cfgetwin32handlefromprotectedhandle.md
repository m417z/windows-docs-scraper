# CfGetWin32HandleFromProtectedHandle function

## Description

Converts a protected handle to a Win32 handle so that it can be used with all handle-based Win32 APIs.

## Parameters

### `ProtectedHandle` [in]

The protected handle to be converted.

## Return value

The corresponding Win32 handle.

## Remarks

The caller must have referenced the protected handle prior to this call using [CfReferenceProtectedHandle](https://learn.microsoft.com/windows/win32/api/cfapi/nf-cfapi-cfreferenceprotectedhandle) to ensure that the use of the Win32 handle is tracked, and the Win32 API call that consumes the Win32 handle is synchronized with the oplock break notification acknowledgment.

The caller must release the reference on the protected handle after being done with the Win32 handle using [CfReleaseProtectedHandle](https://learn.microsoft.com/windows/win32/api/cfapi/nf-cfapi-cfreleaseprotectedhandle).

In no circumstances should the caller close the Win32 handle returned using [CfCloseHandle](https://learn.microsoft.com/windows/win32/api/cfapi/nf-cfapi-cfclosehandle).

## See also

[CfReferenceProtectedHandle](https://learn.microsoft.com/windows/win32/api/cfapi/nf-cfapi-cfreferenceprotectedhandle)

[CfReleaseProtectedHandle](https://learn.microsoft.com/windows/win32/api/cfapi/nf-cfapi-cfreleaseprotectedhandle)

[CfCloseHandle](https://learn.microsoft.com/windows/win32/api/cfapi/nf-cfapi-cfclosehandle)