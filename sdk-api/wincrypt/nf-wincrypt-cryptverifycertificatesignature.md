# CryptVerifyCertificateSignature function

## Description

The **CryptVerifyCertificateSignature** function verifies the signature of a certificate, [certificate revocation list](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) (CRL), or [certificate request](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) by using the [public key](https://learn.microsoft.com/windows/desktop/SecGloss/p-gly) in a
[CERT_PUBLIC_KEY_INFO](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_public_key_info) structure. The function does not require access to a [private key](https://learn.microsoft.com/windows/desktop/SecGloss/p-gly).

## Parameters

### `hCryptProv` [in]

This parameter is not used and should be set to **NULL**.

**Windows Server 2003 and Windows XP:** A handle to the [cryptographic service provider](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) (CSP) used to verify the signature.This parameter's data type is **HCRYPTPROV**.

**NULL** is passed unless there is a strong reason for passing in a specific cryptographic provider. Passing in **NULL** causes the default RSA or DSS provider to be acquired.

### `dwCertEncodingType` [in]

The [certificate encoding type](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) that was used to encrypt the subject. The [message encoding type](https://learn.microsoft.com/windows/desktop/SecGloss/m-gly) identifier, contained in the high **WORD** of this value, is ignored by this function.

This parameter can be the following currently defined certificate encoding type.

| Value | Meaning |
| --- | --- |
| **X509_ASN_ENCODING**<br><br>1 (0x1) | Specifies [X.509](https://learn.microsoft.com/windows/desktop/SecGloss/x-gly) certificate encoding. |

### `pbEncoded` [in]

A pointer to an encoded [BLOB](https://learn.microsoft.com/windows/desktop/SecGloss/b-gly) of [CERT_SIGNED_CONTENT_INFO](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_signed_content_info) content on which the signature is to be verified.

### `cbEncoded` [in]

The size, in bytes, of the encoded content in *pbEncoded*.

### `pPublicKey` [in]

A pointer to a
[CERT_PUBLIC_KEY_INFO](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_public_key_info) structure that contains the public key to use when verifying the signature.

## Return value

Returns nonzero if successful or zero otherwise.

For extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

**Note** Errors from the called functions
[CryptCreateHash](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptcreatehash),
[CryptImportKey](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptimportkey),
[CryptVerifySignature](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptverifysignaturea), and
[CryptHashData](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-crypthashdata) may be propagated to this function.

On failure, this function will cause the following error codes to be returned from [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

| Return code | Description |
| --- | --- |
| **ERROR_FILE_NOT_FOUND** | Invalid certificate encoding type. Currently only **X509_ASN_ENCODING** is supported. |
| **NTE_BAD_ALGID** | The signature algorithm's [object identifier](https://learn.microsoft.com/windows/desktop/SecGloss/o-gly) (OID) does not map to a known or supported [hash](https://learn.microsoft.com/windows/desktop/SecGloss/h-gly) algorithm. |
| **NTE_BAD_SIGNATURE** | The signature was not valid. |

If the function fails, [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) may return an [Abstract Syntax Notation One](https://learn.microsoft.com/windows/desktop/SecGloss/a-gly) (ASN.1) encoding/decoding error. For information about these errors, see
[ASN.1 Encoding/Decoding Return Values](https://learn.microsoft.com/windows/desktop/SecCrypto/asn-1-encoding-decoding-return-values).

## Remarks

This function currently calls the
[CryptVerifyCertificateSignatureEx](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptverifycertificatesignatureex) function to perform the verification.

## See also

[CryptVerifyCertificateSignatureEx](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptverifycertificatesignatureex)