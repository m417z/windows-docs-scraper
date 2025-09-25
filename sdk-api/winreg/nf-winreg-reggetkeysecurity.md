# RegGetKeySecurity function

## Description

The **RegGetKeySecurity** function retrieves a copy of the [security descriptor](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) protecting the specified open registry key.

## Parameters

### `hKey` [in]

A handle to an open key for which to retrieve the security descriptor.

### `SecurityInformation` [in]

A
[SECURITY_INFORMATION](https://learn.microsoft.com/windows/desktop/SecAuthZ/security-information) value that indicates the requested security information.

### `pSecurityDescriptor` [out, optional]

A pointer to a buffer that receives a copy of the requested security descriptor.

### `lpcbSecurityDescriptor` [in, out]

A pointer to a variable that specifies the size, in bytes, of the buffer pointed to by the *pSecurityDescriptor* parameter. When the function returns, the variable contains the number of bytes written to the buffer.

## Return value

If the function succeeds, the function returns ERROR_SUCCESS.

If the function fails, it returns a nonzero error code defined in WinError.h. You can use the
[FormatMessage](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-formatmessage) function with the FORMAT_MESSAGE_FROM_SYSTEM flag to get a generic description of the error.

## Remarks

If the buffer specified by the *pSecurityDescriptor* parameter is too small, the function returns ERROR_INSUFFICIENT_BUFFER and the *lpcbSecurityDescriptor* parameter contains the number of bytes required for the requested security descriptor.

To read the owner, group, or [discretionary access control list](https://learn.microsoft.com/windows/desktop/SecGloss/d-gly) (DACL) from the key's security descriptor, the calling [process](https://learn.microsoft.com/windows/desktop/SecGloss/p-gly) must have been granted READ_CONTROL access when the handle was opened. To get READ_CONTROL access, the caller must be the owner of the key or the key's DACL must grant the access.

To read the [system access control list](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) (SACL) from the security descriptor, the calling process must have been granted ACCESS_SYSTEM_SECURITY access when the key was opened. The correct way to get this access is to enable the SE_SECURITY_NAME privilege in the caller's current token, open the handle for ACCESS_SYSTEM_SECURITY access, and then disable the privilege.

## See also

[FormatMessage](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-formatmessage)

[Low-level Access Control](https://learn.microsoft.com/windows/desktop/SecAuthZ/low-level-access-control)

[Low-level Access Control Functions](https://learn.microsoft.com/windows/desktop/SecAuthZ/authorization-functions)

[RegDeleteKey](https://learn.microsoft.com/windows/desktop/api/winreg/nf-winreg-regdeletekeya)

[RegOpenKeyEx](https://learn.microsoft.com/windows/desktop/api/winreg/nf-winreg-regopenkeyexa)

[RegSetKeySecurity](https://learn.microsoft.com/windows/desktop/api/winreg/nf-winreg-regsetkeysecurity)

[SECURITY_INFORMATION](https://learn.microsoft.com/windows/desktop/SecAuthZ/security-information)