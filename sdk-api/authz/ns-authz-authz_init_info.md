# AUTHZ_INIT_INFO structure

## Description

The **AUTHZ_INIT_INFO** structure defines the initialization information for the resource manager.

## Members

### `version`

The version of the authorization resource manager initialization information structure. This must be set to AUTHZ_INIT_INFO_VERSION_V1 (1).

### `szResourceManagerName`

Pointer to a Unicode string that identifies the resource manager. This parameter can be **NULL** if the resource manager does not need a name.

### `pfnDynamicAccessCheck`

Pointer to an [AuthzAccessCheckCallback](https://learn.microsoft.com/windows/desktop/SecAuthZ/authzaccesscheckcallback) callback function that the resource manager calls each time it encounters a callback access control entry (ACE) during access control list (ACL) evaluation in [AuthzAccessCheck](https://learn.microsoft.com/windows/desktop/api/authz/nf-authz-authzaccesscheck) or [AuthzCachedAccessCheck](https://learn.microsoft.com/windows/desktop/api/authz/nf-authz-authzcachedaccesscheck). This parameter can be **NULL** if no access check callback function is used.

### `pfnComputeDynamicGroups`

Pointer to the [AuthzComputeGroupsCallback](https://learn.microsoft.com/windows/desktop/SecAuthZ/authzcomputegroupscallback) callback function called by the resource manager during initialization of an AuthzClientContext handle. This parameter can be **NULL** if no callback function is used to compute dynamic groups.

### `pfnFreeDynamicGroups`

Pointer to the [AuthzFreeGroupsCallback](https://learn.microsoft.com/windows/desktop/SecAuthZ/authzfreegroupscallback) callback function called by the resource manager to free security identifier (SID) attribute arrays allocated by the compute dynamic groups callback. This parameter can be **NULL** if no callback function is used to compute dynamic groups.

### `pfnGetCentralAccessPolicy`

Pointer to the [AuthzGetCentralAccessPolicyCallback](https://learn.microsoft.com/windows/desktop/SecAuthZ/authzgetcentralaccesspolicycallback-) callback function to be called by the resource manager to resolve any Central Access Policy ID ACE ([SYSTEM_SCOPED_POLICY_ID_ACE](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-system_scoped_policy_id_ace)) encountered by [AuthzAccessCheck](https://learn.microsoft.com/windows/desktop/api/authz/nf-authz-authzaccesscheck) or [AuthzCachedAccessCheck](https://learn.microsoft.com/windows/desktop/api/authz/nf-authz-authzcachedaccesscheck). If this parameter is **NULL**, the **AuthzAccessCheck** function will fall back to LSA to resolve the Central Access Policy ID ACE.

### `pfnFreeCentralAccessPolicy`

Pointer to the [AuthzFreeCentralAccessPolicyCallback](https://learn.microsoft.com/windows/desktop/SecAuthZ/authzfreecentralaccesspolicycallback) callback function called by the resource manager to free the Central Access Policy allocated by the callback to get a central access policy. This parameter can be **NULL** if no callback function is specified for pfnGetCentralAccessPolicy