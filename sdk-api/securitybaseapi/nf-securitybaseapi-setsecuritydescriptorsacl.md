# SetSecurityDescriptorSacl function

## Description

The **SetSecurityDescriptorSacl** function sets information in a [system access control list](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) (SACL). If there is already a SACL present in the [security descriptor](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly), it is replaced.

## Parameters

### `pSecurityDescriptor` [in, out]

A pointer to the
[SECURITY_DESCRIPTOR](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-security_descriptor) structure to which the function adds the SACL. This security descriptor must be in absolute format, meaning that its members must be pointers to other structures, rather than offsets to contiguous data.

### `bSaclPresent` [in]

Indicates the presence of a SACL in the security descriptor. If this parameter is **TRUE**, the function sets the SE_SACL_PRESENT flag in the
[SECURITY_DESCRIPTOR_CONTROL](https://learn.microsoft.com/windows/desktop/SecAuthZ/security-descriptor-control) structure and uses the values in the *pSacl* and *bSaclDefaulted* parameters. If it is **FALSE**, the function does not set the SE_SACL_PRESENT flag, and *pSacl* and *bSaclDefaulted* are ignored.

### `pSacl` [in, optional]

A pointer to an
[ACL](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-acl) structure that specifies the SACL for the security descriptor. If this parameter is **NULL**, a **NULL** SACL is assigned to the security descriptor. The SACL is referenced by, not copied into, the security descriptor.

### `bSaclDefaulted` [in]

Indicates the source of the SACL. If this flag is **TRUE**, the SACL has been retrieved by some default mechanism. If it is **FALSE**, the SACL has been explicitly specified by a user. The function stores this value in the SE_SACL_DEFAULTED flag of the [SECURITY_DESCRIPTOR_CONTROL](https://learn.microsoft.com/windows/desktop/SecAuthZ/security-descriptor-control) structure. If this parameter is not specified, the SE_SACL_DEFAULTED flag is cleared.

## Return value

If the function succeeds, the function returns nonzero.

If the function fails, it returns zero. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## See also

[ACL](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-acl)

[GetSecurityDescriptorSacl](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-getsecuritydescriptorsacl)

[InitializeSecurityDescriptor](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-initializesecuritydescriptor)

[IsValidSecurityDescriptor](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-isvalidsecuritydescriptor)

[Low-level Access Control](https://learn.microsoft.com/windows/desktop/SecAuthZ/low-level-access-control)

[Low-level Access Control Functions](https://learn.microsoft.com/windows/desktop/SecAuthZ/authorization-functions)

[SECURITY_DESCRIPTOR](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-security_descriptor)

[SECURITY_DESCRIPTOR_CONTROL](https://learn.microsoft.com/windows/desktop/SecAuthZ/security-descriptor-control)

[SetSecurityDescriptorDacl](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-setsecuritydescriptordacl)

[SetSecurityDescriptorGroup](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-setsecuritydescriptorgroup)

[SetSecurityDescriptorOwner](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-setsecuritydescriptorowner)