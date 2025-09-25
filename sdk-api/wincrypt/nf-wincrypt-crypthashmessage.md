# CryptHashMessage function

## Description

The **CryptHashMessage** function creates a [hash](https://learn.microsoft.com/windows/desktop/SecGloss/h-gly) of the message.

## Parameters

### `pHashPara` [in]

A pointer to a
[CRYPT_HASH_MESSAGE_PARA](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-crypt_hash_message_para) structure that contains the hash parameters.

### `fDetachedHash` [in]

If this parameter is set to **TRUE**, only *pbComputedHash* is encoded in *pbHashedBlob*. Otherwise, both *rgpbToBeHashed* and *pbComputedHash* are encoded.

### `cToBeHashed` [in]

The number of array elements in *rgpbToBeHashed* and *rgcbToBeHashed*. This parameter can only be one unless *fDetachedHash* is set to **TRUE**.

### `rgpbToBeHashed` [in]

An array of pointers to buffers that contain the contents to be hashed.

### `rgcbToBeHashed` [in]

An array of sizes, in bytes, of the buffers pointed to by *rgpbToBeHashed*.

### `pbHashedBlob` [out]

A pointer to a buffer to receive the hashed message encoded for transmission.

This parameter can be **NULL** if the hashed message is not needed for additional processing or to set the size of the hashed message for memory allocation purposes. A hashed message will not be returned if this parameter is **NULL**. For more information, see
[Retrieving Data of Unknown Length](https://learn.microsoft.com/windows/desktop/SecCrypto/retrieving-data-of-unknown-length).

### `pcbHashedBlob` [in, out]

A pointer to a **DWORD** that specifies the size, in bytes, of the buffer pointed to by the *pbHashedBlob* parameter. When the function returns, this variable contains the size, in bytes, of the decrypted message copied to *pbHashedBlob*. This parameter must be the address of a **DWORD** and not **NULL** or the length of the buffer will not be returned.

**Note** When processing the data returned, applications must use the actual size of the data returned. The actual size can be slightly smaller than the size of the buffer specified on input. On input, buffer sizes are usually specified large enough to ensure that the largest possible output data will fit in the buffer. On output, the variable pointed to by this parameter is updated to reflect the actual size of the data copied to the buffer.

### `pbComputedHash` [out, optional]

A pointer to a buffer to receive the newly created hash value. This parameter can be **NULL** if the newly created hash is not needed for additional processing, or to set the size of the hash for memory allocation purposes. For more information, see
[Retrieving Data of Unknown Length](https://learn.microsoft.com/windows/desktop/SecCrypto/retrieving-data-of-unknown-length).

### `pcbComputedHash` [in, out, optional]

A pointer to a **DWORD** that specifies the size, in bytes, of the buffer pointed to by the *pbComputedHash* parameter. When the function returns, this **DWORD** contains the size, in bytes, of the newly created hash that was copied to *pbComputedHash*.

**Note** When processing the data returned, applications must use the actual size of the data returned. The actual size can be slightly smaller than the size of the buffer specified on input. On input, buffer sizes are usually specified large enough to ensure that the largest possible output data will fit in the buffer. On output, the variable pointed to by this parameter is updated to reflect the actual size of the data copied to the buffer.

## Return value

If the function succeeds, the function returns nonzero (**TRUE**).

If the function fails, it returns zero (**FALSE**). For extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

**Note** Errors from the called functions
[CryptCreateHash](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptcreatehash),
[CryptHashData](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-crypthashdata), and
[CryptGetHashParam](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptgethashparam) might be propagated to this function.

The [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) function returns the following error codes most often.

| Return code | Description |
| --- | --- |
| **E_INVALIDARG** | The [message encoding type](https://learn.microsoft.com/windows/desktop/SecGloss/m-gly) is not valid. Currently only PKCS_7_ASN_ENCODING is supported. The **cbSize** in **pHashPara* is not valid. |
| **ERROR_MORE_DATA** | If the buffer specified by the *pbHashedBlob* parameter is not large enough to hold the returned data, the function sets the ERROR_MORE_DATA code and stores the required buffer size, in bytes, into the variable pointed to by *pbHashedBlob*. |

If the function fails, [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) may return an [Abstract Syntax Notation One](https://learn.microsoft.com/windows/desktop/SecGloss/a-gly) (ASN.1) encoding/decoding error. For information about these errors, see
[ASN.1 Encoding/Decoding Return Values](https://learn.microsoft.com/windows/desktop/SecCrypto/asn-1-encoding-decoding-return-values).

## See also

[CryptVerifyDetachedMessageHash](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptverifydetachedmessagehash)

[CryptVerifyMessageHash](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptverifymessagehash)

[Simplified Message Functions](https://learn.microsoft.com/windows/desktop/SecCrypto/cryptography-functions)