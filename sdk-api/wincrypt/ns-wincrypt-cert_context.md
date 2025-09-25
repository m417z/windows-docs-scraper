# CERT_CONTEXT structure

## Description

The **CERT_CONTEXT** structure contains both the encoded and decoded representations of a [certificate](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly). A certificate [context](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) returned by one of the functions defined in Wincrypt.h must be freed by calling the
[CertFreeCertificateContext](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certfreecertificatecontext) function. The
[CertDuplicateCertificateContext](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certduplicatecertificatecontext) function can be called to make a duplicate copy (which also must be freed by calling **CertFreeCertificateContext**).

## Members

### `dwCertEncodingType`

Type of encoding used. It is always acceptable to specify both the certificate and [message encoding types](https://learn.microsoft.com/windows/desktop/SecGloss/m-gly) by combining them with a bitwise-**OR** operation as shown in the following example:

X509_ASN_ENCODING | PKCS_7_ASN_ENCODING Currently defined encoding types are:

* X509_ASN_ENCODING
* PKCS_7_ASN_ENCODING

### `pbCertEncoded`

A pointer to a buffer that contains the encoded certificate.

### `cbCertEncoded`

The size, in bytes, of the encoded certificate.

### `pCertInfo`

The address of a [CERT_INFO](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_info) structure that contains the certificate information.

### `hCertStore`

A handle to the [certificate store](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) that contains the certificate [context](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly).

## See also

[CERT_INFO](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_info)

[CRYPT_SIGN_MESSAGE_PARA](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-crypt_sign_message_para)

[CRYPT_VERIFY_MESSAGE_PARA](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-crypt_verify_message_para)

[CertAddCertificateContextToStore](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certaddcertificatecontexttostore)

[CertAddEncodedCertificateToStore](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certaddencodedcertificatetostore)

[CertCreateCertificateContext](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certcreatecertificatecontext)

[CertEnumCertificatesInStore](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certenumcertificatesinstore)

[CertFindCertificateInStore](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certfindcertificateinstore)

[CertFreeCertificateContext](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certfreecertificatecontext)

[CertGetIssuerCertificateFromStore](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certgetissuercertificatefromstore)

[CertGetSubjectCertificateFromStore](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certgetsubjectcertificatefromstore)

[CertVerifyRevocation](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certverifyrevocation)

[CryptVerifyMessageSignature](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptverifymessagesignature)