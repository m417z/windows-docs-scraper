# SecPkgContext_AuthorityA structure

## Description

The **SecPkgContext_Authority** structure contains the name of the authenticating authority if one is available. It can be a [certification authority](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) (CA) or the name of a server or domain that authenticated the connection. The
[QueryContextAttributes (General)](https://learn.microsoft.com/windows/desktop/api/sspi/nf-sspi-querycontextattributesa) function uses this structure.

## Members

### `sAuthorityName`

Pointer to a null-terminated string containing the name of the authenticating authority, if available.

## Remarks

> [!NOTE]
> The sspi.h header defines SecPkgContext_Authority as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).