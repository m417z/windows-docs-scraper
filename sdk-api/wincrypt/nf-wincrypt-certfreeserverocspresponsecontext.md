# CertFreeServerOcspResponseContext function

## Description

The **CertFreeServerOcspResponseContext** function decrements the reference count for a [CERT_SERVER_OCSP_RESPONSE_CONTEXT](https://learn.microsoft.com/windows/win32/api/wincrypt/ns-wincrypt-cert_server_ocsp_response_context) structure. If the reference count becomes zero, memory allocated for the structure is released.

## Parameters

### `pServerOcspResponseContext` [in]

A pointer to a [CERT_SERVER_OCSP_RESPONSE_CONTEXT](https://learn.microsoft.com/windows/win32/api/wincrypt/ns-wincrypt-cert_server_ocsp_response_context) structure that contains a value returned by the [CertGetServerOcspResponseContext](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certgetserverocspresponsecontext) function.