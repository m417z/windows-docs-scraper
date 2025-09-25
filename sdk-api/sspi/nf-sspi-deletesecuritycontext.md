# DeleteSecurityContext function

## Description

The **DeleteSecurityContext** function deletes the local data structures associated with the specified [security context](https://learn.microsoft.com/windows/win32/SecGloss/s-gly) initiated by a previous call to the [InitializeSecurityContext (General)](https://learn.microsoft.com/windows/win32/api/sspi/nf-sspi-initializesecuritycontexta) function or the [AcceptSecurityContext (General)](https://learn.microsoft.com/windows/win32/api/sspi/nf-sspi-acceptsecuritycontext) function.

## Parameters

### `phContext` [in]

Handle of the security context to delete.

>[!WARNING]
> Do not use the same context handle in concurrent calls to **DeleteSecurityContext**. The API implementation in the security service providers is not thread-safe.

## Return value

If the function succeeds or the handle has already been deleted, the return value is **SEC_E_OK**.

If the function fails, the return value can be the following error code:

| Return code | Description |
|--------|--------|
| **SEC_E_INVALID_HANDLE**| The handle passed to the function is not valid. |

## Remarks

The **DeleteSecurityContext** function terminates a security context and frees associated resources.

The caller must call this function for a security context when that security context is no longer needed. This is true if the security context is partial, incomplete, rejected, or failed. After the security context is successfully deleted, further use of that security context is not permitted and the handle is no longer valid.

## See also

[AcceptSecurityContext (General)](https://learn.microsoft.com/windows/win32/api/sspi/nf-sspi-acceptsecuritycontext)

[InitializeSecurityContext (General)](https://learn.microsoft.com/windows/win32/api/sspi/nf-sspi-initializesecuritycontexta)

[SSPI Functions](https://learn.microsoft.com/windows/win32/SecAuthN/authentication-functions)