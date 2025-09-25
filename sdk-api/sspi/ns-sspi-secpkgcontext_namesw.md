# SecPkgContext_NamesW structure

## Description

The **SecPkgContext_Names** structure indicates the name of the user associated with a [security context](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly). The
[QueryContextAttributes (General)](https://learn.microsoft.com/windows/desktop/api/sspi/nf-sspi-querycontextattributesa) function uses this structure.

## Members

### `sUserName`

Pointer to a null-terminated string containing the name of the user represented by the context. If the [security package](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) has set the SECPKG_FLAG_ACCEPT_WIN32_NAME flag, this name can be used in other Windows calls.

## See also

[QueryContextAttributes (General)](https://learn.microsoft.com/windows/desktop/api/sspi/nf-sspi-querycontextattributesa)

## Remarks

> [!NOTE]
> The sspi.h header defines SecPkgContext_Names as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).