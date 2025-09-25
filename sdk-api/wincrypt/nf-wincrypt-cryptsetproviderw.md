# CryptSetProviderW function

## Description

**Important** This API is deprecated. New and existing software should start using [Cryptography Next Generation APIs.](https://learn.microsoft.com/windows/desktop/SecCNG/cng-portal) Microsoft may remove this API in future releases.

The **CryptSetProvider** function specifies the current user's default [cryptographic service provider](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) (CSP).

If a current user's default provider is set, that default provider is acquired by any call by that user to
[CryptAcquireContext](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptacquirecontexta) specifying a *dwProvType* provider type but not a CSP name.

An enhanced version of this function,
[CryptSetProviderEx](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptsetproviderexa), is also available.

**Note** Typical applications do not use this function. It is intended for use solely by administrative applications.

## Parameters

### `pszProvName` [in]

Name of the new default CSP. The named CSP must be installed on the computer. For a list of available cryptographic providers, see
[Cryptographic Provider Names](https://learn.microsoft.com/windows/desktop/SecCrypto/cryptographic-provider-names).

### `dwProvType` [in]

Provider type of the CSP specified by *pszProvName*.

## Return value

If the function succeeds, the return value is nonzero (TRUE).

If the function fails, the return value is zero (FALSE). For extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror). Some possible error codes are listed in the following table.

| Return code | Description |
| --- | --- |
| **ERROR_INVALID_HANDLE** | One of the parameters specifies a handle that is not valid. |
| **ERROR_INVALID_PARAMETER** | One of the parameters contains a value that is not valid. This is most often a pointer that is not valid. |
| **ERROR_NOT_ENOUGH_MEMORY** | The operating system ran out of memory during the operation. |

Errors can also be propagated from internal calls to [RegCreateKeyEx](https://learn.microsoft.com/windows/desktop/api/winreg/nf-winreg-regcreatekeyexa) and [RegSetValueEx](https://learn.microsoft.com/windows/desktop/api/winreg/nf-winreg-regsetvalueexa).

## Remarks

Typical applications do not specify a CSP name when calling
[CryptAcquireContext](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptacquirecontexta); however, an application does have the option of selecting a specific CSP. This gives a user the freedom to select a CSP with an appropriate level of security.

Since calling **CryptSetProvider** determines the CSP of a specified type used by all applications that run from that point on, this function must not be called without users' consent.

> [!NOTE]
> The wincrypt.h header defines CryptSetProvider as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[CryptAcquireContext](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptacquirecontexta)

[Cryptographic Provider Names](https://learn.microsoft.com/windows/desktop/SecCrypto/cryptographic-provider-names)

[RegCreateKeyEx](https://learn.microsoft.com/windows/desktop/api/winreg/nf-winreg-regcreatekeyexa)

[RegSetValueEx](https://learn.microsoft.com/windows/desktop/api/winreg/nf-winreg-regsetvalueexa)

[Service Provider Functions](https://learn.microsoft.com/windows/desktop/SecCrypto/cryptography-functions)