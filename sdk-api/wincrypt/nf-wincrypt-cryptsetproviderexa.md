# CryptSetProviderExA function

## Description

**Important** This API is deprecated. New and existing software should start using [Cryptography Next Generation APIs.](https://learn.microsoft.com/windows/desktop/SecCNG/cng-portal) Microsoft may remove this API in future releases.

The **CryptSetProviderEx** function specifies the default [cryptographic service provider](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) (CSP) of a specified provider type for the local computer or current user.

**Note** Typical applications do not use this function. It is intended for use solely by administrative applications.

## Parameters

### `pszProvName` [in]

The name of the new default CSP. This must be a CSP installed on the computer. For a list of available cryptographic providers, see
[Cryptographic Provider Names](https://learn.microsoft.com/windows/desktop/SecCrypto/cryptographic-provider-names).

### `dwProvType` [in]

The provider type of the CSP specified by *pszProvName*.

### `pdwReserved` [in]

This parameter is reserved for future use and must be **NULL**.

### `dwFlags` [in]

The following flag values are defined.

| Value | Meaning |
| --- | --- |
| **CRYPT_DELETE_DEFAULT**<br><br>0x00000004 | Can be used in conjunction with CRYPT_MACHINE_DEFAULT or CRYPT_USER_DEFAULT to delete the default. |
| **CRYPT_USER_DEFAULT**<br><br>0x00000002 | Causes the user-context default CSP of the specified type to be set. |
| **CRYPT_MACHINE_DEFAULT**<br><br>0x00000001 | Causes the computer default CSP of the specified type to be set. |

## Return value

If the function succeeds, the return value is nonzero (**TRUE**).

If the function fails, the return value is zero (**FALSE**). For extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror). Possible error codes include those shown in the following table.

| Return code | Description |
| --- | --- |
| **ERROR_INVALID_PARAMETER** | One of the parameters contains a value that is not valid. This is most often a pointer that is not valid. |
| **ERROR_NOT_ENOUGH_MEMORY** | The operating system ran out of memory. |

## Remarks

Most applications do not specify a CSP name when calling the
[CryptAcquireContext](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptacquirecontexta) function; however, an application can specify a CSP name and thereby select a CSP with an appropriate level of security. Because calls to **CryptSetProviderEx** determine the CSP of a specified type used by all applications from that point on, **CryptSetProviderEx** must never be called without a user's consent.

> [!NOTE]
> The wincrypt.h header defines CryptSetProviderEx as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[CryptAcquireContext](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptacquirecontexta)

[CryptSetProvider](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptsetprovidera)

[Service Provider Functions](https://learn.microsoft.com/windows/desktop/SecCrypto/cryptography-functions)