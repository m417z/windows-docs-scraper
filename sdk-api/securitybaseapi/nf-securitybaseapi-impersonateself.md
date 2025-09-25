# ImpersonateSelf function

## Description

The **ImpersonateSelf** function obtains an [access token](https://learn.microsoft.com/windows/desktop/SecGloss/a-gly) that impersonates the [security context](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) of the calling [process](https://learn.microsoft.com/windows/desktop/SecGloss/p-gly). The token is assigned to the calling thread.

## Parameters

### `ImpersonationLevel` [in]

Specifies a
[SECURITY_IMPERSONATION_LEVEL](https://learn.microsoft.com/windows/desktop/api/winnt/ne-winnt-security_impersonation_level) enumerated type that supplies the impersonation level of the new token.

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

The **ImpersonateSelf** function is used for tasks such as enabling a [privilege](https://learn.microsoft.com/windows/desktop/SecGloss/p-gly) for a single thread rather than for the entire process or for changing the default [discretionary access control list](https://learn.microsoft.com/windows/desktop/SecGloss/d-gly) (DACL) for a single thread.

The server can call the
[RevertToSelf](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-reverttoself) function when the impersonation is complete.

For this function to succeed, the DACL protecting the process token must grant the TOKEN_DUPLICATE right to itself.

## See also

[Client/Server Access Control Functions](https://learn.microsoft.com/windows/desktop/SecAuthZ/authorization-functions)

[Client/Server Access Control Overview](https://learn.microsoft.com/windows/desktop/SecAuthZ/client-server-access-control)

[DuplicateToken](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-duplicatetoken)

[ImpersonateNamedPipeClient](https://learn.microsoft.com/windows/desktop/api/namedpipeapi/nf-namedpipeapi-impersonatenamedpipeclient)

[RevertToSelf](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-reverttoself)

[SECURITY_IMPERSONATION_LEVEL](https://learn.microsoft.com/windows/desktop/api/winnt/ne-winnt-security_impersonation_level)