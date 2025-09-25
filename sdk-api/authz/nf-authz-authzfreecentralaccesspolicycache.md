# AuthzFreeCentralAccessPolicyCache function

## Description

The **AuthzFreeCentralAccessPolicyCache** function frees the cache maintained as a result of [AuthzCachedAccessCheck](https://learn.microsoft.com/windows/desktop/api/authz/nf-authz-authzcachedaccesscheck) evaluating the Central Access Policies (CAP) that applies for the resource.

## Return value

If the function succeeds, it returns **TRUE**.

If the function fails, it returns **FALSE**. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

For more information, see the [How AccessCheck Works](https://learn.microsoft.com/windows/desktop/SecAuthZ/how-dacls-control-access-to-an-object) and [Centralized Authorization Policy](https://learn.microsoft.com/windows/desktop/SecAuthZ/centralized-authorization-policy) overviews.

## See also

[Centralized Authorization Policy](https://learn.microsoft.com/windows/desktop/SecAuthZ/centralized-authorization-policy)

[How AccessCheck Works](https://learn.microsoft.com/windows/desktop/SecAuthZ/how-dacls-control-access-to-an-object)