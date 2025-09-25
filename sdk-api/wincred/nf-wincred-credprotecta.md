# CredProtectA function

## Description

The **CredProtect** function encrypts the specified credentials so that only the current security context can decrypt them.

## Parameters

### `fAsSelf` [in]

Set to **TRUE** to specify that the credentials are encrypted in the security context of the current process. Set to **FALSE** to specify that credentials are encrypted in the security context of the calling thread security context.

### `pszCredentials` [in]

A pointer to a string that specifies the credentials to encrypt. The function encrypts the number of characters provided in the *cchCredentials* parameter.

### `cchCredentials` [in]

The size, in characters, of the *pszCredentials* buffer.

### `pszProtectedCredentials` [out]

A pointer to a string that, on output, receives the encrypted credentials.

### `pcchMaxChars` [in, out]

The size, in characters of the *pszProtectedCredentials* buffer. On output, if the *pszProtectedCredentials* is not of sufficient size to receive the encrypted credentials, this parameter specifies the required size, in characters, of the *pszProtectedCredentials* buffer.

### `ProtectionType` [out]

A pointer to a [CRED_PROTECTION_TYPE](https://learn.microsoft.com/windows/desktop/api/wincred/ne-wincred-cred_protection_type) enumeration type that, on output, specifies the type of protection provided.

## Return value

**TRUE** if the function succeeds; otherwise, **FALSE**.

For extended error information, call the
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) function.

## Remarks

Note that the output of the **CredProtect** function is not integrity protected, so if the output is modified, the [CredUnprotect](https://learn.microsoft.com/windows/desktop/api/wincred/nf-wincred-credunprotecta) function is not updated and may produce incorrect results.

> [!NOTE]
> The wincred.h header defines CredProtect as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).