# SecPkgContext_AccessToken structure

## Description

The **SecPkgContext_AccessToken** structure returns a handle to the access token for the current [security context](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly). The returned handle can be used by the [ImpersonateLoggedOnUser](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-impersonateloggedonuser) and [GetTokenInformation](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-gettokeninformation) functions. This structure is returned by the [QueryContextAttributes (General)](https://learn.microsoft.com/windows/desktop/api/sspi/nf-sspi-querycontextattributesa) function.

## Members

### `AccessToken`

Pointer to a **void** that receives the handle to the access token that represents the authenticated user.

The returned handle is not duplicated, so the calling process must not call [CloseHandle](https://learn.microsoft.com/windows/desktop/api/handleapi/nf-handleapi-closehandle) on the returned handle.

If the security context is for a server or is incomplete, the returned handle may be **NULL**. Depending on the security package, [QueryContextAttributes (General)](https://learn.microsoft.com/windows/desktop/api/sspi/nf-sspi-querycontextattributesa) may return SEC_E_NO_IMPERSONATION for these cases.