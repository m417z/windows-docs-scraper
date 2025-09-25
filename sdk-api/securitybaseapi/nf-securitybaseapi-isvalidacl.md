# IsValidAcl function

## Description

The **IsValidAcl** function validates an [access control list](https://learn.microsoft.com/windows/desktop/SecGloss/a-gly) (ACL).

## Parameters

### `pAcl` [in]

A pointer to an
[ACL](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-acl) structure validated by this function. This value must not be **NULL**.

## Return value

If the ACL is valid, the function returns nonzero.

If the ACL is not valid, the function returns zero. There is no extended error information for this function; do not call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

This function checks the revision level of the ACL and verifies that the number of [access control entries](https://learn.microsoft.com/windows/desktop/SecGloss/a-gly) (ACEs) specified in the **AceCount** member of the [ACL](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-acl) structure fits the space specified by the **AclSize** member of the **ACL** structure.

If *pAcl* is **NULL**, the application will fail with an access violation.

## See also

[ACL](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-acl)

[GetAclInformation](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-getaclinformation)

[InitializeAcl](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-initializeacl)

[Low-level Access Control](https://learn.microsoft.com/windows/desktop/SecAuthZ/low-level-access-control)

[Low-level Access Control Functions](https://learn.microsoft.com/windows/desktop/SecAuthZ/authorization-functions)