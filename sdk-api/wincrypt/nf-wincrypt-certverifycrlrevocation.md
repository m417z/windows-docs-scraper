# CertVerifyCRLRevocation function

## Description

The **CertVerifyCRLRevocation** function check a [certificate revocation list](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) (CRL) to determine whether a subject's certificate has or has not been revoked. The new
[Certificate Chain Verification Functions](https://learn.microsoft.com/windows/desktop/SecCrypto/cryptography-functions) are recommended instead of the use of this function.

## Parameters

### `dwCertEncodingType` [in]

Specifies the encoding type used. It is always acceptable to specify both the certificate and [message encoding types](https://learn.microsoft.com/windows/desktop/SecGloss/m-gly) by combining them with a bitwise-**OR** operation as shown in the following example:

X509_ASN_ENCODING | PKCS_7_ASN_ENCODING

Currently defined encoding types are:

* X509_ASN_ENCODING
* PKCS_7_ASN_ENCODING

### `pCertId` [in]

A pointer to the
[CERT_INFO](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_info) structure of the certificate to be checked against the CRL.

### `cCrlInfo` [in]

Number of
[CRL_INFO](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-crl_info) pointers in the *rgpCrlInfo* array.

### `rgpCrlInfo` [in]

Array of pointers to [CRL_INFO](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-crl_info) structures.

## Return value

Returns **TRUE** if the certificate is not on the CRL and therefore is valid.

It returns **FALSE** if the certificate is on the list and therefore has been revoked and is not valid.

## See also

[CertVerifyCRLTimeValidity](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certverifycrltimevalidity)

[CertVerifyTimeValidity](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certverifytimevalidity)

[CertVerifyValidityNesting](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certverifyvaliditynesting)

[Data Management Functions](https://learn.microsoft.com/windows/desktop/SecCrypto/cryptography-functions)