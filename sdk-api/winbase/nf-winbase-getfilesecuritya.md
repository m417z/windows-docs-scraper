# GetFileSecurityA function

## Description

The **GetFileSecurity** function obtains specified information about the security of a file or directory. The information obtained is constrained by the caller's access rights and [privileges](https://learn.microsoft.com/windows/desktop/SecGloss/p-gly).

The [GetNamedSecurityInfo](https://learn.microsoft.com/windows/desktop/api/aclapi/nf-aclapi-getnamedsecurityinfoa) function provides functionality similar to **GetFileSecurity** for files as well as other types of objects.

## Parameters

### `lpFileName` [in]

A pointer to a null-terminated string that specifies the file or directory for which security information is retrieved.

### `RequestedInformation` [in]

A
[SECURITY_INFORMATION](https://learn.microsoft.com/windows/desktop/SecAuthZ/security-information) value that identifies the security information being requested.

### `pSecurityDescriptor` [out, optional]

A pointer to a buffer that receives a copy of the [security descriptor](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) of the object specified by the *lpFileName* parameter. The calling [process](https://learn.microsoft.com/windows/desktop/SecGloss/p-gly) must have permission to view the specified aspects of the object's security status. The
[SECURITY_DESCRIPTOR](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-security_descriptor) structure is returned in [self-relative security descriptor](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) format.

### `nLength` [in]

Specifies the size, in bytes, of the buffer pointed to by the *pSecurityDescriptor* parameter.

### `lpnLengthNeeded` [out]

A pointer to the variable that receives the number of bytes necessary to store the complete [security descriptor](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly). If the returned number of bytes is less than or equal to *nLength*, the entire security descriptor is returned in the output buffer; otherwise, none of the descriptor is returned.

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

To read the owner, group, or [DACL](https://learn.microsoft.com/windows/desktop/SecGloss/d-gly) from the security descriptor for the specified file or directory, the DACL for the file or directory must grant READ_CONTROL access to the caller, or the caller must be the owner of the file or directory.

To read the [SACL](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) of a file or directory, the SE_SECURITY_NAME privilege must be enabled for the calling process.

## See also

[GetKernelObjectSecurity](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-getkernelobjectsecurity)

[GetNamedSecurityInfo](https://learn.microsoft.com/windows/desktop/api/aclapi/nf-aclapi-getnamedsecurityinfoa)

[GetPrivateObjectSecurity](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-getprivateobjectsecurity)

[GetUserObjectSecurity](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getuserobjectsecurity)

[Low-level Access Control](https://learn.microsoft.com/windows/desktop/SecAuthZ/low-level-access-control)

[Low-level Access Control Functions](https://learn.microsoft.com/windows/desktop/SecAuthZ/authorization-functions)

[SECURITY_DESCRIPTOR](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-security_descriptor)

[SECURITY_INFORMATION](https://learn.microsoft.com/windows/desktop/SecAuthZ/security-information)

[SetFileSecurity](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-setfilesecuritya)