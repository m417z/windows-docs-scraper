# MakeSelfRelativeSD function

## Description

The **MakeSelfRelativeSD** function creates a [security descriptor](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) in [self-relative](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) format by using a security descriptor in [absolute](https://learn.microsoft.com/windows/desktop/SecGloss/a-gly) format as a template.

## Parameters

### `pAbsoluteSecurityDescriptor` [in]

A pointer to a
[SECURITY_DESCRIPTOR](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-security_descriptor) structure in absolute format. The function creates a version of this security descriptor in self-relative format without modifying the original.

### `pSelfRelativeSecurityDescriptor` [out, optional]

A pointer to a buffer the function fills with a security descriptor in self-relative format.

### `lpdwBufferLength` [in, out]

A pointer to a variable specifying the size of the buffer pointed to by the *pSelfRelativeSD* parameter. If the buffer is not large enough for the security descriptor, the function fails and sets this variable to the minimum required size.

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror). Possible return codes include, but are not limited to, the following.

| Return code/value | Description |
| --- | --- |
| **ERROR_INSUFFICIENT_BUFFER**<br><br>0x7A | One or more of the buffers is too small. |

## Remarks

A security descriptor in absolute format contains pointers to the information it contains, rather than containing the information itself. A security descriptor in self-relative format contains the information in a contiguous block of memory. In a self-relative security descriptor, a
[SECURITY_DESCRIPTOR](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-security_descriptor) structure always starts the information, but the security descriptor's other components can follow the structure in any order. Instead of using memory addresses, the components of the security descriptor are identified by offsets from the beginning of the security descriptor. This format is useful when a security descriptor must be stored on a floppy disk or transmitted by means of a communications protocol.

A server that copies secured objects to various media can use the **MakeSelfRelativeSD** function to create a self-relative security descriptor from an absolute security descriptor and the
[MakeAbsoluteSD](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-makeabsolutesd) function to create an absolute security descriptor from a self-relative security descriptor.

## See also

[Low-level Access Control](https://learn.microsoft.com/windows/desktop/SecAuthZ/low-level-access-control)

[Low-level Access Control Functions](https://learn.microsoft.com/windows/desktop/SecAuthZ/authorization-functions)

[MakeAbsoluteSD](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-makeabsolutesd)

[SECURITY_DESCRIPTOR](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-security_descriptor)