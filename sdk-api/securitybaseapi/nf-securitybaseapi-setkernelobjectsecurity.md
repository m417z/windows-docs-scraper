# SetKernelObjectSecurity function

## Description

The **SetKernelObjectSecurity** function sets the security of a kernel object. For example, this can be a [process](https://learn.microsoft.com/windows/desktop/SecGloss/p-gly), thread, or event.

**Note** This function should not be used when setting a security descriptor on file system objects. Instead, use the [SetSecurityInfo](https://learn.microsoft.com/windows/desktop/api/aclapi/nf-aclapi-setsecurityinfo) or [SetNamedSecurityInfo](https://learn.microsoft.com/windows/desktop/api/aclapi/nf-aclapi-setnamedsecurityinfoa) functions.

## Parameters

### `Handle` [in]

A handle to a kernel object for which security information is set.

### `SecurityInformation` [in]

A set of
bit flags that indicate the type of security information to set. This parameter can be a combination of the
[SECURITY_INFORMATION](https://learn.microsoft.com/windows/desktop/SecAuthZ/security-information) bit flags.

### `SecurityDescriptor` [in]

A pointer to a
[SECURITY_DESCRIPTOR](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-security_descriptor) structure that contains the new security information.

## Return value

If the function succeeds, the function returns nonzero.

If the function fails, it returns zero. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## See also

[GetKernelObjectSecurity](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-getkernelobjectsecurity)

[Low-level Access Control](https://learn.microsoft.com/windows/desktop/SecAuthZ/low-level-access-control)

[Low-level Access Control Functions](https://learn.microsoft.com/windows/desktop/SecAuthZ/authorization-functions)

[SECURITY_DESCRIPTOR](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-security_descriptor)

[SECURITY_INFORMATION](https://learn.microsoft.com/windows/desktop/SecAuthZ/security-information)

[SetFileSecurity](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-setfilesecuritya)

[SetPrivateObjectSecurity](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-setprivateobjectsecurity)

[SetUserObjectSecurity](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-setuserobjectsecurity)