# AuthzCachedAccessCheck function

## Description

The **AuthzCachedAccessCheck** function performs a fast access check based on a cached handle containing the static granted bits from a previous
[AuthzAccessCheck](https://learn.microsoft.com/windows/desktop/api/authz/nf-authz-authzaccesscheck) call.

## Parameters

### `Flags` [in]

Reserved for future use.

### `hAccessCheckResults` [in]

A handle to the cached access check results.

### `pRequest` [in]

Access request handle specifying the desired [access mask](https://learn.microsoft.com/windows/desktop/SecGloss/a-gly), principal self [SID](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly), and the object type list structure (if any).

### `hAuditEvent` [in]

A structure that contains object-specific audit information. When the value of this parameter is not null, an audit is automatically requested. Static audit information is read from the resource manager structure.

### `pReply` [out]

A pointer to an
[AUTHZ_ACCESS_REPLY](https://learn.microsoft.com/windows/desktop/api/authz/ns-authz-authz_access_reply) handle that returns the results of access check as an array of GrantedAccessMask/ErrorValue pairs. The number of pairs returned is supplied by the caller in the **ResultListLength** member of the **AUTHZ_ACCESS_REPLY** structure.

## Return value

If the function succeeds, it returns **TRUE**.

If the function fails, it returns **FALSE**. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

Expected values of the Error members of array elements returned are shown in the following table.

| Return code | Description |
| --- | --- |
| **ERROR_SUCCESS** | All the access bits, not including MAXIMUM_ALLOWED, are granted and the **GrantedAccessMask** member of the *pReply* parameter is not zero. |
| **ERROR_PRIVILEGE_NOT_HELD** | The **DesiredAccess** member of the *pRequest* parameter includes ACCESS_SYSTEM_SECURITY, and the client does not have the SeSecurityPrivilege privilege. |
| **ERROR_ACCESS_DENIED** | One or more of the following is true: <br><br>* The requested bits are not granted.<br>* The MaximumAllowed bit is on, and the granted access is zero.<br>* The **DesiredAccess** member of the *pRequest* parameter is zero. |

## Remarks

The client context pointer is stored in the *AuthzHandle* parameter. The structure of the client context must be exactly the same as it was at the time *AuthzHandle* was created. This restriction is for the following fields:

* SIDs
* RestrictedSids
* Privileges

Pointers to the primary [security descriptor](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) and the optional security descriptor array are stored in *AuthzHandle* at the time of handle creation. These pointers must still be valid.

The **AuthzCachedAccessCheck** function maintains a cache as a result of evaluating Central Access Policies (CAP) on objects unless CAPs are ignored, for example when the AUTHZ_RM_FLAG_NO_CENTRAL_ACCESS_POLICIES flag is used. The client may call the [AuthzFreeCentralAccessPolicyCache](https://learn.microsoft.com/windows/desktop/api/authz/nf-authz-authzfreecentralaccesspolicycache) function to free up this cache. Note that this requires a subsequent call to **AuthzCachedAccessCheck** to rebuild the cache if necessary.

For more information, see the [How AccessCheck Works](https://learn.microsoft.com/windows/desktop/SecAuthZ/how-dacls-control-access-to-an-object) and [Centralized Authorization Policy](https://learn.microsoft.com/windows/desktop/SecAuthZ/centralized-authorization-policy) overviews.

## See also

[AUTHZ_ACCESS_REPLY](https://learn.microsoft.com/windows/desktop/api/authz/ns-authz-authz_access_reply)

[AuthzAccessCheck](https://learn.microsoft.com/windows/desktop/api/authz/nf-authz-authzaccesscheck)

[AuthzFreeCentralAccessPolicyCache](https://learn.microsoft.com/windows/desktop/api/authz/nf-authz-authzfreecentralaccesspolicycache)

[AuthzInitializeResourceManager](https://learn.microsoft.com/windows/desktop/api/authz/nf-authz-authzinitializeresourcemanager)

[Basic Access Control Functions](https://learn.microsoft.com/windows/desktop/SecAuthZ/authorization-functions)

[Centralized Authorization Policy](https://learn.microsoft.com/windows/desktop/SecAuthZ/centralized-authorization-policy)

[How AccessCheck Works](https://learn.microsoft.com/windows/desktop/SecAuthZ/how-dacls-control-access-to-an-object)