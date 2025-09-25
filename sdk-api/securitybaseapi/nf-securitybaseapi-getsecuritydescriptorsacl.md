# GetSecurityDescriptorSacl function

## Description

The **GetSecurityDescriptorSacl** function retrieves a pointer to the [system access control list](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) (SACL) in a specified [security descriptor](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly).

## Parameters

### `pSecurityDescriptor` [in]

A pointer to the
[SECURITY_DESCRIPTOR](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-security_descriptor) structure that contains the SACL to which the function retrieves a pointer.

### `lpbSaclPresent` [out]

A pointer to a flag the function sets to indicate the presence of a SACL in the specified security descriptor. If this parameter is **TRUE**, the security descriptor contains a SACL, and the remaining output parameters in this function receive valid values. If this parameter is **FALSE**, the security descriptor does not contain a SACL, and the remaining output parameters do not receive valid values.

### `pSacl` [out]

A pointer to a pointer to an
[access control list](https://learn.microsoft.com/windows/desktop/SecGloss/a-gly) (ACL). If a SACL exists, the function sets the pointer pointed to by *pSacl* to the address of the security descriptor's SACL. If a SACL does not exist, no value is stored.

If the function stores a **NULL** value in the pointer pointed to by *pSacl*, the security descriptor has a **NULL** SACL.

### `lpbSaclDefaulted` [out]

A pointer to a flag that is set to the value of the SE_SACL_DEFAULTED flag in the
[SECURITY_DESCRIPTOR_CONTROL](https://learn.microsoft.com/windows/desktop/SecAuthZ/security-descriptor-control) structure if a SACL exists for the security descriptor.

## Return value

If the function succeeds, the function returns nonzero.

If the function fails, it returns zero. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## See also

[GetSecurityDescriptorControl](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-getsecuritydescriptorcontrol)

[GetSecurityDescriptorDacl](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-getsecuritydescriptordacl)

[GetSecurityDescriptorGroup](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-getsecuritydescriptorgroup)

[GetSecurityDescriptorLength](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-getsecuritydescriptorlength)

[GetSecurityDescriptorOwner](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-getsecuritydescriptorowner)

[InitializeSecurityDescriptor](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-initializesecuritydescriptor)

[IsValidSecurityDescriptor](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-isvalidsecuritydescriptor)

[Low-level Access Control](https://learn.microsoft.com/windows/desktop/SecAuthZ/low-level-access-control)

[Low-level Access Control Functions](https://learn.microsoft.com/windows/desktop/SecAuthZ/authorization-functions)

[SECURITY_DESCRIPTOR](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-security_descriptor)

[SECURITY_DESCRIPTOR_CONTROL](https://learn.microsoft.com/windows/desktop/SecAuthZ/security-descriptor-control)

[SetSecurityDescriptorSacl](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-setsecuritydescriptorsacl)