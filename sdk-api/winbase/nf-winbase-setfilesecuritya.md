# SetFileSecurityA function

## Description

The **SetFileSecurity** function sets the security of a file or directory object.

This function is obsolete. Use the [SetNamedSecurityInfo](https://learn.microsoft.com/windows/desktop/api/aclapi/nf-aclapi-setnamedsecurityinfoa) function instead.

## Parameters

### `lpFileName` [in]

A pointer to a null-terminated string that specifies the file or directory for which security is set. Note that security applied to a directory is not inherited by its children.

### `SecurityInformation` [in]

Specifies a
[SECURITY_INFORMATION](https://learn.microsoft.com/windows/desktop/SecAuthZ/security-information) structure that identifies the contents of the [security descriptor](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) pointed to by the *pSecurityDescriptor* parameter.

### `pSecurityDescriptor` [in]

A pointer to a
[SECURITY_DESCRIPTOR](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-security_descriptor) structure.

## Return value

If the function succeeds, the function returns nonzero.

If the function fails, it returns zero. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

The **SetFileSecurity** function is successful only if the following conditions are met:

* If the owner of the object is being set, the calling [process](https://learn.microsoft.com/windows/desktop/SecGloss/p-gly) must have either WRITE_OWNER permission or be the owner of the object.
* If the [discretionary access control list](https://learn.microsoft.com/windows/desktop/SecGloss/d-gly) (DACL) of the object is being set, the calling process must have either WRITE_DAC permission or be the owner of the object.
* If the [system access control list](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) (SACL) of the object is being set, the SE_SECURITY_NAME privilege must be enabled for the calling process.

## See also

[GetFileSecurity](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-getfilesecuritya)

[Low-level Access Control](https://learn.microsoft.com/windows/desktop/SecAuthZ/low-level-access-control)

[Low-level Access Control Functions](https://learn.microsoft.com/windows/desktop/SecAuthZ/authorization-functions)

[SECURITY_DESCRIPTOR](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-security_descriptor)

[SECURITY_INFORMATION](https://learn.microsoft.com/windows/desktop/SecAuthZ/security-information)

[SetKernelObjectSecurity](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-setkernelobjectsecurity)

[SetNamedSecurityInfo](https://learn.microsoft.com/windows/desktop/api/aclapi/nf-aclapi-setnamedsecurityinfoa)

[SetPrivateObjectSecurity](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-setprivateobjectsecurity)

[SetUserObjectSecurity](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-setuserobjectsecurity)