# GetAuditedPermissionsFromAclA function

## Description

The **GetAuditedPermissionsFromAcl** function retrieves the audited access rights for a specified trustee. The audited rights are based on the [access control entries](https://learn.microsoft.com/windows/desktop/SecGloss/a-gly) (ACEs) of a specified [access control list](https://learn.microsoft.com/windows/desktop/SecGloss/a-gly) (ACL). The audited access rights indicate the types of access attempts that cause the system to generate an audit record in the system event log. The audited rights include those that the
[ACL](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-acl) specifies for the trustee or for any groups of which the trustee is a member. In determining the audited rights, the function does not consider the security privileges held by the trustee.

## Parameters

### `pacl` [in]

A pointer to an
[ACL](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-acl) structure from which to get the trustee's audited access rights.

### `pTrustee` [in]

A pointer to a
[TRUSTEE](https://learn.microsoft.com/windows/desktop/api/accctrl/ns-accctrl-trustee_a) structure that identifies the trustee. A trustee can be a user, group, or program (such as a Windows service). You can use a name or a [security identifier](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) (SID) to identify a trustee. For information about SID structures, see [SID](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-sid).

### `pSuccessfulAuditedRights` [out]

A pointer to an
[ACCESS_MASK](https://learn.microsoft.com/windows/desktop/SecAuthZ/access-mask) structure that receives the successful audit mask for rights audited for the trustee specified by the *pTrustee* parameter. The system generates an audit record when the trustee successfully uses any of these access rights.

### `pFailedAuditRights` [out]

A pointer to an [ACCESS_MASK](https://learn.microsoft.com/windows/desktop/SecAuthZ/access-mask) structure that receives the failed audit mask for rights audited for the trustee specified by the *pTrustee* parameter. The system generates an audit record when the trustee fails in an attempt to use any of these rights.

## Return value

If the function succeeds, the function returns ERROR_SUCCESS.

If the function fails, it returns a nonzero error code defined in WinError.h.

## Remarks

The **GetAuditedPermissionsFromAcl** function checks all system-audit ACEs in the ACL to determine the audited rights for the trustee. For all ACEs that specify audited rights for a group, **GetAuditedPermissionsFromAcl** enumerates the members of the group to determine whether the trustee is a member. The function returns an error if it cannot enumerate the members of a group.

> [!NOTE]
> The aclapi.h header defines GetAuditedPermissionsFromAcl as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[ACCESS_MASK](https://learn.microsoft.com/windows/desktop/SecAuthZ/access-mask)

[ACE](https://learn.microsoft.com/windows/desktop/SecAuthZ/ace)

[ACL](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-acl)

[Access Control Overview](https://learn.microsoft.com/windows/desktop/SecAuthZ/access-control)

[Basic Access Control Functions](https://learn.microsoft.com/windows/desktop/SecAuthZ/authorization-functions)

[GetEffectiveRightsFromAcl](https://learn.microsoft.com/windows/desktop/api/aclapi/nf-aclapi-geteffectiverightsfromacla)

[SID](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-sid)

[SYSTEM_AUDIT_ACE](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-system_audit_ace)

[TRUSTEE](https://learn.microsoft.com/windows/desktop/api/accctrl/ns-accctrl-trustee_a)