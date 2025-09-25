# CertAddRefServerOcspResponseContext function

## Description

The **CertAddRefServerOcspResponseContext** function increments the reference count for a [CERT_SERVER_OCSP_RESPONSE_CONTEXT](https://learn.microsoft.com/windows/win32/api/wincrypt/ns-wincrypt-cert_server_ocsp_response_context) structure.

## Parameters

### `pServerOcspResponseContext` [in]

A pointer to a [CERT_SERVER_OCSP_RESPONSE_CONTEXT](https://learn.microsoft.com/windows/win32/api/wincrypt/ns-wincrypt-cert_server_ocsp_response_context) returned by [CertGetServerOcspResponseContext](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certgetserverocspresponsecontext).

## Remarks

Each call to [CertGetServerOcspResponseContext](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certgetserverocspresponsecontext) and **CertAddRefServerOcspResponseContext** requires a corresponding call to [CertFreeServerOcspResponseContext](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certfreeserverocspresponsecontext).