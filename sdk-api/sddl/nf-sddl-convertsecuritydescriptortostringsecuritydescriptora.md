# ConvertSecurityDescriptorToStringSecurityDescriptorA function

## Description

The **ConvertSecurityDescriptorToStringSecurityDescriptor** function converts a [security descriptor](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) to a string format. You can use the string format to store or transmit the security descriptor.

To convert the string-format security descriptor back to a valid, functional security descriptor, call the
[ConvertStringSecurityDescriptorToSecurityDescriptor](https://learn.microsoft.com/windows/desktop/api/sddl/nf-sddl-convertstringsecuritydescriptortosecuritydescriptora) function.

## Parameters

### `SecurityDescriptor` [in]

A pointer to the security descriptor to convert. The security descriptor can be in
[absolute or self-relative format](https://learn.microsoft.com/windows/desktop/SecAuthZ/absolute-and-self-relative-security-descriptors).

### `RequestedStringSDRevision` [in]

Specifies the revision level of the output *StringSecurityDescriptor* string. Currently this value must be SDDL_REVISION_1.

### `SecurityInformation` [in]

Specifies a combination of the
[SECURITY_INFORMATION](https://learn.microsoft.com/windows/desktop/SecAuthZ/security-information) bit flags to indicate the components of the security descriptor to include in the output string.

The BACKUP_SECURITY_INFORMATION flag is not applicable to this function. If the BACKUP_SECURITY_INFORMATION flag is passed in, the *SecurityInformation* parameter returns TRUE with **null** string output.

### `StringSecurityDescriptor` [out]

A pointer to a variable that receives a pointer to a **null**-terminated security descriptor string. For a description of the string format, see
[Security Descriptor String Format](https://learn.microsoft.com/windows/desktop/SecAuthZ/security-descriptor-string-format). To free the returned buffer, call the
[LocalFree](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-localfree) function.

### `StringSecurityDescriptorLen` [out]

A pointer to a variable that receives the size, in **TCHAR**s, of the security descriptor string returned in the *StringSecurityDescriptor* buffer. This parameter can be **NULL** if you do not need to retrieve the size. The size represents the size of the buffer in **WCHAR**s, not the number of **WCHAR**s in the string.

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror). The **GetLastError** function may return one of the following error codes.

| Return code | Description |
| --- | --- |
| **ERROR_INVALID_PARAMETER** | A parameter is not valid. |
| **ERROR_UNKNOWN_REVISION** | The revision level is not valid. |
| **ERROR_NONE_MAPPED** | A [security identifier](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) (SID) in the input security descriptor could not be found in an account lookup operation. |
| **ERROR_INVALID_ACL** | The [access control list](https://learn.microsoft.com/windows/desktop/SecGloss/a-gly) (ACL) is not valid. This error is returned if the SE_DACL_PRESENT flag is set in the input security descriptor and the DACL is **NULL**. |

## Remarks

If the DACL is **NULL**, and the SE_DACL_PRESENT control bit is set in the input security descriptor, the function fails.

If the DACL is **NULL**, and the SE_DACL_PRESENT control bit is not set in the input security descriptor, the resulting security descriptor string does not have a D: component. For more information, see
[Security Descriptor String Format](https://learn.microsoft.com/windows/desktop/SecAuthZ/security-descriptor-string-format).

> [!NOTE]
> The sddl.h header defines ConvertSecurityDescriptorToStringSecurityDescriptor as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[Access Control Overview](https://learn.microsoft.com/windows/desktop/SecAuthZ/access-control)

[Basic Access Control Functions](https://learn.microsoft.com/windows/desktop/SecAuthZ/authorization-functions)

[ConvertSidToStringSid](https://learn.microsoft.com/windows/desktop/api/sddl/nf-sddl-convertsidtostringsida)

[ConvertStringSecurityDescriptorToSecurityDescriptor](https://learn.microsoft.com/windows/desktop/api/sddl/nf-sddl-convertstringsecuritydescriptortosecuritydescriptora)

[ConvertStringSidToSid](https://learn.microsoft.com/windows/desktop/api/sddl/nf-sddl-convertstringsidtosida)

[SECURITY_DESCRIPTOR](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-security_descriptor)

[SECURITY_INFORMATION](https://learn.microsoft.com/windows/desktop/SecAuthZ/security-information)