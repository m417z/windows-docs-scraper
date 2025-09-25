# CRL_CONTEXT structure

## Description

The **CRL_CONTEXT** structure contains both the encoded and decoded representations of a [certificate revocation list](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) (CRL). CRL contexts returned by any CryptoAPI function must be freed by calling the
[CertFreeCRLContext](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certfreecrlcontext) function.

## Members

### `dwCertEncodingType`

Type of encoding used. It is always acceptable to specify both the certificate and [message encoding types](https://learn.microsoft.com/windows/desktop/SecGloss/m-gly) by combining them with a bitwise-**OR** operation as shown in the following example:

X509_ASN_ENCODING | PKCS_7_ASN_ENCODING

Currently defined encoding types are:

* X509_ASN_ENCODING
* PKCS_7_ASN_ENCODING

### `pbCrlEncoded`

A pointer to the encoded CRL information.

### `cbCrlEncoded`

The size, in bytes, of the encoded CRL information.

### `pCrlInfo`

A pointer to
[CRL_INFO](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-crl_info) structure containing the CRL information.

### `hCertStore`

A handle to the [certificate store](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly).

## See also

[CRL_INFO](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-crl_info)

[CRYPT_SIGN_MESSAGE_PARA](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-crypt_sign_message_para)

[CertAddCRLContextToStore](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certaddcrlcontexttostore)

[CertAddEncodedCRLToStore](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certaddencodedcrltostore)

[CertCreateCRLContext](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certcreatecrlcontext)

[CertFreeCRLContext](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certfreecrlcontext)

[CertGetCRLFromStore](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certgetcrlfromstore)