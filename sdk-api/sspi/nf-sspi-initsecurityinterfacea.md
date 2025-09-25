# InitSecurityInterfaceA function

## Description

The **InitSecurityInterface** function returns a pointer to an SSPI dispatch table. This function enables clients to use SSPI without binding directly to an implementation of the interface.

## Return value

If the function succeeds, the return value is a pointer to a
[SecurityFunctionTable](https://learn.microsoft.com/windows/win32/api/sspi/ns-sspi-securityfunctiontablea) structure.

If the function fails, the return value is **NULL**.

## See also

[SSPI Functions](https://learn.microsoft.com/windows/desktop/SecAuthN/authentication-functions)

[SecurityFunctionTable](https://learn.microsoft.com/windows/win32/api/sspi/ns-sspi-securityfunctiontablea)

## Remarks

> [!NOTE]
> The sspi.h header defines InitSecurityInterface as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).
> QueryContextAttributesExA and QueryCredentialsAttributesExA are not initialized.