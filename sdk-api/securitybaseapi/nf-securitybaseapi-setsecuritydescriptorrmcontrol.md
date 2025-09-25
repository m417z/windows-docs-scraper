# SetSecurityDescriptorRMControl function

## Description

The **SetSecurityDescriptorRMControl** function sets the [resource manager](https://learn.microsoft.com/windows/desktop/SecGloss/r-gly) control bits in the
[SECURITY_DESCRIPTOR](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-security_descriptor) structure.

## Parameters

### `SecurityDescriptor` [in, out]

A pointer to a [SECURITY_DESCRIPTOR](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-security_descriptor) structure that contains the [resource manager](https://learn.microsoft.com/windows/desktop/SecGloss/r-gly) control bits.

### `RMControl` [in, optional]

A pointer to the bitfield value that the resource manager control bits in the
[SECURITY_DESCRIPTOR](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-security_descriptor) structure will be set to. If the value of this parameter is **NULL**, the resource manager control bits will be cleared.

## Return value

The return value is ERROR_SUCCESS.

## Remarks

The resource manager control bits are eight bits in the **Sbz1** member of the
[SECURITY_INFORMATION](https://learn.microsoft.com/windows/desktop/SecAuthZ/security-information) structure that contains information specific to the resource manager accessing the structure. These bits should be accessed only through the
[GetSecurityDescriptorRMControl](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-getsecuritydescriptorrmcontrol) and **SetSecurityDescriptorRMControl** functions.

## See also

[Access Control Overview](https://learn.microsoft.com/windows/desktop/SecAuthZ/access-control)

[Basic Access Control Functions](https://learn.microsoft.com/windows/desktop/SecAuthZ/authorization-functions)

[GetSecurityDescriptorRMControl](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-getsecuritydescriptorrmcontrol)

[SECURITY_DESCRIPTOR](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-security_descriptor)

[SECURITY_INFORMATION](https://learn.microsoft.com/windows/desktop/SecAuthZ/security-information)