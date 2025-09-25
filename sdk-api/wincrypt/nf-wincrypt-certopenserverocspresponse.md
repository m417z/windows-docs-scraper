# CertOpenServerOcspResponse function

## Description

The **CertOpenServerOcspResponse** function opens a handle to an [online certificate status protocol](https://learn.microsoft.com/windows/desktop/SecGloss/o-gly) (OCSP) response associated with a server certificate chain.

## Parameters

### `pChainContext` [in]

The address of a [CERT_CHAIN_CONTEXT](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_chain_context) structure that contains the certificate chain.

### `dwFlags` [in]

| Value | Meaning |
| --- | --- |
| **0**<br><br>0x00000000 | This API will try to retrieve an initial OCSP response before returning, which means it will block during the retrieval. |
| **CERT_SERVER_OCSP_RESPONSE_ASYNC_FLAG**<br><br>0x00000001 | Set this flag to return immediately without making the initial synchronous retrieval. |

### `pOpenPara`

This parameter is not used and must be **NULL**.

## Return value

Returns a handle to the OCSP response associated with a server certificate chain if successful; otherwise, **NULL**. This handle must be passed to the [CertCloseServerOcspResponse](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certcloseserverocspresponse) function when it is no longer needed.

For extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror). Possible error codes returned by the
**GetLastError** function include, but are not limited to, the following.

| Return code | Description |
| --- | --- |
| **ERROR_INVALID_PARAMETER** | One or more parameters are not valid. |
| **CRYPT_E_NOT_IN_REVOCATION_DATABASE** | The end certificate does not contain an OCSP authority information access (AIA) URL. |

## Remarks

When the **dwFlags** is set to 0, the **CertOpenServerOcspResponse** function tries to retrieve an initial OCSP response before it returns.
It blocks its process thread during the retrieval. The **CertOpenServerOcspResponse** function creates a background thread that prefetches time-valid OCSP responses. If unable to successfully retrieve the first OCSP response, a non-NULL handle will still be returned if not one of the error cases mentioned above.

When the **dwFlags** is set to 1 or **CERT_SERVER_OCSP_RESPONSE_ASYNC_FLAG**, the **CertOpenServerOcspResponse** function will return immediately without making the initial synchronous retrieval.

The **CertOpenServerOcspResponse** function increments the reference count for the chain context represented by the *pChainContext* parameter. When you have finished using the chain context, close the returned handle by calling the [CertCloseServerOcspResponse](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certcloseserverocspresponse) function.

The **CertOpenServerOcspResponse** function initializes configuration settings used by the following functions:

* [CertAddRefServerOcspResponse](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certaddrefserverocspresponse)
* [CertCloseServerOcspResponse](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certcloseserverocspresponse)
* [CertGetServerOcspResponseContext](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certgetserverocspresponsecontext)
* [CertAddRefServerOcspResponseContext](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certaddrefserverocspresponsecontext)
* [CertFreeServerOcspResponseContext](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certfreeserverocspresponsecontext)

First, the **CertOpenServerOcspResponse** function initializes the settings based on default values in Wincrypt.h. If the function subsequently finds the registry key defined in **CERT_CHAIN_CONFIG_REGPATH**, it updates the previously initialized values with the registry values.

The following configuration setting names and default values are initialized by this function:

* **CERT_SRV_OCSP_RESP_MIN_VALIDITY_SECONDS_VALUE_NAME**

  L"SrvOcspRespMinValiditySeconds"

  The minimum time validity of the server OCSP response to be returned by [CertGetServerOcspResponseContext](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certgetserverocspresponsecontext). The OCSP
  response validity must be sufficiently long that the client treats it as time valid.
* **CERT_SRV_OCSP_RESP_MIN_VALIDITY_SECONDS_DEFAULT**

  (10 × 60)

  10 minutes.
* **CERT_SRV_OCSP_RESP_URL_RETRIEVAL_TIMEOUT_MILLISECONDS_VALUE_NAME**

  L"SrvOcspRespUrlRetrievalTimeoutMilliseconds"

  This is the maximum time before an OCSP response prefetch wire URL retrieval times out.
* **CERT_SRV_OCSP_RESP_URL_RETRIEVAL_TIMEOUT_MILLISECONDS_DEFAULT**

  (15 × 1000)

  15 seconds.
* **CERT_SRV_OCSP_RESP_MAX_BEFORE_NEXT_UPDATE_SECONDS_VALUE_NAME**

  L"SrvOcspRespMaxBeforeNextUpdateSeconds"

  This is the maximum number of seconds to perform a server OCSP response
  prefetch retrieval before the NextUpdate date of an OCSP response. The
  server OCSP response thread waits until the current time is greater than or equal to the NextUpdate date minus this number of seconds to perform a prefetch retrieval.
* **CERT_SRV_OCSP_RESP_MAX_BEFORE_NEXT_UPDATE_SECONDS_DEFAULT**

  (4 ×60 × 60)

  4 hours.
* **CERT_SRV_OCSP_RESP_MIN_BEFORE_NEXT_UPDATE_SECONDS_VALUE_NAME**

  L"SrvOcspRespMinBeforeNextUpdateSeconds"

  This is the minimum number of seconds to perform a server OCSP response
  prefetch retrieval before the NextUpdate date of an OCSP response. If the current time is greater than or equal to the NextUpdate date minus this number of seconds, the server OCSP response thread waits until
  after the NextUpdate date plus the **CERT_SRV_OCSP_RESP_MIN_AFTER_NEXT_UPDATE_SECONDS_VALUE_NAME** number of seconds before it performs a prefetch retrieval.
* **CERT_SRV_OCSP_RESP_MIN_BEFORE_NEXT_UPDATE_SECONDS_DEFAULT**

  (2 × 60)

  2 minutes.
* **CERT_SRV_OCSP_RESP_MIN_AFTER_NEXT_UPDATE_SECONDS_VALUE_NAME**

  L"SrvOcspRespMinAfterNextUpdateSeconds"

  This is the minimum number of seconds to perform a server OCSP response
  prefetch retrieval after the NextUpdate date of an OCSP response. When the current time is greater than the NextUpdate date minus the **CERT_SRV_OCSP_RESP_MIN_BEFORE_NEXT_UPDATE_SECONDS_VALUE_NAME** number of seconds but less than the NextUpdate date, the server OCSP response thread waits this number of seconds after the NextUpdate date to perform a prefetch retrieval.
* **CERT_SRV_OCSP_RESP_MIN_AFTER_NEXT_UPDATE_SECONDS_DEFAULT**

  (1 × 60)

  1 minute.

## See also

[CertCloseServerOcspResponse](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certcloseserverocspresponse)