# CredUnprotectW function

## Description

The **CredUnprotect** function decrypts credentials that were previously encrypted by using the [CredProtect](https://learn.microsoft.com/windows/desktop/api/wincred/nf-wincred-credprotecta) function. The credentials must have been encrypted in the same security context in which **CredUnprotect** is called.

## Parameters

### `fAsSelf` [in]

Set to **TRUE** to specify that the credentials were encrypted in the security context of the current process. Set to **FALSE** to specify that credentials were encrypted in the security context of the calling thread security context.

### `pszProtectedCredentials` [in]

A pointer to a string that specifies the encrypted credentials.

### `cchProtectedCredentials` [in]

The size, in characters, of the *pszProtectedCredentials* buffer.

### `pszCredentials` [out]

A pointer to a string that, on output, receives the decrypted credentials.

### `pcchMaxChars` [in, out]

The size, in characters of the *pszCredentials* buffer. On output, if the *pszCredentials* is not of sufficient size to receive the encrypted credentials, this parameter specifies the required size, in characters, of the *pszCredentials* buffer.

## Return value

**TRUE** if the function succeeds; otherwise, **FALSE**.

For extended error information, call the
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) function. The following table shows common values for the **GetLastError** function.

| Return code/value | Description |
| --- | --- |
| **ERROR_NOT_CAPABLE** | The security context used to encrypt the credentials is different from the security context used to decrypt the credentials. |
| **ERROR_INSUFFICIENT_BUFFER** | The *pszCredentials* buffer was of insufficient size. |

## Remarks

> [!NOTE]
> The wincred.h header defines CredUnprotect as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).