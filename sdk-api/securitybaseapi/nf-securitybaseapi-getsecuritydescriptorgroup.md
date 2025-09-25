# GetSecurityDescriptorGroup function

## Description

The **GetSecurityDescriptorGroup** function retrieves the primary group information from a [security descriptor](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly).

## Parameters

### `pSecurityDescriptor` [in]

A pointer to a
[SECURITY_DESCRIPTOR](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-security_descriptor) structure whose primary group information the function retrieves.

### `pGroup` [out]

A pointer to a pointer to a
[security identifier](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) (SID) that identifies the primary group when the function returns. If the security descriptor does not contain a primary group, the function sets the pointer pointed to by *pGroup* to **NULL** and ignores the remaining output parameter, *lpbGroupDefaulted*. If the security descriptor contains a primary group, the function sets the pointer pointed to by *pGroup* to the address of the security descriptor's group SID and provides a valid value for the variable pointed to by *lpbGroupDefaulted*.

### `lpbGroupDefaulted` [out]

A pointer to a flag that is set to the value of the SE_GROUP_DEFAULTED flag in the
[SECURITY_DESCRIPTOR_CONTROL](https://learn.microsoft.com/windows/desktop/SecAuthZ/security-descriptor-control) structure when the function returns. If the value stored in the variable pointed to by the *pGroup* parameter is **NULL**, no value is set.

## Return value

If the function succeeds, the function returns nonzero.

If the function fails, it returns zero. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## See also

[GetSecurityDescriptorControl](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-getsecuritydescriptorcontrol)

[GetSecurityDescriptorDacl](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-getsecuritydescriptordacl)

[GetSecurityDescriptorLength](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-getsecuritydescriptorlength)

[GetSecurityDescriptorOwner](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-getsecuritydescriptorowner)

[GetSecurityDescriptorSacl](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-getsecuritydescriptorsacl)

[IsValidSecurityDescriptor](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-isvalidsecuritydescriptor)

[Low-level Access Control](https://learn.microsoft.com/windows/desktop/SecAuthZ/low-level-access-control)

[Low-level Access Control Functions](https://learn.microsoft.com/windows/desktop/SecAuthZ/authorization-functions)

[SECURITY_DESCRIPTOR](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-security_descriptor)

[SECURITY_DESCRIPTOR_CONTROL](https://learn.microsoft.com/windows/desktop/SecAuthZ/security-descriptor-control)

[SetSecurityDescriptorGroup](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-setsecuritydescriptorgroup)