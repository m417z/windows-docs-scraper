# CryptSignAndEncryptMessage function

## Description

The **CryptSignAndEncryptMessage** function creates a [hash](https://learn.microsoft.com/windows/desktop/SecGloss/h-gly) of the specified content, signs the hash, encrypts the content, hashes the encrypted contents and the signed hash, and then encodes both the encrypted content and the signed hash. The result is the same as if the hash were first signed and then encrypted.

## Parameters

### `pSignPara` [in]

A pointer to a
[CRYPT_SIGN_MESSAGE_PARA](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-crypt_sign_message_para) structure that contains the signature parameters.

### `pEncryptPara` [in]

A pointer to a
[CRYPT_ENCRYPT_MESSAGE_PARA](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-crypt_encrypt_message_para) structure containing encryption parameters.

### `cRecipientCert` [in]

Number of array elements in *rgpRecipientCert*.

### `rgpRecipientCert` [in]

Array of pointers to
[CERT_CONTEXT](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_context) structures. Each structure is the certificate of an intended recipients of the message.

### `pbToBeSignedAndEncrypted` [in]

A pointer to a buffer containing the content to be signed and encrypted.

### `cbToBeSignedAndEncrypted` [in]

The size, in bytes, of the *pbToBeSignedAndEncrypted* buffer.

### `pbSignedAndEncryptedBlob` [out]

A pointer to a buffer to receive the encrypted and encoded message.

This parameter can be **NULL** to set the size of this information for memory allocation purposes. For more information, see
[Retrieving Data of Unknown Length](https://learn.microsoft.com/windows/desktop/SecCrypto/retrieving-data-of-unknown-length).

### `pcbSignedAndEncryptedBlob` [in, out]

A pointer to **DWORD** specifying the size, in bytes, of the buffer pointed to by *pbSignedAndEncryptedBlob*. When the function returns, this variable contains the size, in bytes, of the signed and encrypted message copied to **pbSignedAndEncryptedBlob*.

**Note** When processing the data returned, applications must use the actual size of the data returned. The actual size can be slightly smaller than the size of the buffer specified on input. (On input, buffer sizes are usually specified large enough to ensure that the largest possible output data will fit in the buffer.) On output, the variable pointed to by this parameter is updated to reflect the actual size of the data copied to the buffer.

## Return value

If the function succeeds, the return value is nonzero (TRUE).

If the function fails, the return value is zero (FALSE).

For extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

The following lists the error code most commonly returned by the
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) function.

| Return code | Description |
| --- | --- |
| **ERROR_MORE_DATA** | If the buffer specified by the *pbSignedAndEncryptedBlob* parameter is not large enough to hold the returned data, the function sets the ERROR_MORE_DATA code, and stores the required buffer size, in bytes, into the variable pointed to by *pcbSignedAndEncryptedBlob*. |

**Note** Errors from the called functions
[CryptSignMessage](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptsignmessage) and
[CryptEncryptMessage](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptencryptmessage) might be propagated to this function.

## See also

[CryptDecryptAndVerifyMessageSignature](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptdecryptandverifymessagesignature)

[CryptSignMessage](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptsignmessage)

[Simplified Message Functions](https://learn.microsoft.com/windows/desktop/SecCrypto/cryptography-functions)