# IAzApplication::InitializeClientContextFromStringSid

## Description

The **InitializeClientContextFromStringSid** method gets an [IAzClientContext](https://learn.microsoft.com/windows/desktop/api/azroles/nn-azroles-iazclientcontext) object pointer from the specified [security identifier](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) (SID) in text form.

**Note** If possible, call the [InitializeClientContextFromToken](https://learn.microsoft.com/windows/desktop/api/azroles/nf-azroles-iazapplication-initializeclientcontextfromtoken) function instead of **InitializeClientContextFromStringSid**. For more information, see Remarks.

## Parameters

### `SidString` [in]

A string that contains the text form of the SID of the security principal. This must be a valid string SID that can be converted by the [ConvertStringSidToSid](https://learn.microsoft.com/windows/desktop/api/sddl/nf-sddl-convertstringsidtosida) function.

### `lOptions` [in]

Options for the context creation.

If AZ_CLIENT_CONTEXT_SKIP_GROUP is specified, the SID specified in the *SidString* parameter is not necessarily a valid user account. The SID will be used to create the context without validation. The created context will be flagged as having been created from a SID, the SID string will be stored in the client name field, and the domain name field will be empty. Token groups will not be used in the client context creation. [Lightweight Directory Access Protocol](https://learn.microsoft.com/windows/desktop/SecGloss/l-gly) (LDAP) query groups are not supported when AZ_CLIENT_CONTEXT_SKIP_GROUP is specified. Because the account is not validated in Active Directory, the client context's user information properties, such as [UserSamCompat](https://learn.microsoft.com/windows/desktop/api/azroles/nf-azroles-iazclientcontext-get_usersamcompat), will not be valid, and when accessed, they will return ERROR_INVALID_HANDLE. The [RoleForAccessCheck](https://learn.microsoft.com/windows/desktop/api/azroles/nf-azroles-iazclientcontext-get_roleforaccesscheck) property and the [AccessCheck](https://learn.microsoft.com/windows/desktop/api/azroles/nf-azroles-iazclientcontext-accesscheck) method of [IAzClientContext](https://learn.microsoft.com/windows/desktop/api/azroles/nn-azroles-iazclientcontext) can still be used to specify a role for access checking. The [GetRoles](https://learn.microsoft.com/windows/desktop/api/azroles/nf-azroles-iazclientcontext-getroles) method of **IAzClientContext** can still be used to enumerate roles assigned to the context within a specific scope.

If AZ_CLIENT_CONTEXT_SKIP_GROUP is not specified, the SID must represent a valid user account.

### `varReserved` [in, optional]

Reserved for future use. This parameter can be one of the following values:

* varReserved.vt == VT_ERROR and varReserved.scode == DISP_E_PARAMNOTFOUND
* varReserved.vt == VT_EMPTY
* varReserved.vt == VT_NULL
* varReserved.vt == VT_I4 and varReserved.lVal == 0
* varReserved.vt == VT_I2 and varReserved.iVal == 0

### `ppClientContext` [out]

A pointer to a pointer to the returned [IAzClientContext](https://learn.microsoft.com/windows/desktop/api/azroles/nn-azroles-iazclientcontext) object.

## Return value

If the function succeeds, the function returns S_OK.

If the function fails, it returns an **HRESULT** value that indicates the error. For a list of common error codes, see [Common HRESULT Values](https://learn.microsoft.com/windows/desktop/SecCrypto/common-hresult-values).

## Remarks

If possible, call the [InitializeClientContextFromToken](https://learn.microsoft.com/windows/desktop/api/azroles/nf-azroles-iazapplication-initializeclientcontextfromtoken) function instead of **InitializeClientContextFromStringSid**. **InitializeClientContextFromStringSid** attempts to retrieve the information available in a logon token had the client actually logged on. An actual logon token provides more information, such as logon type and logon properties, and reflects the behavior of the authentication package used for the logon. The client context created by **InitializeClientContextFromToken** uses a logon token, and the resulting client context is more complete and accurate than a client context created by **InitializeClientContextFromStringSid**.

**Important** Applications should not assume that the calling context has permission to use this function. The [AuthzInitializeContextFromSid](https://learn.microsoft.com/windows/desktop/api/authz/nf-authz-authzinitializecontextfromsid) function reads the tokenGroupsGlobalAndUniversal attribute of the SID specified in the call to determine the current user's group memberships. If the user's object is in [Active Directory](https://learn.microsoft.com/windows/desktop/AD/active-directory-domain-services), the calling context must have read access to the tokenGroupsGlobalAndUniversal attribute on the user object. Read access to the tokenGroupsGlobalAndUniversal attribute is granted to the **Pre-Windows 2000 Compatible Access** group, but new domains contain an empty **Pre-Windows 2000 Compatible Access** group by default because the default setup selection is **Permissions compatible with Windows 2000 and Windows Server 2003**. Therefore, applications may not have access to the tokenGroupsGlobalAndUniversal attribute; in this case, the **AuthzInitializeContextFromSid** function fails with ACCESS_DENIED. Applications that use this function should correctly handle this error and provide supporting documentation. To simplify granting accounts permission to query a user's group information, add accounts that need the ability to look up group information to the Windows Authorization Access Group.

Applications calling this function should use the fully qualified domain name or [user principal name](https://learn.microsoft.com/windows/desktop/SecGloss/u-gly) (UPN). Otherwise, this method might fail across forests if the NetBIOS domain name is used and the two domains do not have a direct trust relationship.

## See also

[Allowing Anonymous Access](https://learn.microsoft.com/windows/desktop/SecAuthZ/allowing-anonymous-access)

[IAzApplication](https://learn.microsoft.com/windows/desktop/api/azroles/nn-azroles-iazapplication)