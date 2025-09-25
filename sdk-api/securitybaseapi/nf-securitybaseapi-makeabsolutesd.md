# MakeAbsoluteSD function

## Description

The **MakeAbsoluteSD** function creates a [security descriptor](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) in [absolute](https://learn.microsoft.com/windows/desktop/SecGloss/a-gly) format by using a security descriptor in [self-relative](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) format as a template.

## Parameters

### `pSelfRelativeSecurityDescriptor` [in]

A pointer to a
[SECURITY_DESCRIPTOR](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-security_descriptor) structure in self-relative format. The function creates an absolute-format version of this security descriptor without modifying the original security descriptor.

### `pAbsoluteSecurityDescriptor` [out, optional]

A pointer to a buffer that the function fills with the main body of an absolute-format security descriptor. This information is formatted as a [SECURITY_DESCRIPTOR](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-security_descriptor) structure.

### `lpdwAbsoluteSecurityDescriptorSize` [in, out]

A pointer to a variable that specifies the size of the buffer pointed to by the *pAbsoluteSD* parameter. If the buffer is not large enough for the security descriptor, the function fails and sets this variable to the minimum required size.

### `pDacl` [out, optional]

A pointer to a buffer the function fills with the [discretionary access control list](https://learn.microsoft.com/windows/desktop/SecGloss/d-gly) (DACL) of the absolute-format security descriptor. The main body of the absolute-format security descriptor references this pointer.

### `lpdwDaclSize` [in, out]

A pointer to a variable that specifies the size of the buffer pointed to by the *pDacl* parameter. If the buffer is not large enough for the [access control list](https://learn.microsoft.com/windows/desktop/SecGloss/a-gly) (ACL), the function fails and sets this variable to the minimum required size.

### `pSacl` [out, optional]

A pointer to a buffer the function fills with the [system access control list](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) (SACL) of the absolute-format security descriptor. The main body of the absolute-format security descriptor references this pointer.

### `lpdwSaclSize` [in, out]

A pointer to a variable that specifies the size of the buffer pointed to by the *pSacl* parameter. If the buffer is not large enough for the ACL, the function fails and sets this variable to the minimum required size.

### `pOwner` [out, optional]

A pointer to a buffer the function fills with the [security identifier](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) (SID) of the owner of the absolute-format security descriptor. The main body of the absolute-format security descriptor references this pointer.

### `lpdwOwnerSize` [in, out]

A pointer to a variable that specifies the size of the buffer pointed to by the *pOwner* parameter. If the buffer is not large enough for the SID, the function fails and sets this variable to the minimum required size.

### `pPrimaryGroup` [out, optional]

A pointer to a buffer the function fills with the SID of the absolute-format security descriptor's primary group. The main body of the absolute-format security descriptor references this pointer.

### `lpdwPrimaryGroupSize` [in, out]

A pointer to a variable that specifies the size of the buffer pointed to by the *pPrimaryGroup* parameter. If the buffer is not large enough for the SID, the function fails and sets this variable to the minimum required size.

## Return value

If the function succeeds, the function returns nonzero.

If the function fails, it returns zero. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror). Possible return codes include, but are not limited to, the following.

| Return code/value | Description |
| --- | --- |
| **ERROR_INSUFFICIENT_BUFFER**<br><br>0x7A | One or more of the buffers is too small. |

## Remarks

A security descriptor in absolute format contains pointers to the information it contains, rather than the information itself. A security descriptor in self-relative format contains the information in a contiguous block of memory. In a self-relative security descriptor, a
[SECURITY_DESCRIPTOR](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-security_descriptor) structure always starts the information, but the security descriptor's other components can follow the structure in any order. Instead of using memory addresses, the components of the self-relative security descriptor are identified by offsets from the beginning of the security descriptor. This format is useful when a security descriptor must be stored on a floppy disk or transmitted by means of a communications protocol.

A server that copies secured objects to various media can use the **MakeAbsoluteSD** function to create an absolute security descriptor from a self-relative security descriptor and the
[MakeSelfRelativeSD](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-makeselfrelativesd) function to create a self-relative security descriptor from an absolute security descriptor.

## See also

[Low-level Access Control](https://learn.microsoft.com/windows/desktop/SecAuthZ/low-level-access-control)

[Low-level Access Control Functions](https://learn.microsoft.com/windows/desktop/SecAuthZ/authorization-functions)

[MakeSelfRelativeSD](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-makeselfrelativesd)

[SECURITY_DESCRIPTOR](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-security_descriptor)