# GetSecurityDescriptorLength function

## Description

The **GetSecurityDescriptorLength** function returns the length, in bytes, of a structurally valid [security descriptor](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly). The length includes the length of all associated structures.

## Parameters

### `pSecurityDescriptor` [in]

A pointer to the
[SECURITY_DESCRIPTOR](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-security_descriptor) structure whose length the function returns. The pointer is assumed to be valid.

## Return value

If the function succeeds, the function returns the length, in bytes, of the [SECURITY_DESCRIPTOR](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-security_descriptor) structure.

If the [SECURITY_DESCRIPTOR](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-security_descriptor) structure is not valid, the return value is undefined.

## Remarks

The minimum length of a security descriptor is SECURITY_DESCRIPTOR_MIN_LENGTH. A security descriptor of this length has no associated
[security identifiers](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) (SIDs) or
[access control lists](https://learn.microsoft.com/windows/desktop/SecGloss/a-gly) (ACLs).

## See also

[GetSecurityDescriptorControl](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-getsecuritydescriptorcontrol)

[GetSecurityDescriptorDacl](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-getsecuritydescriptordacl)

[GetSecurityDescriptorGroup](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-getsecuritydescriptorgroup)

[GetSecurityDescriptorOwner](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-getsecuritydescriptorowner)

[GetSecurityDescriptorSacl](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-getsecuritydescriptorsacl)

[IsValidSecurityDescriptor](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-isvalidsecuritydescriptor)

[Low-level Access Control](https://learn.microsoft.com/windows/desktop/SecAuthZ/low-level-access-control)

[Low-level Access Control Functions](https://learn.microsoft.com/windows/desktop/SecAuthZ/authorization-functions)

[SECURITY_DESCRIPTOR](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-security_descriptor)