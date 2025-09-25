# CryptContextAddRef function

## Description

**Important** This API is deprecated. New and existing software should start using [Cryptography Next Generation APIs.](https://learn.microsoft.com/windows/desktop/SecCNG/cng-portal) Microsoft may remove this API in future releases.

The **CryptContextAddRef** function adds one to the [reference count](https://learn.microsoft.com/windows/desktop/SecGloss/r-gly) of an
[HCRYPTPROV](https://learn.microsoft.com/windows/desktop/SecCrypto/hcryptprov) [cryptographic service provider](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) (CSP) handle. This function should be used if the CSP handle is included as a member of any structure passed to another function. The
[CryptReleaseContext](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptreleasecontext) function should be called when the CSP handle is no longer needed.

## Parameters

### `hProv` [in]

[HCRYPTPROV](https://learn.microsoft.com/windows/desktop/SecCrypto/hcryptprov) handle for which the [reference count](https://learn.microsoft.com/windows/desktop/SecGloss/r-gly) is being incremented. This handle must have already been created using
[CryptAcquireContext](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptacquirecontexta).

### `pdwReserved` [in]

Reserved for future use and must be **NULL**.

### `dwFlags` [in]

Reserved for future use and must be zero.

## Return value

If the function succeeds, the return value is nonzero (TRUE).

If the function fails, the return value is zero (FALSE). For extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror). One possible error code is the following.

| Return code | Description |
| --- | --- |
| **ERROR_INVALID_PARAMETER** | One of the parameters contains a value that is not valid. This is most often a pointer that is not valid. |

## Remarks

This function increases the [reference count](https://learn.microsoft.com/windows/desktop/SecGloss/r-gly) on a
[HCRYPTPROV](https://learn.microsoft.com/windows/desktop/SecCrypto/hcryptprov) handle so that multiple calls to
[CryptReleaseContext](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptreleasecontext) are required to actually release the handle.

#### Examples

The following example increments the [reference count](https://learn.microsoft.com/windows/desktop/SecGloss/r-gly) on an acquired CSP handle.

```cpp
//--------------------------------------------------------------------
// hCryptProv is a HCRYPTPROV variable that was previously acquired
// by using CryptAcquireContext or CryptAcquireCertificatePrivateKey.

if(CryptContextAddRef(
       hCryptProv,
       NULL,
       0))
{
    printf("CryptContextAddRef succeeded. \n");
}
else
{
   printf("Error during CryptContextAddRef!\n");
   exit(1);
}
//--------------------------------------------------------------------
//  The reference count on hCryptProv is now greater than one. The
//  first call to CryptReleaseContext will not release the provider
//  handle. A second call to CryptReleaseContext would be needed to
//  release the context.
```

For another example that uses this function, see [Example C Program: Using CryptAcquireContext](https://learn.microsoft.com/windows/desktop/SecCrypto/example-c-program-using-cryptacquirecontext).

## See also

[CryptAcquireContext](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptacquirecontexta)

[CryptReleaseContext](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptreleasecontext)

[Service Provider Functions](https://learn.microsoft.com/windows/desktop/SecCrypto/cryptography-functions)