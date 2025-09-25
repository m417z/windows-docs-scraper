# CertGetServerOcspResponseContext function

## Description

The **CertGetServerOcspResponseContext** function retrieves a non-blocking, time valid [online certificate status protocol](https://learn.microsoft.com/windows/desktop/SecGloss/o-gly) (OCSP) response context for the specified handle.

## Parameters

### `hServerOcspResponse` [in]

The OCSP server response handle for which to retrieve a response context. This handle is returned by the [CertOpenServerOcspResponse](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certopenserverocspresponse) function.

### `dwFlags` [in]

This parameter is reserved for future use and must be zero.

### `pvReserved`

This parameter is reserved for future use and must be **NULL**.

## Return value

If the function succeeds, it returns a pointer to a [CERT_SERVER_OCSP_RESPONSE_CONTEXT](https://learn.microsoft.com/windows/win32/api/wincrypt/ns-wincrypt-cert_server_ocsp_response_context) structure.

For a response to be time valid, the current time on the system hosting this function call must be less than the next update time for the [certificate revocation list](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) (CRL) context. When a time valid OCSP response
is not available, this function returns **NULL** with the last error set to
CRYPT_E_REVOCATION_OFFLINE.

If the certificate is unknown by the OCSP responder, this function returns **NULL** with the last error set to CRYPT_E_REVOCATION_OFFLINE.

## Remarks

If you use the **CertGetServerOcspResponseContext** function to create multiple references to an OCSP response context, you must call [CertAddRefServerOcspResponseContext](https://learn.microsoft.com/windows/win32/api/wincrypt/ns-wincrypt-cert_server_ocsp_response_context) to increment the reference count for the [CERT_SERVER_OCSP_RESPONSE_CONTEXT](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_server_ocsp_response_context) structure. When you have finished using the structure, you must free it by calling the [CertFreeServerOcspResponseContext](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certfreeserverocspresponsecontext) function.