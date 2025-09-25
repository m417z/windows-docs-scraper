# AuthzInitializeResourceManager function

## Description

The **AuthzInitializeResourceManager** function uses Authz to verify that clients have access to various resources.

## Parameters

### `Flags` [in]

A **DWORD** value that defines how the resource manager is initialized. This parameter can contain the following values.

| Value | Meaning |
| --- | --- |
| 0 | Default call to the function. The resource manager is initialized as the principal identified in the process token, and auditing is in effect. Note that unless the **AUTHZ_RM_FLAG_NO_AUDIT** flag is set, **SeAuditPrivilege** must be enabled for the function to succeed. |
| **AUTHZ_RM_FLAG_NO_AUDIT** | Auditing is not in effect. If this flag is set, the caller does not need to have **SeAuditPrivilege** enabled to call this function. |
| **AUTHZ_RM_FLAG_INITIALIZE_UNDER_IMPERSONATION** | The resource manager is initialized as the identity of the thread token. |
| **AUTHZ_RM_FLAG_NO_CENTRAL_ACCESS_POLICIES** | The resource manager ignores CAP IDs and does not evaluate centralized access policies. |

AUTHZ_RM_FLAG_NO_AUDIT and AUTHZ_RM_FLAG_INITIALIZE_UNDER_IMPERSONATION can be bitwise-combined.

### `pfnDynamicAccessCheck` [in, optional]

A pointer to the [AuthzAccessCheckCallback](https://learn.microsoft.com/windows/desktop/SecAuthZ/authzaccesscheckcallback) callback function that the resource manager calls each time it encounters a callback
[access control entry](https://learn.microsoft.com/windows/desktop/SecGloss/a-gly) (ACE) during [access control list](https://learn.microsoft.com/windows/desktop/SecGloss/a-gly) (ACL) evaluation in
[AuthzAccessCheck](https://learn.microsoft.com/windows/desktop/api/authz/nf-authz-authzaccesscheck) or
[AuthzCachedAccessCheck](https://learn.microsoft.com/windows/desktop/api/authz/nf-authz-authzcachedaccesscheck). This parameter can be **NULL** if no access check callback function is used.

### `pfnComputeDynamicGroups` [in, optional]

A pointer to the [AuthzComputeGroupsCallback](https://learn.microsoft.com/windows/desktop/SecAuthZ/authzcomputegroupscallback) callback function called by the resource manager during initialization of an *AuthzClientContext* handle. This parameter can be **NULL** if no callback function is used to compute dynamic groups.

### `pfnFreeDynamicGroups` [in, optional]

A pointer to the [AuthzFreeGroupsCallback](https://learn.microsoft.com/windows/desktop/SecAuthZ/authzfreegroupscallback) callback function called by the resource manager to free [security identifier](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) (SID) attribute arrays allocated by the compute dynamic groups callback. This parameter can be **NULL** if no callback function is used to compute dynamic groups.

### `szResourceManagerName` [in]

A string that identifies the resource manager. This parameter can be **NULL** if the resource manager does not need a name.

### `phAuthzResourceManager` [out]

A pointer to the returned resource manager handle. When you have finished using the handle, free it by calling the [AuthzFreeResourceManager](https://learn.microsoft.com/windows/desktop/api/authz/nf-authz-authzfreeresourcemanager) function.

## Return value

If the function succeeds, the function returns a nonzero value.

If the function fails, it returns a zero value. To get extended error information, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## See also

[AuthzAccessCheck](https://learn.microsoft.com/windows/desktop/api/authz/nf-authz-authzaccesscheck)

[AuthzCachedAccessCheck](https://learn.microsoft.com/windows/desktop/api/authz/nf-authz-authzcachedaccesscheck)

[AuthzFreeResourceManager](https://learn.microsoft.com/windows/desktop/api/authz/nf-authz-authzfreeresourcemanager)

[Basic Access Control Functions](https://learn.microsoft.com/windows/desktop/SecAuthZ/authorization-functions)