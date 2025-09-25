# CryptDecryptAndVerifyMessageSignature function

## Description

The **CryptDecryptAndVerifyMessageSignature** function decrypts a message and verifies its signature.

## Parameters

### `pDecryptPara` [in]

A pointer to a
[CRYPT_DECRYPT_MESSAGE_PARA](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-crypt_decrypt_message_para) structure that contains decryption parameters.

### `pVerifyPara` [in]

A pointer to a
[CRYPT_VERIFY_MESSAGE_PARA](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-crypt_verify_message_para) structure that contains verification parameters.

### `dwSignerIndex` [in]

Identifies a particular signer of the message. A message can be signed by more than one signer and this function can be called multiple times changing this parameter to check for several signers. It is set to zero for the first signer. If the function returns **FALSE**, and [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) returns CRYPT_E_NO_SIGNER, the previous call received the last signer of the message.

### `pbEncryptedBlob` [in]

A pointer to the signed, encoded, and encrypted message to be decrypted and verified.

### `cbEncryptedBlob` [in]

The size, in bytes, of the encrypted message.

### `pbDecrypted` [out, optional]

A pointer to a buffer to receive the decrypted message.

This parameter can be **NULL** if the decrypted message is not required or to set the size of the decrypted message for memory allocation purposes. A decrypted message will not be returned if this parameter is **NULL**. For more information, see
[Retrieving Data of Unknown Length](https://learn.microsoft.com/windows/desktop/SecCrypto/retrieving-data-of-unknown-length).

### `pcbDecrypted` [in, out, optional]

A pointer to a **DWORD** that specifies the size, in bytes, of the buffer pointed to by the *pbDecrypted* parameter. When the function returns, it contains the size of the decrypted message copied to *pbDecrypted*.

**Note** When processing the data returned in the *pbDecrypted* buffer, applications must use the actual size of the data returned. The actual size can be slightly smaller than the size of the buffer specified in *pcbDecrypted* on input. On output, the variable pointed to by this parameter is set to reflect the actual size of the data copied to the buffer.

### `ppXchgCert` [out, optional]

A pointer to a
[CERT_CONTEXT](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_context) structure of the [certificate](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) that corresponds to the private [exchange key](https://learn.microsoft.com/windows/desktop/SecGloss/e-gly) needed to decrypt the message.

### `ppSignerCert` [out, optional]

A pointer to a [CERT_CONTEXT](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_context) structure of the certificate of the signer.

## Return value

If the function succeeds, the function returns nonzero (**TRUE**).

If the function fails, it returns zero (**FALSE**). For extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

**Note** Errors from the called functions
[CryptDecryptMessage](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptdecryptmessage) and
[CryptVerifyMessageSignature](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptverifymessagesignature) might be propagated to this function.

The [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) function returns the following error code most often.

| Return code | Description |
| --- | --- |
| **ERROR_MORE_DATA** | If the buffer specified by the *pbDecrypted* parameter is not large enough to hold the returned data, the function sets the ERROR_MORE_DATA code, and stores the required buffer size, in bytes, in the variable pointed to by *pcbDecrypted*. |

## Remarks

For a successfully [decrypted](https://learn.microsoft.com/windows/desktop/SecGloss/d-gly) and verified message, the [certificate context](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) pointers pointed to by *ppXchgCert* and *ppSignerCert* are updated. They must be freed by calling
[CertFreeCertificateContext](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certfreecertificatecontext). If the function fails, they are set to **NULL**.

To indicate that the caller is not interested in the exchange certificate or the signer [certificate context](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly), set the *ppXchgCert* and *ppSignerCert* parameters to **NULL**.

#### Examples

For an example that uses this function, see
[Example C Program: Sending and Receiving a Signed and Encrypted Message](https://learn.microsoft.com/windows/desktop/SecCrypto/example-c-program-sending-and-receiving-a-signed-and-encrypted-message).

## See also

[CryptDecryptMessage](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptdecryptmessage)

[CryptSignAndEncryptMessage](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptsignandencryptmessage)

[Simplified Message Functions](https://learn.microsoft.com/windows/desktop/SecCrypto/cryptography-functions)