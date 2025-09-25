# CryptVerifyMessageSignature function

## Description

The **CryptVerifyMessageSignature** function verifies a signed message's signature.

This function should not be used to verify the signature of a detached message. You should use the [CryptVerifyDetachedMessageSignature](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptverifydetachedmessagesignature) function to verify the signature of a detached message.

## Parameters

### `pVerifyPara` [in]

A pointer to a
[CRYPT_VERIFY_MESSAGE_PARA](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-crypt_verify_message_para) structure that contains verification parameters.

### `dwSignerIndex` [in]

The index of the desired signature. There can be more than one signature. **CryptVerifyMessageSignature** can be called repeatedly, incrementing *dwSignerIndex* each time. Set this parameter to zero for the first signer, or if there is only one signer. If the function returns **FALSE**, and [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) returns CRYPT_E_NO_SIGNER, the previous call processed the last signer of the message.

### `pbSignedBlob` [in]

A pointer to a buffer that contains the signed message.

### `cbSignedBlob` [in]

The size, in bytes, of the signed message buffer.

### `pbDecoded` [out]

A pointer to a buffer to receive the decoded message.

This parameter can be **NULL** if the decoded message is not needed for additional processing or to set the size of the message for memory allocation purposes. For more information, see
[Retrieving Data of Unknown Length](https://learn.microsoft.com/windows/desktop/SecCrypto/retrieving-data-of-unknown-length).

### `pcbDecoded` [in, out]

A pointer to a **DWORD** value that specifies the size, in bytes, of the *pbDecoded* buffer. When the function returns, this **DWORD** contains the size, in bytes, of the decoded message. The decoded message will not be returned if this parameter is **NULL**.

**Note** When processing the data returned, applications must use the actual size of the data returned. The actual size can be slightly smaller than the size of the buffer specified on input. (On input, buffer sizes are usually specified large enough to ensure that the largest possible output data will fit in the buffer.) On output, the variable pointed to by this parameter is updated to reflect the actual size of the data copied to the buffer.

### `ppSignerCert` [out, optional]

The address of a [CERT_CONTEXT](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_context) structure pointer that receives the certificate of the signer. When you have finished using this structure, free it by passing this pointer to the [CertFreeCertificateContext](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certfreecertificatecontext) function. This parameter can be **NULL** if the signer's certificate is not needed.

## Return value

If the function succeeds, the function returns nonzero. This does not necessarily mean that the signature was verified. In the case of a detached message, the variable pointed to by *pcbDecoded* will contain zero. In this case, this function will return nonzero, but the signature is not verified. To verify the signature of a detached message, use the [CryptVerifyDetachedMessageSignature](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptverifydetachedmessagesignature) function.

If the function fails, it returns zero. For extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

The following table shows the error codes most commonly returned by the
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) function.

| Return code | Description |
| --- | --- |
| **ERROR_MORE_DATA** | If the buffer specified by the *pbDecoded* parameter is not large enough to hold the returned data, the function sets the ERROR_MORE_DATA code, and stores the required buffer size, in bytes, in the variable pointed to by *pcbDecoded*. |
| **E_INVALIDARG** | Invalid message and certificate encoding types. Currently only PKCS_7_ASN_ENCODING and X509_ASN_ENCODING_TYPE are supported. Invalid **cbSize** in **pVerifyPara*. |
| **CRYPT_E_UNEXPECTED_MSG_TYPE** | Not a signed cryptographic message. |
| **CRYPT_E_NO_SIGNER** | The message does not have any signers or a signer for the specified *dwSignerIndex*. |
| **NTE_BAD_ALGID** | The message was hashed and signed by using an unknown or unsupported algorithm. |
| **NTE_BAD_SIGNATURE** | The message's signature was not verified. |

**Note** Errors from the called functions
[CryptCreateHash](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptcreatehash),
[CryptHashData](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-crypthashdata),
[CryptVerifySignature](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptverifysignaturea), and
[CryptImportKey](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptimportkey) can be propagated to this function.

If the function fails, [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) may return an [Abstract Syntax Notation One](https://learn.microsoft.com/windows/desktop/SecGloss/a-gly) (ASN.1) encoding/decoding error. For information about these errors, see
[ASN.1 Encoding/Decoding Return Values](https://learn.microsoft.com/windows/desktop/SecCrypto/asn-1-encoding-decoding-return-values).

## Remarks

For a verified signer and message, *ppSignerCert* is updated with the
[CERT_CONTEXT](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_context) of the signer. It must be freed by calling
[CertFreeCertificateContext](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certfreecertificatecontext). Otherwise, *ppSignerCert* is set to **NULL**.

For a message that contains only certificates and [CRLs](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly), *pcbDecoded* is set to **NULL**.

#### Examples

For an example that uses this function, see
[Example C Program: Signing a Message and Verifying a Message Signature](https://learn.microsoft.com/windows/desktop/SecCrypto/example-c-program-signing-a-message-and-verifying-a-message-signature).

## See also

[CryptSignMessage](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptsignmessage)

[CryptVerifyDetachedMessageSignature](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptverifydetachedmessagesignature)

[Simplified Message Functions](https://learn.microsoft.com/windows/desktop/SecCrypto/cryptography-functions)