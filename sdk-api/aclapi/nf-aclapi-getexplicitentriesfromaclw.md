# GetExplicitEntriesFromAclW function

## Description

The **GetExplicitEntriesFromAcl** function retrieves an array of structures that describe the [access control entries](https://learn.microsoft.com/windows/desktop/SecGloss/a-gly) (ACEs) in an [access control list](https://learn.microsoft.com/windows/desktop/SecGloss/a-gly) (ACL).

## Parameters

### `pacl` [in]

A pointer to an
[ACL](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-acl) structure from which to get
[ACE](https://learn.microsoft.com/windows/desktop/SecAuthZ/ace) information.

### `pcCountOfExplicitEntries` [out]

A pointer to a variable that receives the number of [EXPLICIT_ACCESS](https://learn.microsoft.com/windows/desktop/api/accctrl/ns-accctrl-explicit_access_a) structures returned in the *pListOfExplicitEntries* array.

### `pListOfExplicitEntries` [out]

A pointer to a variable that receives a pointer to an array of [EXPLICIT_ACCESS](https://learn.microsoft.com/windows/desktop/api/accctrl/ns-accctrl-explicit_access_a) structures that describe the ACEs in the ACL. If the function succeeds, you must call the
[LocalFree](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-localfree) function to free the returned buffer.

## Return value

If the function succeeds, the function returns ERROR_SUCCESS.

If the function fails, it returns a nonzero error code defined in WinError.h.

## Remarks

Each entry in the array of
[EXPLICIT_ACCESS](https://learn.microsoft.com/windows/desktop/api/accctrl/ns-accctrl-explicit_access_a) structures describes access control information from an
[ACE](https://learn.microsoft.com/windows/desktop/SecAuthZ/ace) for a trustee. A trustee can be a user, group, or program (such as a Windows service).

Each [EXPLICIT_ACCESS](https://learn.microsoft.com/windows/desktop/api/accctrl/ns-accctrl-explicit_access_a) structure specifies a set of access rights and an access mode flag that indicates whether the ACE allows, denies, or audits the specified rights.

For a [discretionary access control list](https://learn.microsoft.com/windows/desktop/SecGloss/d-gly) (DACL), the access mode flag can be either GRANT_ACCESS or DENY_ACCESS. For information about these values, see [ACCESS_MODE](https://learn.microsoft.com/windows/desktop/api/accctrl/ne-accctrl-access_mode).

For a [system access control list](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) (SACL), the access mode flag can be SET_AUDIT_ACCESS, SET_AUDIT_FAILURE, or both. For information about these values, see [ACCESS_MODE](https://learn.microsoft.com/windows/desktop/api/accctrl/ne-accctrl-access_mode).

> [!NOTE]
> The aclapi.h header defines GetExplicitEntriesFromAcl as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[ACCESS_ALLOWED_ACE](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-access_allowed_ace)

[ACCESS_DENIED_ACE](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-access_denied_ace)

[ACCESS_MODE](https://learn.microsoft.com/windows/desktop/api/accctrl/ne-accctrl-access_mode)

[ACE](https://learn.microsoft.com/windows/desktop/SecAuthZ/ace)

[ACL](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-acl)

[Access Control](https://learn.microsoft.com/windows/desktop/SecAuthZ/access-control)

[Basic Access Control Functions](https://learn.microsoft.com/windows/desktop/SecAuthZ/authorization-functions)

[EXPLICIT_ACCESS](https://learn.microsoft.com/windows/desktop/api/accctrl/ns-accctrl-explicit_access_a)

[LocalFree](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-localfree)

[SYSTEM_AUDIT_ACE](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-system_audit_ace)