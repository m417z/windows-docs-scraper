# SecPkgCredentials_SSIProviderA structure

## Description

The **SecPkgCredentials_SSIProvider** structure holds the SSI provider information associated with a [context](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly). The
[QueryCredentialsAttributes](https://learn.microsoft.com/windows/desktop/api/sspi/nf-sspi-querycredentialsattributesa) function uses this structure.

## Members

### `sProviderName`

Pointer to a null-terminated string that contains the name of the provider represented by the credential.

### `ProviderInfoLength`

Length of the provider information.

### `ProviderInfo`

The provider information.

## Remarks

> [!NOTE]
> The sspi.h header defines SecPkgCredentials_SSIProvider as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).