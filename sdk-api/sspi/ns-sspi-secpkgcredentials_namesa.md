# SecPkgCredentials_NamesA structure

## Description

The **SecPkgCredentials_Names** structure holds the name of the user associated with a [context](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly). The
[QueryCredentialsAttributes](https://learn.microsoft.com/windows/desktop/api/sspi/nf-sspi-querycredentialsattributesa) function uses this structure.

## Members

### `sUserName`

Pointer to a null-terminated string containing the name of the user represented by the credential. If the [security package](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) sets the SECPKG_FLAG_ACCEPT_WIN32_NAME flag to indicate that it can process Windows names, this name can be used in other Windows calls.

### `sUserName.string`

## See also

[QueryCredentialsAttributes](https://learn.microsoft.com/windows/desktop/api/sspi/nf-sspi-querycredentialsattributesa)

## Remarks

> [!NOTE]
> The sspi.h header defines SecPkgCredentials_Names as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).