# CryptReleaseContext function

## Description

**Important** This API is deprecated. New and existing software should start using [Cryptography Next Generation APIs.](https://learn.microsoft.com/windows/desktop/SecCNG/cng-portal) Microsoft may remove this API in future releases.

The **CryptReleaseContext** function releases the handle of a [cryptographic service provider](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) (CSP) and a [key container](https://learn.microsoft.com/windows/desktop/SecGloss/k-gly). At each call to this function, the [reference count](https://learn.microsoft.com/windows/desktop/SecGloss/r-gly) on the CSP is reduced by one. When the reference count reaches zero, the [context](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) is fully released and it can no longer be used by any function in the application.

An application calls this function after finishing the use of the CSP. After this function is called, the released CSP handle is no longer valid. This function does not destroy [key containers](https://learn.microsoft.com/windows/desktop/SecGloss/k-gly) or [key pairs](https://learn.microsoft.com/windows/desktop/SecGloss/k-gly).

## Parameters

### `hProv` [in]

Handle of a cryptographic service provider (CSP) created by a call to
[CryptAcquireContext](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptacquirecontexta).

### `dwFlags` [in]

Reserved for future use and must be zero. If *dwFlags* is not set to zero, this function returns **FALSE** but the CSP is released.

## Return value

If the function succeeds, the return value is nonzero (**TRUE**).

If the function fails, the return value is zero (**FALSE**). For extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror). Some possible error codes are listed in the following table.

| Return code | Description |
| --- | --- |
| **ERROR_BUSY** | The CSP [context](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) specified by *hProv* is currently being used by another [process](https://learn.microsoft.com/windows/desktop/SecGloss/p-gly). |
| **ERROR_INVALID_HANDLE** | One of the parameters specifies a handle that is not valid. |
| **ERROR_INVALID_PARAMETER** | One of the parameters contains a value that is not valid. This is most often a pointer that is not valid. |
| **NTE_BAD_FLAGS** | The *dwFlags* parameter is nonzero. |
| **NTE_BAD_UID** | The *hProv* parameter does not contain a valid context handle. |

## Remarks

After this function has been called, the CSP session is finished and all existing session keys and [hash objects](https://learn.microsoft.com/windows/desktop/SecGloss/h-gly) created by using the *hProv* handle are no longer valid. In practice, all of these objects should be destroyed with calls to
[CryptDestroyKey](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptdestroykey) and
[CryptDestroyHash](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptdestroyhash) before **CryptReleaseContext** is called.

#### Examples

For an example that uses this function, see [Example C Program: Creating and Hashing a Session Key](https://learn.microsoft.com/windows/desktop/SecCrypto/example-c-program-creating-and-hashing-a-session-key).

## See also

[CryptAcquireContext](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptacquirecontexta)

[CryptDestroyHash](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptdestroyhash)

[CryptDestroyKey](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptdestroykey)

[Service Provider Functions](https://learn.microsoft.com/windows/desktop/SecCrypto/cryptography-functions)