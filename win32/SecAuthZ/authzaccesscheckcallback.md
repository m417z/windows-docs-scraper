# AuthzAccessCheckCallback callback function

The **AuthzAccessCheckCallback** function is an application-defined function that handles callback [*access control entries*](https://learn.microsoft.com/windows/desktop/SecGloss/a-gly) (ACEs) during an access check. **AuthzAccessCheckCallback** is a placeholder for the application-defined function name. The application registers this callback by calling [**AuthzInitializeResourceManager**](https://learn.microsoft.com/windows/desktop/api/Authz/nf-authz-authzinitializeresourcemanager).

## Parameters

*hAuthzClientContext* \[in\]

A handle to a client context.

*pAce* \[in\]

A pointer to the ACE to evaluate for inclusion in the call to the [**AuthzAccessCheck**](https://learn.microsoft.com/windows/desktop/api/Authz/nf-authz-authzaccesscheck) function.

*pArgs* \[in, optional\]

Data passed in the *DynamicGroupArgs* parameter of the call to [**AuthzAccessCheck**](https://learn.microsoft.com/windows/desktop/api/Authz/nf-authz-authzaccesscheck) or [**AuthzCachedAccessCheck**](https://learn.microsoft.com/windows/desktop/api/Authz/nf-authz-authzcachedaccesscheck).

*pbAceApplicable* \[in, out\]

A pointer to a Boolean variable that receives the results of the evaluation of the logic defined by the application.

The results are **TRUE** if the logic determines that the ACE is applicable and will be included in the call to [**AuthzAccessCheck**](https://learn.microsoft.com/windows/desktop/api/Authz/nf-authz-authzaccesscheck); otherwise, the results are **FALSE**.

## Return value

If the function succeeds, the function returns **TRUE**.

If the function is unable to perform the evaluation, it returns **FALSE**. Use [**SetLastError**](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-setlasterror) to return an error to the access check function.

## Remarks

Security attribute variables must be present in the client context if referred to in a conditional expression, otherwise the conditional expression term referencing them will evaluate to unknown.

For more information, see the [How AccessCheck Works](https://learn.microsoft.com/windows/win32/secauthz/how-dacls-control-access-to-an-object) and [Centralized Authorization Policy](https://learn.microsoft.com/windows/win32/secauthz/centralized-authorization-policy) overviews.

## Requirements

| Requirement | Value |
|-------------------------------------|------------------------------------------------------------------------|
| Minimum supported client<br> | Windows XP \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows Server 2003 \[desktop apps only\]<br> |
| Redistributable<br> | Windows Server 2003 Administration Tools Pack on Windows XP<br> |

## See also

[Basic Access Control Functions](https://learn.microsoft.com/windows/win32/secauthz/authorization-functions)

[Centralized Authorization Policy](https://learn.microsoft.com/windows/win32/secauthz/centralized-authorization-policy)

[How AccessCheck Works](https://learn.microsoft.com/windows/win32/secauthz/how-dacls-control-access-to-an-object)

[**AuthzAccessCheck**](https://learn.microsoft.com/windows/desktop/api/Authz/nf-authz-authzaccesscheck)

[**AuthzCachedAccessCheck**](https://learn.microsoft.com/windows/desktop/api/Authz/nf-authz-authzcachedaccesscheck)

[**AuthzInitializeRemoteResourceManager**](https://learn.microsoft.com/windows/desktop/api/Authz/nf-authz-authzinitializeremoteresourcemanager)

[**AuthzInitializeResourceManager**](https://learn.microsoft.com/windows/desktop/api/Authz/nf-authz-authzinitializeresourcemanager)

