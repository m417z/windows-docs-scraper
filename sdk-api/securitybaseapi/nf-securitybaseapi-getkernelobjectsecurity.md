# GetKernelObjectSecurity function

## Description

The **GetKernelObjectSecurity** function retrieves a copy of the [security descriptor](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) that protects a kernel object.

## Parameters

### `Handle` [in]

A handle to a kernel object.

### `RequestedInformation` [in]

Specifies a
[SECURITY_INFORMATION](https://learn.microsoft.com/windows/desktop/SecAuthZ/security-information) value that identifies the security information being requested.

### `pSecurityDescriptor` [out, optional]

A pointer to a buffer the function fills with a copy of the security descriptor of the specified object. The calling [process](https://learn.microsoft.com/windows/desktop/SecGloss/p-gly) must have the right to view the specified aspects of the object's security status. The
[SECURITY_DESCRIPTOR](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-security_descriptor) structure is returned in [self-relative](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) format.

### `nLength` [in]

Specifies the size, in bytes, of the buffer pointed to by the *pSecurityDescriptor* parameter.

### `lpnLengthNeeded` [out]

A pointer to a variable that receives the number of bytes required for the buffer pointed to by the *pSecurityDescriptor* parameter. If this variable's value is greater than the value of the *nLength* parameter when the function returns, none of the security descriptor is copied to the buffer.

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

To read the owner, group, or [DACL](https://learn.microsoft.com/windows/desktop/SecGloss/d-gly) from the kernel object's security descriptor, the calling process must have been granted READ_CONTROL access when the handle was opened. To get READ_CONTROL access, the caller must be the owner of the object or the object's DACL must grant the access.

To read the [SACL](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) from the security descriptor, the calling process must have been granted ACCESS_SYSTEM_SECURITY access when the handle was opened. The proper way to get this access is to enable the SE_SECURITY_NAME privilege in the caller's current token, open the handle for ACCESS_SYSTEM_SECURITY access, and then disable the privilege.

## See also

[GetFileSecurity](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-getfilesecuritya)

[GetPrivateObjectSecurity](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-getprivateobjectsecurity)

[GetUserObjectSecurity](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getuserobjectsecurity)

[Low-level Access Control](https://learn.microsoft.com/windows/desktop/SecAuthZ/low-level-access-control)

[Low-level Access Control Functions](https://learn.microsoft.com/windows/desktop/SecAuthZ/authorization-functions)

[SECURITY_DESCRIPTOR](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-security_descriptor)

[SECURITY_INFORMATION](https://learn.microsoft.com/windows/desktop/SecAuthZ/security-information)

[SetKernelObjectSecurity](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-setkernelobjectsecurity)