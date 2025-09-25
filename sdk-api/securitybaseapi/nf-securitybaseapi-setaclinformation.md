# SetAclInformation function

## Description

The **SetAclInformation** function sets information about an [access control list](https://learn.microsoft.com/windows/desktop/SecGloss/a-gly) (ACL).

## Parameters

### `pAcl` [in, out]

A pointer to an
ACL. The function sets information in this ACL.

### `pAclInformation` [in]

A pointer to a buffer that contains the information to be set. This must be a pointer to an
[ACL_REVISION_INFORMATION](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-acl_revision_information) structure.

### `nAclInformationLength` [in]

The size, in bytes, of the buffer pointed to by the *pAclInfo* parameter.

### `dwAclInformationClass` [in]

An
[ACL_INFORMATION_CLASS](https://learn.microsoft.com/windows/desktop/api/winnt/ne-winnt-acl_information_class) enumerated type that gives the class of information requested.

Currently, this parameter can be **AclRevisionInformation**. This means that the buffer pointed to by the *pAclInformation* parameter contains an
[ACL_REVISION_INFORMATION](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-acl_revision_information) structure.

## Return value

If the function succeeds, the function returns nonzero.

If the function fails, it returns zero. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## See also

[ACL_INFORMATION_CLASS](https://learn.microsoft.com/windows/desktop/api/winnt/ne-winnt-acl_information_class)

[ACL_REVISION_INFORMATION](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-acl_revision_information)

[GetAclInformation](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-getaclinformation)

[InitializeAcl](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-initializeacl)

[IsValidAcl](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-isvalidacl)

[Low-level Access Control](https://learn.microsoft.com/windows/desktop/SecAuthZ/low-level-access-control)

[Low-level Access Control Functions](https://learn.microsoft.com/windows/desktop/SecAuthZ/authorization-functions)