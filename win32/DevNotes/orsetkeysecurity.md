# ORSetKeySecurity function

Sets the security of an open registry key in an offline registry hive.

## Parameters

*Handle* \[in\]

A handle to an open registry key in an offline registry hive.

*SecurityInformation* \[in\]

Bit flags that indicate the type of security information to set. This parameter can be a combination of the [SECURITY\_INFORMATION](https://learn.microsoft.com/windows/win32/secauthz/security-information) bit flags.

*pSecurityDescriptor* \[in\]

A pointer to a [SECURITY\_DESCRIPTOR](https://learn.microsoft.com/windows/win32/api/winnt/ns-winnt-security_descriptor) structure that specifies the security attributes to set for the specified key.

## Return value

If the function succeeds, the function returns ERROR\_SUCCESS.

If the function fails, it returns a nonzero error code defined in Winerror.h. You can use the [FormatMessage](https://learn.microsoft.com/windows/win32/api/winbase/nf-winbase-formatmessage) function with the FORMAT\_MESSAGE\_FROM\_SYSTEM flag to get a generic description of the error.

## Requirements

| Requirement | Value |
|----------------------------|---------------------------------------------------------------------------------------|
| Redistributable<br> | Windows Offline Registry library version 1.0 or later<br> |
| Header<br> | Offreg.h |
| DLL<br> | Offreg.dll |

## See also

[**ORCloseKey**](https://learn.microsoft.com/windows/win32/devnotes/orclosekey)

[**ORDeleteKey**](https://learn.microsoft.com/windows/win32/devnotes/ordeletekey)

[**OROpenKey**](https://learn.microsoft.com/windows/win32/devnotes/oropenkey)

[**ORGetKeySecurity**](https://learn.microsoft.com/windows/win32/devnotes/orgetkeysecurity)

[SECURITY\_DESCRIPTOR](https://learn.microsoft.com/windows/win32/api/winnt/ns-winnt-security_descriptor)

[SECURITY\_INFORMATION](https://learn.microsoft.com/windows/win32/secauthz/security-information)

