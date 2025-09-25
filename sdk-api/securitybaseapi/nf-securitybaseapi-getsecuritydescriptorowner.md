# GetSecurityDescriptorOwner function

## Description

The **GetSecurityDescriptorOwner** function retrieves the owner information from a [security descriptor](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly).

## Parameters

### `pSecurityDescriptor` [in]

A pointer to a
[SECURITY_DESCRIPTOR](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-security_descriptor) structure whose owner information the function retrieves.

### `pOwner` [out]

A pointer to a pointer to a
[security identifier](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) (SID) that identifies the owner when the function returns. If the security descriptor does not contain an owner, the function sets the pointer pointed to by *pOwner* to **NULL** and ignores the remaining output parameter, *lpbOwnerDefaulted*. If the security descriptor contains an owner, the function sets the pointer pointed to by *pOwner* to the address of the security descriptor's owner SID and provides a valid value for the variable pointed to by *lpbOwnerDefaulted*.

### `lpbOwnerDefaulted` [out]

A pointer to a flag that is set to the value of the SE_OWNER_DEFAULTED flag in the
[SECURITY_DESCRIPTOR_CONTROL](https://learn.microsoft.com/windows/desktop/SecAuthZ/security-descriptor-control) structure when the function returns. If the value stored in the variable pointed to by the *pOwner* parameter is **NULL**, no value is set.

## Return value

If the function succeeds, the function returns nonzero.

If the function fails, it returns zero. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## See also

[GetSecurityDescriptorControl](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-getsecuritydescriptorcontrol)

[GetSecurityDescriptorDacl](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-getsecuritydescriptordacl)

[GetSecurityDescriptorGroup](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-getsecuritydescriptorgroup)

[GetSecurityDescriptorLength](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-getsecuritydescriptorlength)

[GetSecurityDescriptorSacl](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-getsecuritydescriptorsacl)

[IsValidSecurityDescriptor](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-isvalidsecuritydescriptor)

[Low-level Access Control](https://learn.microsoft.com/windows/desktop/SecAuthZ/low-level-access-control)

[Low-level Access Control Functions](https://learn.microsoft.com/windows/desktop/SecAuthZ/authorization-functions)

[SECURITY_DESCRIPTOR](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-security_descriptor)

[SECURITY_DESCRIPTOR_CONTROL](https://learn.microsoft.com/windows/desktop/SecAuthZ/security-descriptor-control)

[SetSecurityDescriptorOwner](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-setsecuritydescriptorowner)