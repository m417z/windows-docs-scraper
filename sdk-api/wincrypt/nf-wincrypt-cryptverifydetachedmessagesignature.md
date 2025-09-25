# CryptVerifyDetachedMessageSignature function

## Description

The **CryptVerifyDetachedMessageSignature** function verifies a signed message containing a detached signature or signatures.

## Parameters

### `pVerifyPara` [in]

A pointer to a
[CRYPT_VERIFY_MESSAGE_PARA](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-crypt_verify_message_para) structure containing the verification parameters.

### `dwSignerIndex` [in]

Index of the signature to be verified. A message might have several signers and this function can be called repeatedly, changing *dwSignerIndex* to verify other signatures. If the function returns FALSE, and [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) returns CRYPT_E_NO_SIGNER, the previous call received the last signer of the message.

### `pbDetachedSignBlob` [in]

A pointer to a BLOB containing the encoded message signatures.

### `cbDetachedSignBlob` [in]

The size, in bytes, of the detached signature.

### `cToBeSigned` [in]

Number of array elements in *rgpbToBeSigned* and *rgcbToBeSigned*.

### `rgpbToBeSigned` [in]

Array of pointers to buffers containing the contents to be [hashed](https://learn.microsoft.com/windows/desktop/SecGloss/h-gly).

### `rgcbToBeSigned` [in]

Array of sizes, in bytes, for the content buffers pointed to in *rgpbToBeSigned*.

### `ppSignerCert` [out, optional]

A pointer to a
pointer to a [CERT_CONTEXT](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_context) structure of a signer certificate. When you have finished using the certificate context, free it by calling the [CertFreeCertificateContext](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certfreecertificatecontext) function. A pointer to a **CERT_CONTEXT** structure will not be returned if this parameter is **NULL**.

## Return value

If the function succeeds, the return value is nonzero (TRUE).

If the function fails, the return value is zero (**FALSE**).

For extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

The following lists the error codes most commonly returned by the
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) function.

| Return code | Description |
| --- | --- |
| **E_INVALIDARG** | Invalid message and certificate encoding types. Currently only PKCS_7_ASN_ENCODING and X509_ASN_ENCODING_TYPE are supported. Invalid **cbSize** in **pVerifyPara*. |
| **CRYPT_E_UNEXPECTED_MSG_TYPE** | Not a signed cryptographic message. |
| **CRYPT_E_NO_SIGNER** | The message does not have any signers or a signer for the specified *dwSignerIndex*. |
| **NTE_BAD_ALGID** | The message was hashed and signed by using an unknown or unsupported algorithm. |
| **NTE_BAD_SIGNATURE** | The message's signature was not verified. |

**Note** Errors from the called functions
[CryptCreateHash](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptcreatehash),
[CryptHashData](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-crypthashdata),
[CryptVerifySignature](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptverifysignaturea), and
[CryptImportKey](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptimportkey) might be propagated to this function.

If the function fails, [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) may return an [Abstract Syntax Notation One](https://learn.microsoft.com/windows/desktop/SecGloss/a-gly) (ASN.1) encoding/decoding error. For information about these errors, see
[ASN.1 Encoding/Decoding Return Values](https://learn.microsoft.com/windows/desktop/SecCrypto/asn-1-encoding-decoding-return-values).

## See also

[CryptVerifyMessageSignature](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptverifymessagesignature)

[Simplified Message Functions](https://learn.microsoft.com/windows/desktop/SecCrypto/cryptography-functions)