# CertAddRefServerOcspResponse function

## Description

The **CertAddRefServerOcspResponse** function increments the reference count for an **HCERT_SERVER_OCSP_RESPONSE** handle.

## Parameters

### `hServerOcspResponse` [in]

A handle to an **HCERT_SERVER_OCSP_RESPONSE** returned by [CertOpenServerOcspResponse](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certopenserverocspresponse).

## Remarks

Each [CertOpenServerOcspResponse](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certopenserverocspresponse) and **CertAddRefServerOcspResponse** requires a corresponding [CertCloseServerOcspResponse](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certcloseserverocspresponse).