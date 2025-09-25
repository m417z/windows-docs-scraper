# CryptGetMessageCertificates function

## Description

The **CryptGetMessageCertificates** function returns the handle of an open [certificate store](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) containing the message's certificates and [CRLs](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly). This function calls
[CertOpenStore](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certopenstore) using provider type CERT_STORE_PROV_PKCS7 as its *lpszStoreProvider* parameter.

## Parameters

### `dwMsgAndCertEncodingType` [in]

Specifies the encoding type used. It is always acceptable to specify both the certificate and [message encoding types](https://learn.microsoft.com/windows/desktop/SecGloss/m-gly) by combining them with a bitwise-**OR** operation as shown in the following example:

X509_ASN_ENCODING | PKCS_7_ASN_ENCODING

Currently defined encoding types are:

* X509_ASN_ENCODING
* PKCS_7_ASN_ENCODING

### `hCryptProv` [in]

This parameter is not used and should be set to **NULL**.

**Windows Server 2003 and Windows XP:** Handle of the CSP passed to
[CertOpenStore](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certopenstore). For more information, see
[CertOpenStore](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certopenstore).Unless there is a strong reason for passing a specific cryptographic provider in *hCryptProv*, pass zero to cause the default RSA or DSS provider to be acquired.

This parameter's data type is **HCRYPTPROV**.

### `dwFlags` [in]

Flags passed to [CertOpenStore](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certopenstore). For more information, see
[CertOpenStore](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certopenstore).

### `pbSignedBlob` [in]

A pointer to a buffered
[CRYPT_INTEGER_BLOB](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa381414(v=vs.85)) structure that contains the signed message.

### `cbSignedBlob` [in]

The size, in bytes, of the signed message.

## Return value

Returns the [certificate store](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) containing the message's certificates and CRLs. For an error, **NULL** is returned.

The following lists the error code most commonly returned by the
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) function.

| Return code | Description |
| --- | --- |
| **E_INVALIDARG** | Invalid message and certificate encoding types. Currently only PKCS_7_ASN_ENCODING and X509_ASN_ENCODING are supported. |

If the function fails, [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) may return an [Abstract Syntax Notation One](https://learn.microsoft.com/windows/desktop/SecGloss/a-gly) (ASN.1) encoding/decoding error. For information about these errors, see
[ASN.1 Encoding/Decoding Return Values](https://learn.microsoft.com/windows/desktop/SecCrypto/asn-1-encoding-decoding-return-values).

## Remarks

Use
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) to determine the reason for any errors.

#### Examples

For an example that uses this function, see [Example C Program: Setting and Getting Certificate Store Properties](https://learn.microsoft.com/windows/desktop/SecCrypto/example-c-program-setting-and-getting-certificate-store-properties).

## See also

[CryptVerifyMessageSignature](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptverifymessagesignature)

[Simplified Message Functions](https://learn.microsoft.com/windows/desktop/SecCrypto/cryptography-functions)