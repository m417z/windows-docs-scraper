# CryptVerifyDetachedMessageHash function

## Description

The **CryptVerifyDetachedMessageHash** function verifies a detached [hash](https://learn.microsoft.com/windows/desktop/SecGloss/h-gly).

## Parameters

### `pHashPara` [in]

A pointer to a
[CRYPT_HASH_MESSAGE_PARA](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-crypt_hash_message_para) structure containing the hash parameters.

### `pbDetachedHashBlob` [in]

A pointer to the encoded, detached hash.

### `cbDetachedHashBlob` [in]

The size, in bytes, of the detached hash.

### `cToBeHashed` [in]

Number of elements in the *rgpbToBeHashed* and *rgcbToBeHashed* arrays.

### `rgpbToBeHashed` [in]

Array of pointers to content buffers to be hashed.

### `rgcbToBeHashed` [in]

Array of sizes, in bytes, for the content buffers pointed to by the elements of the *rgcbToBeHashed* array.

### `pbComputedHash` [out]

A pointer to a buffer to receive the computed hash.

This parameter can be **NULL** if the newly created hash is not needed for additional processing, or to set the size of the hash for memory allocation purposes. For more information, see
[Retrieving Data of Unknown Length](https://learn.microsoft.com/windows/desktop/SecCrypto/retrieving-data-of-unknown-length).

### `pcbComputedHash` [in, out]

A pointer to a **DWORD** specifying the size, in bytes, of the *pbComputedHash* buffer. When the function returns, this **DWORD** contains the size, in bytes, of the created hash. The hash will not be returned if this parameter is **NULL**.

**Note** When processing the data returned , applications must use the actual size of the data returned. The actual size can be slightly smaller than the size of the buffer specified on input. (On input, buffer sizes are usually specified large enough to ensure that the largest possible output data will fit in the buffer.) On output, the variable pointed to by this parameter is updated to reflect the actual size of the data copied to the buffer.

## Return value

If the function succeeds, the return value is nonzero (TRUE).

If the function fails, the return value is zero (FALSE).

For extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

The following lists the error codes most commonly returned by the
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) function.

| Return code | Description |
| --- | --- |
| **CRYPT_E_UNEXPECTED_MSG_TYPE** | Not a hashed cryptographic message. |
| **E_INVALIDARG** | The [message encoding type](https://learn.microsoft.com/windows/desktop/SecGloss/m-gly) is not valid. Currently only PKCS_7_ASN_ENCODING is supported. The **cbSize** in **pHashPara* is not valid. |
| **ERROR_MORE_DATA** | If the buffer specified by the *pbComputedHash* parameter is not large enough to hold the returned data, the function sets the ERROR_MORE_DATA code, and stores the required buffer size, in bytes, into the variable pointed to by *pcbComputedHash*. |

**Note** Errors from the called functions
[CryptCreateHash](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptcreatehash),
[CryptHashData](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-crypthashdata), and
[CryptGetHashParam](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptgethashparam) might be propagated to this function.

If the function fails, [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) may return an [Abstract Syntax Notation One](https://learn.microsoft.com/windows/desktop/SecGloss/a-gly) (ASN.1) encoding/decoding error. For information about these errors, see
[ASN.1 Encoding/Decoding Return Values](https://learn.microsoft.com/windows/desktop/SecCrypto/asn-1-encoding-decoding-return-values).

## See also

[CryptVerifyMessageHash](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptverifymessagehash)

[Simplified Message Functions](https://learn.microsoft.com/windows/desktop/SecCrypto/cryptography-functions)