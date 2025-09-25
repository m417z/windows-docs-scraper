# CertVerifyTimeValidity function

## Description

The **CertVerifyTimeValidity** function verifies the time validity of a certificate.

## Parameters

### `pTimeToVerify` [in]

A pointer to a [FILETIME](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-filetime) structure containing the comparison time. If **NULL**, the current time is used.

### `pCertInfo` [in]

A pointer to the
[CERT_INFO](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_info) structure of the certificate for which the time is being verified.

## Return value

Returns a minus one if the comparison time is before the **NotBefore** member of the
[CERT_INFO](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_info) structure. Returns a plus one if the comparison time is after the **NotAfter** member. Returns zero for valid time for the certificate.

## See also

[CertVerifyCRLRevocation](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certverifycrlrevocation)

[CertVerifyCRLTimeValidity](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certverifycrltimevalidity)

[CertVerifyValidityNesting](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certverifyvaliditynesting)

[Data Management Functions](https://learn.microsoft.com/windows/desktop/SecCrypto/cryptography-functions)