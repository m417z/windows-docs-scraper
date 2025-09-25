# CertCloseServerOcspResponse function

## Description

The **CertCloseServerOcspResponse** function closes an [online certificate status protocol](https://learn.microsoft.com/windows/desktop/SecGloss/o-gly) (OCSP) server response handle.

## Parameters

### `hServerOcspResponse` [in]

The handle to close for an OCSP server response.

### `dwFlags` [in]

This parameter is not used and must be zero.

## Remarks

The **CertCloseServerOcspResponse** function closes a handle returned by either the [CertOpenServerOcspResponse](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certopenserverocspresponse) or [CertAddRefServerOcspResponse](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certaddrefserverocspresponse) function.

## See also

[CertOpenServerOcspResponse](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certopenserverocspresponse)