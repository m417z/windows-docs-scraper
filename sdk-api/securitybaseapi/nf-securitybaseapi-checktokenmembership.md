# CheckTokenMembership function

## Description

The **CheckTokenMembership** function determines whether a specified [security identifier](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) (SID) is enabled in an [access token](https://learn.microsoft.com/windows/desktop/SecGloss/a-gly). If you want to determine group membership for app container tokens, you need to use the [CheckTokenMembershipEx](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-checktokenmembershipex) function.

## Parameters

### `TokenHandle` [in, optional]

A handle to an access token. The handle must have TOKEN_QUERY access to the token. The token must be an [impersonation token](https://learn.microsoft.com/windows/desktop/SecGloss/i-gly).

If *TokenHandle* is **NULL**, **CheckTokenMembership** uses the impersonation token of the calling thread. If the thread is not impersonating, the function duplicates the thread's [primary token](https://learn.microsoft.com/windows/desktop/SecGloss/p-gly) to create an [impersonation token](https://learn.microsoft.com/windows/desktop/SecGloss/i-gly).

### `SidToCheck` [in]

A pointer to a
[SID](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-sid) structure. The **CheckTokenMembership** function checks for the presence of this SID in the user and group SIDs of the access token.

### `IsMember` [out]

A pointer to a variable that receives the results of the check. If the SID is present and has the SE_GROUP_ENABLED attribute, *IsMember* returns **TRUE**; otherwise, it returns **FALSE**.

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

The **CheckTokenMembership** function simplifies the process of determining whether a SID is both present and enabled in an access token.

Even if a SID is present in the token, the system may not use the SID in an access check. The SID may be disabled or have the **SE_GROUP_USE_FOR_DENY_ONLY** attribute. The system uses only enabled SIDs to grant access when performing an access check. For more information, see
[SID Attributes in an Access Token](https://learn.microsoft.com/windows/desktop/SecAuthZ/sid-attributes-in-an-access-token).

If *TokenHandle* is a restricted token, or if *TokenHandle* is **NULL** and the current effective token of the calling thread is a restricted token, **CheckTokenMembership** also checks whether the SID is present in the list of restricting SIDs.

#### Examples

The following example shows checking a token for membership in the Administrators local group.

```cpp
BOOL IsUserAdmin(VOID)
/*++
Routine Description: This routine returns TRUE if the caller's
process is a member of the Administrators local group. Caller is NOT
expected to be impersonating anyone and is expected to be able to
open its own process and process token.
Arguments: None.
Return Value:
   TRUE - Caller has Administrators local group.
   FALSE - Caller does not have Administrators local group. --
*/
{
    BOOL b;
    SID_IDENTIFIER_AUTHORITY NtAuthority = SECURITY_NT_AUTHORITY;
    PSID AdministratorsGroup;
    b = AllocateAndInitializeSid(
        &NtAuthority,
        2,
        SECURITY_BUILTIN_DOMAIN_RID,
        DOMAIN_ALIAS_RID_ADMINS,
        0, 0, 0, 0, 0, 0,
        &AdministratorsGroup );

    if(b)
    {
        if (!CheckTokenMembership( NULL, AdministratorsGroup, &b))
        {
             b = FALSE;
        }
        FreeSid(AdministratorsGroup);
    }

    return(b);
}

```

## See also

[Access Control Overview](https://learn.microsoft.com/windows/desktop/SecAuthZ/access-control)

[AccessCheck](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-accesscheck)

[Basic Access Control Functions](https://learn.microsoft.com/windows/desktop/SecAuthZ/authorization-functions)

[CheckTokenMembershipEx](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-checktokenmembershipex)

[CreateRestrictedToken](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-createrestrictedtoken)