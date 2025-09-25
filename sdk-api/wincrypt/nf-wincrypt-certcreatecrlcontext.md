# CertCreateCRLContext function

## Description

The **CertCreateCRLContext** function creates a [certificate revocation list](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) (CRL) [context](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) from an encoded CRL. The created context is not persisted to a [certificate store](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly). It makes a copy of the encoded CRL within the created context.

## Parameters

### `dwCertEncodingType` [in]

Specifies the type of encoding used. It is always acceptable to specify both the certificate and [message encoding types](https://learn.microsoft.com/windows/desktop/SecGloss/m-gly) by combining them with a bitwise-**OR** operation as shown in the following example:

X509_ASN_ENCODING | PKCS_7_ASN_ENCODING Currently defined encoding types are:

* X509_ASN_ENCODING
* PKCS_7_ASN_ENCODING

### `pbCrlEncoded` [in]

A pointer to a buffer containing the encoded [CRL](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) from which the context is to be created.

### `cbCrlEncoded` [in]

The size, in bytes, of the *pbCrlEncoded* buffer.

## Return value

If the function succeeds, the return value is a pointer to a read-only
[CRL_CONTEXT](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-crl_context).

If the function fails and is unable to decode and create the [CRL_CONTEXT](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-crl_context), the return value is **NULL**. For extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror). The following table shows a possible error code.

| Return code | Description |
| --- | --- |
| **E_INVALIDARG** | Invalid certificate encoding type. Currently, only the encoding type X509_ASN_ENCODING is supported. |

If the function fails, [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) may return an [Abstract Syntax Notation One](https://learn.microsoft.com/windows/desktop/SecGloss/a-gly) (ASN.1) encoding/decoding error. For information about these errors, see
[ASN.1 Encoding/Decoding Return Values](https://learn.microsoft.com/windows/desktop/SecCrypto/asn-1-encoding-decoding-return-values).

## Remarks

The
[CRL_CONTEXT](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-crl_context) must be freed by calling
[CertFreeCRLContext](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certfreecrlcontext).
[CertDuplicateCRLContext](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certduplicatecrlcontext) can be called to make a duplicate.
[CertSetCRLContextProperty](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certsetcrlcontextproperty) and
[CertGetCRLContextProperty](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certgetcrlcontextproperty) can be called to store and read properties for the CRL.

## See also

[CRL_CONTEXT](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-crl_context)

[CertCreateCTLContext](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certcreatectlcontext)

[CertCreateCertificateContext](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certcreatecertificatecontext)

[CertDuplicateCRLContext](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certduplicatecrlcontext)

[CertFreeCRLContext](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certfreecrlcontext)

[CertGetCRLContextProperty](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certgetcrlcontextproperty)

[CertSetCRLContextProperty](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certsetcrlcontextproperty)

[Certificate Revocation List Functions](https://learn.microsoft.com/windows/desktop/SecCrypto/cryptography-functions)