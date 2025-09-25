# CertVerifyValidityNesting function

## Description

The **CertVerifyValidityNesting** function verifies that a subject certificate's time validity nests correctly within its issuer's time validity.

## Parameters

### `pSubjectInfo` [in]

A pointer to the
[CERT_INFO](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_info) structure of the subject certificate.

### `pIssuerInfo` [in]

A pointer to the [CERT_INFO](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_info) structure of the issuer certificate.

## Return value

Returns **TRUE** if the **NotBefore** time of the subject's certificate is after the **NotBefore** time of the issuer's certificate and the **NotAfter** time of the subject's certificate is not after the **NotAfter** time of the issuer's certificate. Otherwise, returns **FALSE**.

## See also

[CertVerifyCRLRevocation](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certverifycrlrevocation)

[CertVerifyCRLTimeValidity](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certverifycrltimevalidity)

[CertVerifyTimeValidity](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certverifytimevalidity)

[Data Management Functions](https://learn.microsoft.com/windows/desktop/SecCrypto/cryptography-functions)