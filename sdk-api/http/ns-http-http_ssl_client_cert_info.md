# HTTP_SSL_CLIENT_CERT_INFO structure

## Description

The
**HTTP_SSL_CLIENT_CERT_INFO** structure contains data about a Secure Sockets Layer (SSL) client certificate that can be used to determine whether the certificate is valid.

## Members

### `CertFlags`

Flags that indicate whether the certificate is valid. The possible values for this member are
a [SSPI Status Code](https://learn.microsoft.com/windows/desktop/SecAuthN/sspi-status-codes) returned from SSPI or one of the following flags from the **dwError** member of the [CERT_CHAIN_POLICY_STATUS](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_chain_policy_status) structure:

#### CERT_E_EXPIRED

#### CERT_E_UNTRUSTEDCA

#### CERT_E_WRONG_USAGE

#### CERT_E_UNTRUSTEDROOT

#### CERT_E_REVOKED

#### CERT_E_CN_NO_MATCH

### `CertEncodedSize`

The size, in bytes, of the certificate.

### `pCertEncoded`

A pointer to the actual certificate.

### `Token`

A handle to an access token. If the HTTP_SERVICE_CONFIG_SSL_FLAG_USE_DS_MAPPER flag is set using the
[HttpSetServiceConfiguration](https://learn.microsoft.com/windows/desktop/api/http/nf-http-httpsetserviceconfiguration) function, and the client certificate was successfully mapped to an operating-system user account, then this member contains the handle to a valid
[access token](https://learn.microsoft.com/windows/desktop/SecAuthZ/access-tokens). When the
**HTTP_SSL_CLIENT_CERT_INFO** structure is no longer required, release this token explicitly by closing the handle.

### `CertDeniedByMapper`

Reserved.

## Remarks

An
**HTTP_SSL_CLIENT_CERT_INFO** structure is pointed to by the **pClientCertInfo** member of the
[HTTP_SSL_INFO](https://learn.microsoft.com/windows/desktop/api/http/ns-http-http_ssl_info) structure, and is used by the
[HttpReceiveClientCertificate](https://learn.microsoft.com/windows/desktop/api/http/nf-http-httpreceiveclientcertificate) function to return data about the client certificate through the *pSslClientCertInfo* parameter.

## See also

[HTTP Server API Version 1.0 Structures](https://learn.microsoft.com/windows/desktop/Http/http-server-api-version-1-0-structures)

[HTTP_SSL_INFO](https://learn.microsoft.com/windows/desktop/api/http/ns-http-http_ssl_info)

[HttpReceiveClientCertificate](https://learn.microsoft.com/windows/desktop/api/http/nf-http-httpreceiveclientcertificate)