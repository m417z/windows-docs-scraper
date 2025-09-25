# SetSecurityDescriptorGroup function

## Description

The **SetSecurityDescriptorGroup** function sets the primary group information of an absolute-format [security descriptor](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly), replacing any primary group information already present in the security descriptor.

## Parameters

### `pSecurityDescriptor` [in, out]

A pointer to the
[SECURITY_DESCRIPTOR](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-security_descriptor) structure whose primary group is set by this function. The function replaces any existing primary group with the new primary group.

### `pGroup` [in, optional]

A pointer to a
[SID](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-sid) structure for the security descriptor's new primary group. The **SID** structure is referenced by, not copied into, the security descriptor. If this parameter is **NULL**, the function clears the security descriptor's primary group information. This marks the security descriptor as having no primary group.

### `bGroupDefaulted` [in]

Indicates whether the primary group information was derived from a default mechanism. If this value is **TRUE**, it is default information, and the function stores this value as the SE_GROUP_DEFAULTED flag in the
[SECURITY_DESCRIPTOR_CONTROL](https://learn.microsoft.com/windows/desktop/SecAuthZ/security-descriptor-control) structure. If this parameter is zero, the SE_GROUP_DEFAULTED flag is cleared.

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## See also

[GetSecurityDescriptorGroup](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-getsecuritydescriptorgroup)

[InitializeSecurityDescriptor](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-initializesecuritydescriptor)

[Low-level Access Control](https://learn.microsoft.com/windows/desktop/SecAuthZ/low-level-access-control)

[Low-level Access Control Functions](https://learn.microsoft.com/windows/desktop/SecAuthZ/authorization-functions)

[SECURITY_DESCRIPTOR](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-security_descriptor)

[SECURITY_DESCRIPTOR_CONTROL](https://learn.microsoft.com/windows/desktop/SecAuthZ/security-descriptor-control)

[SID](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-sid)

[SetSecurityDescriptorDacl](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-setsecuritydescriptordacl)

[SetSecurityDescriptorOwner](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-setsecuritydescriptorowner)

[SetSecurityDescriptorSacl](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-setsecuritydescriptorsacl)