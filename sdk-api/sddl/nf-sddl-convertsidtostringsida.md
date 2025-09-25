# ConvertSidToStringSidA function

## Description

The **ConvertSidToStringSid** function converts a [security identifier](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) (SID) to a string format suitable for display, storage, or transmission.

To convert the string-format SID back to a valid, functional SID, call the
[ConvertStringSidToSid](https://learn.microsoft.com/windows/desktop/api/sddl/nf-sddl-convertstringsidtosida) function.

## Parameters

### `Sid` [in]

A pointer to the [SID](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-sid) structure to be converted.

### `StringSid` [out]

A pointer to a variable that receives a pointer to a null-terminated SID string. To free the returned buffer, call the
[LocalFree](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-localfree) function.

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror). The **GetLastError** function may return one of the following error codes.

| Return code | Description |
| --- | --- |
| **ERROR_NOT_ENOUGH_MEMORY** | Insufficient memory. |
| **ERROR_INVALID_SID** | The SID is not valid. |
| **ERROR_INVALID_PARAMETER** | One of the parameters contains a value that is not valid. This is most often a pointer that is not valid. |

## Remarks

The **ConvertSidToStringSid** function uses the standard S-*R*-*I*-*S*-*S*… format for SID strings. For more information about SID string notation, see
[SID Components](https://learn.microsoft.com/windows/desktop/SecAuthZ/sid-components).

> [!NOTE]
> The sddl.h header defines ConvertSidToStringSid as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[Access Control Overview](https://learn.microsoft.com/windows/desktop/SecAuthZ/access-control)

[Basic Access Control Functions](https://learn.microsoft.com/windows/desktop/SecAuthZ/authorization-functions)

[ConvertSecurityDescriptorToStringSecurityDescriptor](https://learn.microsoft.com/windows/desktop/api/sddl/nf-sddl-convertsecuritydescriptortostringsecuritydescriptora)

[ConvertStringSecurityDescriptorToSecurityDescriptor](https://learn.microsoft.com/windows/desktop/api/sddl/nf-sddl-convertstringsecuritydescriptortosecuritydescriptora)

[ConvertStringSidToSid](https://learn.microsoft.com/windows/desktop/api/sddl/nf-sddl-convertstringsidtosida)

[SID](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-sid)