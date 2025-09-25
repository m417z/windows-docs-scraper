# GetAclInformation function

## Description

The **GetAclInformation** function retrieves information about an [access control list](https://learn.microsoft.com/windows/desktop/SecGloss/a-gly) (ACL).

## Parameters

### `pAcl` [in]

A pointer to an
ACL. The function retrieves information about this ACL. If a null value is passed, the function causes an access violation.

### `pAclInformation` [out]

A pointer to a buffer to receive the requested information. The structure that is placed into the buffer depends on the information class requested in the *dwAclInformationClass* parameter.

### `nAclInformationLength` [in]

The size, in bytes, of the buffer pointed to by the *pAclInformation* parameter.

### `dwAclInformationClass` [in]

A value of the
[ACL_INFORMATION_CLASS](https://learn.microsoft.com/windows/desktop/api/winnt/ne-winnt-acl_information_class) enumeration that indicates the class of information requested. This parameter can be one of two values from this enumeration:

* If the value is **AclRevisionInformation**, the function fills the buffer pointed to by the *pAclInformation* parameter with an
  [ACL_REVISION_INFORMATION](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-acl_revision_information) structure.
* If the value is **AclSizeInformation**, the function fills the buffer pointed to by the *pAclInformation* parameter with an
  [ACL_SIZE_INFORMATION](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-acl_size_information) structure.

## Return value

If the function succeeds, the function returns nonzero.

If the function fails, it returns zero. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## See also

[ACL_INFORMATION_CLASS](https://learn.microsoft.com/windows/desktop/api/winnt/ne-winnt-acl_information_class)

[ACL_REVISION_INFORMATION](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-acl_revision_information)

[ACL_SIZE_INFORMATION](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-acl_size_information)

[GetAce](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-getace)

[InitializeAcl](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-initializeacl)

[IsValidAcl](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-isvalidacl)

[Low-level Access Control](https://learn.microsoft.com/windows/desktop/SecAuthZ/low-level-access-control)

[Low-level Access Control Functions](https://learn.microsoft.com/windows/desktop/SecAuthZ/authorization-functions)

[SetAclInformation](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-setaclinformation)