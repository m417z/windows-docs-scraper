# DuplicateTokenEx function

## Description

The **DuplicateTokenEx** function creates a new [access token](https://learn.microsoft.com/windows/desktop/SecGloss/a-gly) that duplicates an existing token. This function can create either a [primary token](https://learn.microsoft.com/windows/desktop/SecGloss/p-gly) or an [impersonation token](https://learn.microsoft.com/windows/desktop/SecGloss/i-gly).

## Parameters

### `hExistingToken` [in]

A handle to an access token opened with TOKEN_DUPLICATE access.

### `dwDesiredAccess` [in]

Specifies the requested access rights for the new token. The **DuplicateTokenEx** function compares the requested access rights with the existing token's [discretionary access control list](https://learn.microsoft.com/windows/desktop/SecGloss/d-gly) (DACL) to determine which rights are granted or denied. To request the same access rights as the existing token, specify zero. To request all access rights that are valid for the caller, specify MAXIMUM_ALLOWED.

For a list of access rights for access tokens, see
[Access Rights for Access-Token Objects](https://learn.microsoft.com/windows/desktop/SecAuthZ/access-rights-for-access-token-objects).

### `lpTokenAttributes` [in, optional]

A pointer to a
[SECURITY_ATTRIBUTES](https://learn.microsoft.com/windows/win32/api/wtypesbase/ns-wtypesbase-security_attributes) structure that specifies a [security descriptor](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) for the new token and determines whether child processes can inherit the token. If *lpTokenAttributes* is **NULL**, the token gets a default security descriptor and the handle cannot be inherited. If the security descriptor contains a [system access control list](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) (SACL), the token gets ACCESS_SYSTEM_SECURITY access right, even if it was not requested in *dwDesiredAccess*.

To set the owner in the security descriptor for the new token, the caller's process token must have the **SE_RESTORE_NAME** privilege set.

### `ImpersonationLevel` [in]

Specifies a value from the
[SECURITY_IMPERSONATION_LEVEL](https://learn.microsoft.com/windows/desktop/api/winnt/ne-winnt-security_impersonation_level) enumeration that indicates the impersonation level of the new token.

### `TokenType` [in]

Specifies one of the following values from the [TOKEN_TYPE](https://learn.microsoft.com/windows/desktop/api/winnt/ne-winnt-token_type) enumeration.

| Value | Meaning |
| --- | --- |
| **TokenPrimary** | The new token is a [primary token](https://learn.microsoft.com/windows/desktop/SecGloss/p-gly) that you can use in the [CreateProcessAsUser](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-createprocessasusera) function. |
| **TokenImpersonation** | The new token is an impersonation token. |

### `phNewToken` [out]

A pointer to a **HANDLE** variable that receives the new token.

When you have finished using the new token, call the [CloseHandle](https://learn.microsoft.com/windows/desktop/api/handleapi/nf-handleapi-closehandle) function to close the token handle.

## Return value

If the function succeeds, the function returns a nonzero value.

If the function fails, it returns zero. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

The **DuplicateTokenEx** function allows you to create a [primary token](https://learn.microsoft.com/windows/desktop/SecGloss/p-gly) that you can use in the
[CreateProcessAsUser](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-createprocessasusera) function. This allows a server application that is impersonating a client to create a process that has the [security context](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) of the client. Note that the [DuplicateToken](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-duplicatetoken) function can create only impersonation tokens, which are not valid for **CreateProcessAsUser**.

The following is a typical scenario for using **DuplicateTokenEx** to create a [primary token](https://learn.microsoft.com/windows/desktop/SecGloss/p-gly). A server application creates a thread that calls one of the impersonation functions, such as
[ImpersonateNamedPipeClient](https://learn.microsoft.com/windows/desktop/api/namedpipeapi/nf-namedpipeapi-impersonatenamedpipeclient), to impersonate a client. The impersonating thread then calls the
[OpenThreadToken](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-openthreadtoken) function to get its own token, which is an [impersonation token](https://learn.microsoft.com/windows/desktop/SecGloss/i-gly) that has the security context of the client. The thread specifies this impersonation token in a call to **DuplicateTokenEx**, specifying the TokenPrimary flag. The **DuplicateTokenEx** function creates a *primary token* that has the security context of the client.

## See also

[Access Control](https://learn.microsoft.com/windows/desktop/SecAuthZ/access-control)

[Basic Access Control Functions](https://learn.microsoft.com/windows/desktop/SecAuthZ/authorization-functions)

[CloseHandle](https://learn.microsoft.com/windows/desktop/api/handleapi/nf-handleapi-closehandle)

[CreateProcessAsUser](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-createprocessasusera)

[DdeImpersonateClient](https://learn.microsoft.com/windows/desktop/api/ddeml/nf-ddeml-ddeimpersonateclient)

[DuplicateToken](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-duplicatetoken)

[ImpersonateNamedPipeClient](https://learn.microsoft.com/windows/desktop/api/namedpipeapi/nf-namedpipeapi-impersonatenamedpipeclient)

[OpenThreadToken](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-openthreadtoken)

[RevertToSelf](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-reverttoself)

[RpcImpersonateClient](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcimpersonateclient)

[SECURITY_ATTRIBUTES](https://learn.microsoft.com/windows/win32/api/wtypesbase/ns-wtypesbase-security_attributes)

[SECURITY_IMPERSONATION_LEVEL](https://learn.microsoft.com/windows/desktop/api/winnt/ne-winnt-security_impersonation_level)