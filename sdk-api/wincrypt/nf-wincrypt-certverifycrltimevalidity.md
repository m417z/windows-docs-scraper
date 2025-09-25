# CertVerifyCRLTimeValidity function

## Description

The **CertVerifyCRLTimeValidity** function verifies the time validity of a CRL.

## Parameters

### `pTimeToVerify` [in]

A pointer to [FILETIME](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-filetime) structure containing the time to be used in the verification. If set to **NULL**, the current time is used.

### `pCrlInfo` [in]

A pointer to a
[CRL_INFO](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-crl_info) structure containing the CRL for which the time is to be verified.

## Return value

Returns a minus one (–1) if the comparison time is before the **ThisUpdate** member of the [CRL_INFO](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-crl_info) pointed to by *pCrlInfo*. Returns a plus one (+1) if the comparison time is after the **NextUpdate** time. Returns zero for valid time for the CRL.

## See also

[CertVerifyCRLRevocation](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certverifycrlrevocation)

[CertVerifyTimeValidity](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certverifytimevalidity)

[CertVerifyValidityNesting](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certverifyvaliditynesting)

[Data Management Functions](https://learn.microsoft.com/windows/desktop/SecCrypto/cryptography-functions)