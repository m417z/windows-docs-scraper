# ConvertStringSecurityDescriptorToSecurityDescriptorA function

## Description

The **ConvertStringSecurityDescriptorToSecurityDescriptor** function converts a string-format [security descriptor](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) into a valid, functional security descriptor. This function retrieves a security descriptor that the
[ConvertSecurityDescriptorToStringSecurityDescriptor](https://learn.microsoft.com/windows/desktop/api/sddl/nf-sddl-convertsecuritydescriptortostringsecuritydescriptora) function converted to string format.

## Parameters

### `StringSecurityDescriptor` [in]

A pointer to a null-terminated string containing the
[string-format security descriptor](https://learn.microsoft.com/windows/desktop/SecAuthZ/security-descriptor-string-format) to convert.

### `StringSDRevision` [in]

Specifies the revision level of the *StringSecurityDescriptor* string. Currently this value must be SDDL_REVISION_1.

### `SecurityDescriptor` [out]

A pointer to a variable that receives a pointer to the converted security descriptor. The returned security descriptor is [self-relative](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly). To free the returned buffer, call the
[LocalFree](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-localfree) function. To convert the security descriptor to an [absolute security descriptor](https://learn.microsoft.com/windows/desktop/SecGloss/a-gly), use the
[MakeAbsoluteSD](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-makeabsolutesd) function.

### `SecurityDescriptorSize` [out]

A pointer to a variable that receives the size, in bytes, of the converted security descriptor. This parameter can be NULL.

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror). **GetLastError** may return one of the following error codes.

| Return code | Description |
| --- | --- |
| **ERROR_INVALID_PARAMETER** | A parameter is not valid. |
| **ERROR_UNKNOWN_REVISION** | The SDDL revision level is not valid. |
| **ERROR_NONE_MAPPED** | A [security identifier](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) (SID) in the input security descriptor string could not be found in an account lookup operation. |

## Remarks

If **ace_type** is ACCESS_ALLOWED_OBJECT_ACE_TYPE
and neither **object_guid** nor **inherit_object_guid** has a [GUID](https://learn.microsoft.com/windows/win32/api/guiddef/ns-guiddef-guid) specified, then **ConvertStringSecurityDescriptorToSecurityDescriptor** converts **ace_type** to ACCESS_ALLOWED_ACE_TYPE. For information about the **ace_type**, **object_guid**, and **inherit_object_guid** fields, see [Ace Strings](https://learn.microsoft.com/windows/desktop/SecAuthZ/ace-strings).

> [!NOTE]
> The sddl.h header defines ConvertStringSecurityDescriptorToSecurityDescriptor as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[Access Control Overview](https://learn.microsoft.com/windows/desktop/SecAuthZ/access-control)

[Basic Access Control Functions](https://learn.microsoft.com/windows/desktop/SecAuthZ/authorization-functions)

[ConvertSecurityDescriptorToStringSecurityDescriptor](https://learn.microsoft.com/windows/desktop/api/sddl/nf-sddl-convertsecuritydescriptortostringsecuritydescriptora)

[ConvertSidToStringSid](https://learn.microsoft.com/windows/desktop/api/sddl/nf-sddl-convertsidtostringsida)

[ConvertStringSidToSid](https://learn.microsoft.com/windows/desktop/api/sddl/nf-sddl-convertstringsidtosida)

[MakeAbsoluteSD](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-makeabsolutesd)

[SECURITY_DESCRIPTOR](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-security_descriptor)