# GetSecurityDescriptorRMControl function

## Description

The **GetSecurityDescriptorRMControl** function retrieves the [resource manager](https://learn.microsoft.com/windows/desktop/SecGloss/r-gly) control bits.

## Parameters

### `SecurityDescriptor` [in]

A pointer to a
[SECURITY_DESCRIPTOR](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-security_descriptor) structure that contains the [resource manager](https://learn.microsoft.com/windows/desktop/SecGloss/r-gly) control bits. The value of the **Control** member is set to SE_RM_CONTROL_VALID.

### `RMControl` [out]

A pointer to a buffer that receives the resource manager control bits.

## Return value

If the function succeeds, the return value is ERROR_SUCCESS.

If the function fails, the following value is returned.

| Return code | Description |
| --- | --- |
| **ERROR_INVALID_DATA** | The SE_RM_CONTROL_VALID bit flag is not set in the specified [SECURITY_DESCRIPTOR](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-security_descriptor) structure. |

## Remarks

The [resource manager](https://learn.microsoft.com/windows/desktop/SecGloss/r-gly) control bits are eight bits in the **Sbz1** member of the [SECURITY_DESCRIPTOR](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-security_descriptor) structure that contains information specific to the resource manager accessing the structure. These bits should be accessed only through the **GetSecurityDescriptorRMControl** and
[SetSecurityDescriptorRMControl](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-setsecuritydescriptorrmcontrol) functions.

## See also

[Access Control Overview](https://learn.microsoft.com/windows/desktop/SecAuthZ/access-control)

[Basic Access Control Functions](https://learn.microsoft.com/windows/desktop/SecAuthZ/authorization-functions)

[SECURITY_DESCRIPTOR](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-security_descriptor)

[SetSecurityDescriptorRMControl](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-setsecuritydescriptorrmcontrol)