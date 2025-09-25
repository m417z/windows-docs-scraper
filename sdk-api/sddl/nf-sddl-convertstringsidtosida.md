# ConvertStringSidToSidA function

## Description

The **ConvertStringSidToSid** function converts a string-format [security identifier](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) (SID) into a valid, functional SID. You can use this function to retrieve a SID that the
[ConvertSidToStringSid](https://learn.microsoft.com/windows/desktop/api/sddl/nf-sddl-convertsidtostringsida) function converted to string format.

## Parameters

### `StringSid` [in]

A pointer to a null-terminated string containing the string-format SID to convert.

The SID string can use either the standard
S-*R*-*I*-*S*-*S*… format for SID strings, or the SID string constant format, such as "BA" for built-in administrators. For more information about SID string notation, see
[SID Components](https://learn.microsoft.com/windows/desktop/SecAuthZ/sid-components).

### `Sid` [out]

A pointer to a variable that receives a pointer to the converted SID. To free the returned buffer, call the
[LocalFree](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-localfree) function.

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror). The **GetLastError** function may return one of the following error codes.

| Return code | Description |
| --- | --- |
| **ERROR_INVALID_PARAMETER** | Invalid parameter. |
| **ERROR_INVALID_SID** | Invalid SID. |

## See also

[Access Control](https://learn.microsoft.com/windows/desktop/SecAuthZ/access-control)

[Basic Access Control Functions](https://learn.microsoft.com/windows/desktop/SecAuthZ/authorization-functions)

[ConvertSecurityDescriptorToStringSecurityDescriptor](https://learn.microsoft.com/windows/desktop/api/sddl/nf-sddl-convertsecuritydescriptortostringsecuritydescriptora)

[ConvertSidToStringSid](https://learn.microsoft.com/windows/desktop/api/sddl/nf-sddl-convertsidtostringsida)

[ConvertStringSecurityDescriptorToSecurityDescriptor](https://learn.microsoft.com/windows/desktop/api/sddl/nf-sddl-convertstringsecuritydescriptortosecuritydescriptora)

[SID](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-sid)

## Remarks

> [!NOTE]
> The sddl.h header defines ConvertStringSidToSid as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).