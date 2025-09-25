# SetEntriesInAclW function

## Description

The **SetEntriesInAcl** function creates a new [access control list](https://learn.microsoft.com/windows/desktop/SecGloss/a-gly) (ACL) by merging new access control or audit control information into an existing
[ACL](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-acl) structure.

## Parameters

### `cCountOfExplicitEntries` [in]

The number of
[EXPLICIT_ACCESS](https://learn.microsoft.com/windows/desktop/api/accctrl/ns-accctrl-explicit_access_a) structures in the *pListOfExplicitEntries* array.

### `pListOfExplicitEntries` [in, optional]

A pointer to an array of [EXPLICIT_ACCESS](https://learn.microsoft.com/windows/desktop/api/accctrl/ns-accctrl-explicit_access_a) structures that describe the access control information to merge into the existing ACL.

### `OldAcl` [in, optional]

A pointer to the existing ACL. This parameter can be **NULL**, in which case, the function creates a new ACL based on the [EXPLICIT_ACCESS](https://learn.microsoft.com/windows/desktop/api/accctrl/ns-accctrl-explicit_access_a) entries.

### `NewAcl` [out]

A pointer to a variable that receives a pointer to the new ACL. If the function succeeds, you must call the
[LocalFree](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-localfree) function to free the returned buffer.

## Return value

If the function succeeds, the function returns ERROR_SUCCESS.

If the function fails, it returns a nonzero error code defined in WinError.h.

## Remarks

Each entry in the array of [EXPLICIT_ACCESS](https://learn.microsoft.com/windows/desktop/api/accctrl/ns-accctrl-explicit_access_a) structures specifies access control or audit control information for a specified trustee. A trustee can be a user, group, or other [security identifier](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) (SID) value, such as a [logon identifier](https://learn.microsoft.com/windows/desktop/SecGloss/l-gly) or logon type (for instance, a Windows service or batch job). You can use a name or a SID to identify a trustee.

You can use the **SetEntriesInAcl** function to modify the list of [access control entries](https://learn.microsoft.com/windows/desktop/SecGloss/a-gly) (ACEs) in a [discretionary access control list](https://learn.microsoft.com/windows/desktop/SecGloss/d-gly) (DACL) or a [system access control list](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) (SACL). Note that **SetEntriesInAcl** does not prevent you from mixing access control and audit control information in the same
[ACL](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-acl); however, the resulting ACL will contain meaningless entries.

For a DACL, the **grfAccessMode** member of the
[EXPLICIT_ACCESS](https://learn.microsoft.com/windows/desktop/api/accctrl/ns-accctrl-explicit_access_a) structure specifies whether to allow, deny, or revoke access rights for the trustee. This member can specify one of the following values:

* GRANT_ACCESS
* SET_ACCESS
* DENY_ACCESS
* REVOKE_ACCESS

For information about these values, see [ACCESS_MODE](https://learn.microsoft.com/windows/desktop/api/accctrl/ne-accctrl-access_mode).

The **SetEntriesInAcl** function places any new access-denied ACEs at the beginning of the list of ACEs for the new
[ACL](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-acl). This function places any new access-allowed ACEs just before any existing access-allowed ACEs.

For a SACL, the **grfAccessMode** member of the
[EXPLICIT_ACCESS](https://learn.microsoft.com/windows/desktop/api/accctrl/ns-accctrl-explicit_access_a) structure can specify the following values:

* REVOKE_ACCESS
* SET_AUDIT_FAILURE
* SET_AUDIT_SUCCESS

SET_AUDIT_FAILURE and SET_AUDIT_SUCCESS can be combined. For information about these values, see [ACCESS_MODE](https://learn.microsoft.com/windows/desktop/api/accctrl/ne-accctrl-access_mode).

The **SetEntriesInAcl** function places any new system-audit ACEs at the beginning of the list of ACEs for the new ACL.

#### Examples

For an example that uses this function, see [Modifying the ACLs of an Object](https://learn.microsoft.com/windows/desktop/SecAuthZ/modifying-the-acls-of-an-object-in-c--) or [Creating a Security Descriptor for a New Object](https://learn.microsoft.com/windows/desktop/SecAuthZ/creating-a-security-descriptor-for-a-new-object-in-c--) or [Taking Object Ownership](https://learn.microsoft.com/windows/desktop/SecAuthZ/taking-object-ownership-in-c--).

> [!NOTE]
> The aclapi.h header defines SetEntriesInAcl as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[ACCESS_ALLOWED_ACE](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-access_allowed_ace)

[ACCESS_DENIED_ACE](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-access_denied_ace)

[ACL](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-acl)

[Access Control](https://learn.microsoft.com/windows/desktop/SecAuthZ/access-control)

[Basic Access Control Functions](https://learn.microsoft.com/windows/desktop/SecAuthZ/authorization-functions)

[EXPLICIT_ACCESS](https://learn.microsoft.com/windows/desktop/api/accctrl/ns-accctrl-explicit_access_a)

[LocalFree](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-localfree)

[SYSTEM_AUDIT_ACE](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-system_audit_ace)