# CRYPT_PASSWORD_CREDENTIALSA structure

## Description

The **CRYPT_PASSWORD_CREDENTIALS** structure contains the user name and password credentials to be used in the [CRYPT_CREDENTIALS](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-crypt_credentials) structure as optional input to a remote object retrieval function such as [CryptRetrieveObjectByUrl](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptretrieveobjectbyurla) or [CryptGetTimeValidObject](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptgettimevalidobject).

## Members

### `cbSize`

The size, in bytes, of this structure.

### `pszUsername`

A pointer to a null-terminated string that contains the user name credential for the remote session authentication.

### `pszPassword`

A pointer to a null-terminated string that contains the password credential for the remote session authentication.

## Remarks

> [!NOTE]
> The wincrypt.h header defines CRYPT_PASSWORD_CREDENTIALS as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).