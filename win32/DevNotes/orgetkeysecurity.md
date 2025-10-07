# ORGetKeySecurity function

Retrieves a copy of the security descriptor protecting the specified open registry key in an offline registry hive.

## Parameters

*Handle* \[in\]

A handle to an open registry key in an offline registry hive.

*SecurityInformation* \[in\]

A [SECURITY\_INFORMATION](https://learn.microsoft.com/windows/win32/secauthz/security-information) value that indicates the requested security information.

*pSecurityDescriptor* \[out, optional\]

A pointer to a buffer that receives a copy of the requested security descriptor. This parameter can be **NULL**.

*lpcbSecurityDescriptor* \[in, out\]

A pointer to a variable that specifies the size, in bytes, of the buffer pointed to by the *pSecurityDescriptor* parameter. When the function returns, the variable contains the number of bytes written to the buffer.

## Return value

If the function succeeds, the function returns ERROR\_SUCCESS.

If the function fails, it returns a nonzero error code defined in Winerror.h. You can use the [FormatMessage](https://learn.microsoft.com/windows/win32/api/winbase/nf-winbase-formatmessage) function with the FORMAT\_MESSAGE\_FROM\_SYSTEM flag to get a generic description of the error.

If the buffer specified by the *pSecurityDescriptor* parameter is too small, the function returns ERROR\_INSUFFICIENT\_BUFFER and the *lpcbSecurityDescriptor* parameter contains the number of bytes required for the requested security descriptor.

## Requirements

| Requirement | Value |
|----------------------------|---------------------------------------------------------------------------------------|
| Redistributable<br> | Windows Offline Registry library version 1.0 or later<br> |
| Header<br> | Offreg.h |
| DLL<br> | Offreg.dll |

## See also

[**ORDeleteKey**](https://learn.microsoft.com/windows/win32/devnotes/ordeletekey)

[**OROpenKey**](https://learn.microsoft.com/windows/win32/devnotes/oropenkey)

[**ORSetKeySecurity**](https://learn.microsoft.com/windows/win32/devnotes/orsetkeysecurity)

[SECURITY\_INFORMATION](https://learn.microsoft.com/windows/win32/secauthz/security-information)

