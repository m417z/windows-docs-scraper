# AuthzAccessCheck function

## Description

The **AuthzAccessCheck** function determines which access bits can be granted to a client for a given set of [security descriptors](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly). The [AUTHZ_ACCESS_REPLY](https://learn.microsoft.com/windows/desktop/api/authz/ns-authz-authz_access_reply) structure returns an array of granted [access masks](https://learn.microsoft.com/windows/desktop/SecGloss/a-gly) and error status. Optionally, access masks that will always be granted can be cached, and a handle to cached values is returned.

## Parameters

### `Flags` [in]

A **DWORD** value that specifies how the security descriptor is copied. This parameter can be one of the following values.

Starting with Windows 8 and Windows Server 2012, when you call this function on a remote context handle, the upper 16 bits must be zero.

| Value | Meaning |
| --- | --- |
| 0 | If *phAccessCheckResults* is not **NULL**, a deep copy of the security descriptor is copied to the handle referenced by *phAccessCheckResults*. |
| **AUTHZ_ACCESS_CHECK_NO_DEEP_COPY_SD**<br><br>1 | A deep copy of the security descriptor is not performed. The calling application must pass the address of an **AUTHZ_ACCESS_CHECK_RESULTS_HANDLE** handle in *phAccessCheckResults*. The **AuthzAccessCheck** function sets this handle to a security descriptor that must remain valid during subsequent calls to [AuthzCachedAccessCheck](https://learn.microsoft.com/windows/desktop/api/authz/nf-authz-authzcachedaccesscheck). |

### `hAuthzClientContext` [in]

A handle to a structure that represents the client.

Starting with Windows 8 and Windows Server 2012, the client context can be local or remote.

### `pRequest` [in]

A pointer to an [AUTHZ_ACCESS_REQUEST](https://learn.microsoft.com/windows/desktop/api/authz/ns-authz-authz_access_request) structure that specifies the desired access mask, principal self [security identifier](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) (SID), and the object type list structure, if it exists.

### `hAuditEvent` [in, optional]

A structure that contains object-specific audit information. When the value of this parameter is not **null**, an audit is automatically requested. Static audit information is read from the resource manager structure.

Starting with Windows 8 and Windows Server 2012, when you use this function with a remote context handle, the value of the parameter must be **NULL**.

### `pSecurityDescriptor` [in]

A pointer to a
[SECURITY_DESCRIPTOR](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-security_descriptor) structure to be used for access checks. The owner SID for the object is picked from this security descriptor. A **NULL** [discretionary access control list](https://learn.microsoft.com/windows/desktop/SecGloss/d-gly) (DACL) in this security descriptor represents a **NULL** DACL for the entire object. Make sure the security descriptor contains OWNER and DACL information, or an error code 87 or "invalid parameter" message will be generated.

**Important** **NULL** DACLs permit all types of access to all users; therefore, do not use **NULL** DACLs. For information about creating a DACL, see [Creating a DACL](https://learn.microsoft.com/windows/desktop/SecBP/creating-a-dacl).

A **NULL** [system access control list](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) (SACL) in this security descriptor is treated the same way as an empty SACL.

### `OptionalSecurityDescriptorArray` [in, optional]

An array of [SECURITY_DESCRIPTOR](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-security_descriptor) structures. **NULL** [access control lists](https://learn.microsoft.com/windows/desktop/SecGloss/a-gly) (ACLs) in these security descriptors are treated as empty ACLs. The ACL for the entire object is the logical concatenation of all of the ACLs.

### `OptionalSecurityDescriptorCount` [in, optional]

The number of security descriptors not including the primary security descriptor.

### `pReply` [in, out]

A pointer to an
[AUTHZ_ACCESS_REPLY](https://learn.microsoft.com/windows/desktop/api/authz/ns-authz-authz_access_reply) structure that contains the results of the access check. Before calling the **AuthzAccessCheck** function, an application must allocate memory for the **GrantedAccessMask** and **SaclEvaluationResults** members of the **AUTHZ_ACCESS_REPLY** structure referenced by *pReply*.

### `phAccessCheckResults` [out, optional]

A pointer to return a handle to the cached results of the access check. When this parameter value is not **null**, the results of this access check call will be cached. This results in a MAXIMUM_ALLOWED check.

Starting with Windows 8 and Windows Server 2012, when you use this function with a remote context handle, the value of the parameter must be **NULL**.

## Return value

If the function succeeds, the function returns **TRUE**.

If the function fails, it returns **FALSE**. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

The [AuthzAccessCheckCallback](https://learn.microsoft.com/windows/desktop/SecAuthZ/authzaccesscheckcallback) callback function will be called if the DACL of the [SECURITY_DESCRIPTOR](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-security_descriptor) structure pointed to by the *pSecurityDescriptor* parameter contains a callback [access control entry](https://learn.microsoft.com/windows/desktop/SecGloss/a-gly) (ACE).

Security attribute variables must be present in the client context if referred to in a conditional expression, otherwise the conditional expression term referencing them will evaluate to unknown. For more information, see the [Security Descriptor Definition Language for Conditional ACEs](https://learn.microsoft.com/windows/desktop/SecAuthZ/security-descriptor-definition-language-for-conditional-aces-) topic.

For more information, see the [How AccessCheck Works](https://learn.microsoft.com/windows/desktop/SecAuthZ/how-dacls-control-access-to-an-object) and [Centralized Authorization Policy](https://learn.microsoft.com/windows/desktop/SecAuthZ/centralized-authorization-policy) overviews.

## See also

[AUTHZ_ACCESS_REPLY](https://learn.microsoft.com/windows/desktop/api/authz/ns-authz-authz_access_reply)

[AUTHZ_ACCESS_REQUEST](https://learn.microsoft.com/windows/desktop/api/authz/ns-authz-authz_access_request)

[AuthzCachedAccessCheck](https://learn.microsoft.com/windows/desktop/api/authz/nf-authz-authzcachedaccesscheck)

[Basic Access Control Functions](https://learn.microsoft.com/windows/desktop/SecAuthZ/authorization-functions)

[Centralized Authorization Policy](https://learn.microsoft.com/windows/desktop/SecAuthZ/centralized-authorization-policy)

[How AccessCheck Works](https://learn.microsoft.com/windows/desktop/SecAuthZ/how-dacls-control-access-to-an-object)

[SECURITY_DESCRIPTOR](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-security_descriptor)

[Security Descriptor Definition Language for Conditional ACEs](https://learn.microsoft.com/windows/desktop/SecAuthZ/security-descriptor-definition-language-for-conditional-aces-)