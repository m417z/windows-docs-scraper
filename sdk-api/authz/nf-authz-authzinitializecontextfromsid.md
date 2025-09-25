# AuthzInitializeContextFromSid function

## Description

The **AuthzInitializeContextFromSid** function creates a user-mode client context from a user [security identifier](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) (SID). Domain SIDs retrieve token group attributes from the Active Directory.

**Note** If possible, call the [AuthzInitializeContextFromToken](https://learn.microsoft.com/windows/desktop/api/authz/nf-authz-authzinitializecontextfromtoken) function instead of **AuthzInitializeContextFromSid**. For more information, see Remarks.

## Parameters

### `Flags` [in]

The following flags are defined.

Starting with Windows 8 and Windows Server 2012, when you call this function on a remote context handle, the upper 16 bits must be zero.

| Value | Meaning |
| --- | --- |
| 0 (0x0) | Default value.<br><br>**AuthzInitializeContextFromSid** attempts to retrieve the user's token group information by performing an S4U logon.<br><br>If S4U logon is not supported by the user's domain or the calling computer, **AuthzInitializeContextFromSid** queries the user's account object for group information. When an account is queried directly, some groups that represent logon characteristics, such as Network, Interactive, Anonymous, Network Service, or Local Service, are omitted. Applications can explicitly add such group SIDs by implementing the [AuthzComputeGroupsCallback](https://learn.microsoft.com/windows/desktop/SecAuthZ/authzcomputegroupscallback) function or calling the [AuthzAddSidsToContext](https://learn.microsoft.com/windows/desktop/api/authz/nf-authz-authzaddsidstocontext) function. |
| **AUTHZ_SKIP_TOKEN_GROUPS**<br><br>2 (0x2) | Causes **AuthzInitializeContextFromSid** to skip all group evaluations. When this flag is used, the context returned contains only the SID specified by the *UserSid* parameter. The specified SID can be an arbitrary or application-specific SID. Other SIDs can be added to this context by implementing the [AuthzComputeGroupsCallback](https://learn.microsoft.com/windows/desktop/SecAuthZ/authzcomputegroupscallback) function or by calling the [AuthzAddSidsToContext](https://learn.microsoft.com/windows/desktop/api/authz/nf-authz-authzaddsidstocontext) function. |
| **AUTHZ_REQUIRE_S4U_LOGON**<br><br>4 (0x4) | Causes **AuthzInitializeContextFromSid** to fail if Windows Services For User is not available to retrieve token group information.<br><br>**Windows XP:** This flag is not supported. |
| **AUTHZ_COMPUTE_PRIVILEGES**<br><br>8 (0x8) | Causes **AuthzInitializeContextFromSid** to retrieve privileges for the new context. If this function performs an S4U logon, it retrieves privileges from the token. Otherwise, the function retrieves privileges from all SIDs in the context. |

### `UserSid` [in]

The SID of the user for whom a client context will be created. This must be a valid user or computer account unless the AUTHZ_SKIP_TOKEN_GROUPS flag is used.

### `hAuthzResourceManager` [in, optional]

A handle to the resource manager creating this client context. This handle is stored in the client context structure.

Starting with Windows 8 and Windows Server 2012, the resource manager can be local or remote and is obtained by calling the [AuthzInitializeRemoteResourceManager](https://learn.microsoft.com/windows/desktop/api/authz/nf-authz-authzinitializeremoteresourcemanager) function.

### `pExpirationTime` [in]

Expiration date and time of the token. If no value is passed, the token never expires. Expiration time is not currently enforced.

### `Identifier` [in]

Specific identifier of the resource manager. This parameter is not currently used.

### `DynamicGroupArgs` [in, optional]

A pointer to parameters to be passed to the callback function that computes dynamic groups. This parameter can be **NULL** if no dynamic parameters are passed to the callback function.

Starting with Windows 8 and Windows Server 2012, this parameter must be **NULL** if the resource manager is remote. Otherwise, ERROR_NOT_SUPPORTED will be set.

### `phAuthzClientContext` [out]

A pointer to the handle to the client context that the **AuthzInitializeContextFromSid** function creates. When you have finished using the handle, free it by calling the [AuthzFreeContext](https://learn.microsoft.com/windows/desktop/api/authz/nf-authz-authzfreecontext) function.

## Return value

If the function succeeds, the function returns nonzero.

If the function fails, it returns zero. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

If possible, call the [AuthzInitializeContextFromToken](https://learn.microsoft.com/windows/desktop/api/authz/nf-authz-authzinitializecontextfromtoken) function instead of **AuthzInitializeContextFromSid**. **AuthzInitializeContextFromSid** attempts to retrieve the information available in a logon token had the client actually logged on. An actual logon token provides more information, such as logon type and logon properties, and reflects the behavior of the authentication package used for the logon. The client context created by **AuthzInitializeContextFromToken** uses a logon token, and the resulting client context is more complete and accurate than a client context created by **AuthzInitializeContextFromSid**.

This function resolves valid user SIDs only.

**Windows XP:** This function resolves group memberships for valid user and group SIDs (unless the AUTHZ_SKIP_TOKEN_GROUPS flag is used). Support for resolving memberships of group SIDs may be altered or unavailable in subsequent versions.

This function calls the [AuthzComputeGroupsCallback](https://learn.microsoft.com/windows/desktop/SecAuthZ/authzcomputegroupscallback) callback function to add SIDs to the newly created context.

**Important** Applications should not assume that the calling context has permission to use this function. The **AuthzInitializeContextFromSid** function reads the tokenGroupsGlobalAndUniversal attribute of the SID specified in the call to determine the current user's group memberships. If the user's object is in [Active Directory](https://learn.microsoft.com/windows/desktop/AD/active-directory-domain-services), the calling context must have read access to the tokenGroupsGlobalAndUniversal attribute on the user object. When a new domain is created, the default access compatibility selection is **Permissions compatible with Windows 2000 and Windows Server 2003 operating systems**. When this option is set, the **Pre-Windows 2000 Compatible Access** group includes only the **Authenticated Users** built-in security identifiers. Therefore, applications may not have access to the tokenGroupsGlobalAndUniversal attribute; in this case, the **AuthzInitializeContextFromSid** function fails with ACCESS_DENIED. Applications that use this function should correctly handle this error and provide supporting documentation. To simplify granting accounts permission to query a user's group information, add accounts that need the ability to look up group information to the Windows Authorization Access Group.

## See also

[Allowing Anonymous Access](https://learn.microsoft.com/windows/desktop/SecAuthZ/allowing-anonymous-access)

[AuthzFreeContext](https://learn.microsoft.com/windows/desktop/api/authz/nf-authz-authzfreecontext)

[Basic Access Control Functions](https://learn.microsoft.com/windows/desktop/SecAuthZ/authorization-functions)