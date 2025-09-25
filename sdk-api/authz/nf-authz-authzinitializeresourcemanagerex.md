# AuthzInitializeResourceManagerEx function

## Description

The **AuthzInitializeResourceManagerEx** function initializes an Authz resource manager and returns a handle to it. Use this function rather than [AuthzInitializeResourceManager](https://learn.microsoft.com/windows/desktop/api/authz/nf-authz-authzinitializeresourcemanager) when you want the resource manager to manage Central Access Policies (CAPs).

## Parameters

### `Flags` [in, optional]

A **DWORD** value that defines how the resource manager is initialized. This parameter can be one or more of the following values.

| Value | Meaning |
| --- | --- |
| 0 | Default call to the function. The resource manager is initialized as the principal identified in the process token, and auditing is in effect. Unless the **AUTHZ_RM_FLAG_NO_AUDIT** flag is set, **SeAuditPrivilege** must be enabled for the function to succeed. |
| **AUTHZ_RM_FLAG_NO_AUDIT**<br><br>1 | Auditing is not in effect. If this flag is set, the caller does not need to have **SeAuditPrivilege** enabled to call this function. Use this flag if the resource manager will never generate an audit for best performance. |
| **AUTHZ_RM_FLAG_INITIALIZE_UNDER_IMPERSONATION**<br><br>2 | The resource manager is initialized as the identity of the thread token. If the current thread is impersonating, then use the impersonation token as the identity of the resource manager. |
| **AUTHZ_RM_FLAG_NO_CENTRAL_ACCESS_POLICIES**<br><br>4 | The central access policy IDs are ignored. Do not evaluate central access policies. |

### `pAuthzInitInfo` [in, optional]

A pointer to a [AUTHZ_INIT_INFO](https://learn.microsoft.com/windows/desktop/api/authz/ns-authz-authz_init_info) structure that contains the authorization resource manager initialization information.

### `phAuthzResourceManager` [out]

A pointer to the returned resource manager handle. When you have finished using the handle, free it by using the [AuthzFreeResourceManager](https://learn.microsoft.com/windows/desktop/api/authz/nf-authz-authzfreeresourcemanager) function.

## Return value

If the function succeeds, the function returns a value of **TRUE**.

If the function fails, it returns a value of **FALSE**. To get extended error information, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

If the AUTHZ_RM_FLAG_NO_CENTRAL_ACCESS_POLICIES flag is specified, then [AuthzAccessCheck](https://learn.microsoft.com/windows/desktop/api/authz/nf-authz-authzaccesscheck) and [AuthzCachedAccessCheck](https://learn.microsoft.com/windows/desktop/api/authz/nf-authz-authzcachedaccesscheck) ignore CAPID (Central Access Policie ID) [access control entries](https://learn.microsoft.com/windows/desktop/SecGloss/a-gly)[SYSTEM_SCOPED_POLICY_ID_ACE](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-system_scoped_policy_id_ace) and will not evaluate CAPs.

If the AUTHZ_RM_FLAG_NO_CENTRAL_ACCESS_POLICIES flag is not specified and pfnGetCentralAccessPolicy is **NULL**, then [AuthzAccessCheck](https://learn.microsoft.com/windows/desktop/api/authz/nf-authz-authzaccesscheck) and [AuthzCachedAccessCheck](https://learn.microsoft.com/windows/desktop/api/authz/nf-authz-authzcachedaccesscheck) will get CAPs from LSA. For more information, see [LsaGetAppliedCAPIDs](https://learn.microsoft.com/windows/desktop/api/ntlsa/nf-ntlsa-lsagetappliedcapids).

If the AUTHZ_RM_FLAG_NO_CENTRAL_ACCESS_POLICIES flag is not specified and a central access policy callback is provided by the resource manager, then [AuthzAccessCheck](https://learn.microsoft.com/windows/desktop/api/authz/nf-authz-authzaccesscheck) and [AuthzCachedAccessCheck](https://learn.microsoft.com/windows/desktop/api/authz/nf-authz-authzcachedaccesscheck) will get CAPs from the resource manager by invoking the callback.

The LSA and the central access policy callback can indicate that CAPs are not supported, in which case [AuthzAccessCheck](https://learn.microsoft.com/windows/desktop/api/authz/nf-authz-authzaccesscheck) and [AuthzCachedAccessCheck](https://learn.microsoft.com/windows/desktop/api/authz/nf-authz-authzcachedaccesscheck) ignore CAPID ACEs and will not evaluate CAPs.

The LSA and the central access policy callback may fail to return a CAP that corresponds to a particular CAPID, in which case **AuthzAccessCheck** and **AuthzCachedAccessCheck** use the same default CAP as the kernel AccessCheck.

## See also

[LsaGetAppliedCAPIDs](https://learn.microsoft.com/windows/desktop/api/ntlsa/nf-ntlsa-lsagetappliedcapids)