# CryptDecryptMessage function

## Description

The **CryptDecryptMessage** function [decodes](https://learn.microsoft.com/windows/desktop/SecGloss/d-gly) and [decrypts](https://learn.microsoft.com/windows/desktop/SecGloss/d-gly) a message.

## Parameters

### `pDecryptPara` [in]

A pointer to a
[CRYPT_DECRYPT_MESSAGE_PARA](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-crypt_decrypt_message_para) structure that contains decryption parameters.

### `pbEncryptedBlob` [in]

A pointer to a buffer that contains the [encoded](https://learn.microsoft.com/windows/desktop/SecGloss/e-gly) and [encrypted](https://learn.microsoft.com/windows/desktop/SecGloss/e-gly) message to be decrypted.

### `cbEncryptedBlob` [in]

The size, in bytes, of the encoded and encrypted message.

### `pbDecrypted` [out, optional]

A pointer to a buffer that receives the decrypted message.

To set the size of this information for memory allocation purposes, this parameter can be **NULL**. A decrypted message will not be returned if this parameter is **NULL**. For more information, see
[Retrieving Data of Unknown Length](https://learn.microsoft.com/windows/desktop/SecCrypto/retrieving-data-of-unknown-length).

### `pcbDecrypted` [in, out, optional]

A pointer to a **DWORD** that specifies the size, in bytes, of the buffer pointed to by the *pbDecrypted* parameter. When the function returns, this variable contains the size, in bytes, of the decrypted message copied to *pbDecrypted*.

**Note** When processing the data returned in the *pbDecrypted* buffer, applications must use the actual size of the data returned. The actual size can be slightly smaller than the size of the buffer specified in *pcbDecrypted* on input. On input, buffer sizes are usually specified large enough to ensure that the largest possible output data will fit in the buffer. On output, the **DWORD** is updated to the actual size of the data copied to the buffer.

### `ppXchgCert` [out, optional]

A pointer to a
[CERT_CONTEXT](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_context) structure of a [certificate](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) that corresponds to the private [exchange key](https://learn.microsoft.com/windows/desktop/SecGloss/e-gly) needed to decrypt the message. To indicate that the function should not return the [certificate context](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) used to decrypt, set this parameter to **NULL**.

## Return value

If the function succeeds, the function returns nonzero (**TRUE**).

If the function fails, it returns zero (**FALSE**). For extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

**Note** Errors from calls to
[CryptImportKey](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptimportkey) and
[CryptDecrypt](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptdecrypt) might be propagated to this function.

The [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) function returns the following error codes most often.

| Return code | Description |
| --- | --- |
| **ERROR_MORE_DATA** | If the buffer specified by the *pbDecrypted* parameter is not large enough to hold the returned data, the function sets the ERROR_MORE_DATA code, and stores the required buffer size, in bytes, in the variable pointed to by *pcbDecrypted*. |
| **E_INVALIDARG** | Invalid message and [certificate encoding types](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly). Currently only PKCS_7_ASN_ENCODING and X509_ASN_ENCODING_TYPE are supported. Invalid **cbSize** in **pDecryptPara*. |
| **CRYPT_E_UNEXPECTED_MSG_TYPE** | Not an [enveloped](https://learn.microsoft.com/windows/desktop/SecGloss/e-gly) cryptographic message. |
| **NTE_BAD_ALGID** | The message was encrypted by using an unknown or unsupported algorithm. |
| **CRYPT_E_NO_DECRYPT_CERT** | No certificate was found having a [private key](https://learn.microsoft.com/windows/desktop/SecGloss/p-gly) property to use for decrypting. |

If the function fails, [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) may return an [Abstract Syntax Notation One](https://learn.microsoft.com/windows/desktop/SecGloss/a-gly) (ASN.1) encoding/decoding error. For information about these errors, see
[ASN.1 Encoding/Decoding Return Values](https://learn.microsoft.com/windows/desktop/SecCrypto/asn-1-encoding-decoding-return-values).

## Remarks

When **NULL** is passed for *pbDecrypted*, and *pcbDecrypted* is not **NULL**, **NULL** is returned for the address passed in *ppXchgCert*; otherwise, a pointer to a
[CERT_CONTEXT](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_context) is returned. For a successfully decrypted message, this pointer to a **CERT_CONTEXT** points to the [certificate context](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) used to decrypt the message. It must be freed by calling
[CertFreeCertificateContext](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certfreecertificatecontext). If the function fails, the value at *ppXchgCert* is set to **NULL**.

#### Examples

For an example that uses this function, see
[Example C Program: Using CryptEncryptMessage and CryptDecryptMessage](https://learn.microsoft.com/windows/desktop/SecCrypto/example-c-program-using-cryptencryptmessage-and-cryptdecryptmessage).

## See also

[CryptDecryptAndVerifyMessageSignature](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptdecryptandverifymessagesignature)

[Simplified Message Functions](https://learn.microsoft.com/windows/desktop/SecCrypto/cryptography-functions)