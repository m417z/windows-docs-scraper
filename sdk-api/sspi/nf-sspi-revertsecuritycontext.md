# RevertSecurityContext function

## Description

Allows a [security package](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) to discontinue the impersonation of the caller and restore its own [security context](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly).

## Parameters

### `phContext` [in]

Handle of the [security context](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) being impersonated. This handle must have been obtained in the call to the
[AcceptSecurityContext (General)](https://learn.microsoft.com/windows/desktop/api/sspi/nf-sspi-acceptsecuritycontext) function and used in the call to the
[ImpersonateSecurityContext](https://learn.microsoft.com/windows/desktop/api/sspi/nf-sspi-impersonatesecuritycontext) function.

## Return value

If the function succeeds, the return value is SEC_E_OK.

If the function fails, the return value can be one of the following error codes.

| Return code | Description |
| --- | --- |
| **SEC_E_INVALID_HANDLE** | The handle passed to the function is not valid. |

## Remarks

**RevertSecurityContext** is not available with all [security packages](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) on all platforms. Typically, it is implemented only on platforms and with security packages for which a call to the
[QuerySecurityPackageInfo](https://learn.microsoft.com/windows/desktop/api/sspi/nf-sspi-querysecuritypackageinfoa) function indicates impersonation support.

## See also

[AcceptSecurityContext (General)](https://learn.microsoft.com/windows/desktop/api/sspi/nf-sspi-acceptsecuritycontext)

[ImpersonateSecurityContext](https://learn.microsoft.com/windows/desktop/api/sspi/nf-sspi-impersonatesecuritycontext)

[SSPI Functions](https://learn.microsoft.com/windows/desktop/SecAuthN/authentication-functions)