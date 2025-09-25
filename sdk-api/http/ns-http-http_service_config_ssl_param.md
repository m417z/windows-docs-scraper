# HTTP_SERVICE_CONFIG_SSL_PARAM structure

## Description

The
**HTTP_SERVICE_CONFIG_SSL_PARAM** structure defines a record in the SSL configuration store.

## Members

### `SslHashLength`

The size, in bytes, of the SSL hash.

### `pSslHash`

A pointer to the SSL certificate hash.

### `AppId`

A unique identifier of the application setting this record.

### `pSslCertStoreName`

A pointer to a wide-character string that contains the name of the store from which the server certificate is to be read. If set to **NULL**, "MY" is assumed as the default name. The specified certificate store name must be present in the Local System store location.

### `DefaultCertCheckMode`

Determines how client certificates are checked. This member can be one of the following values.

| Value | Meaning |
| --- | --- |
| **0** | Enables the client certificate revocation check. |
| **1** | Client certificate is not to be verified for revocation. |
| **2** | Only cached certificate revocation is to be used. |
| **4** | The **DefaultRevocationFreshnessTime** setting is enabled. |
| **0x10000** | No usage check is to be performed. |

### `DefaultRevocationFreshnessTime`

The number of seconds after which to check for an updated certificate revocation list (CRL). If this value is zero, the new CRL is updated only when the previous one expires.

### `DefaultRevocationUrlRetrievalTimeout`

The timeout interval, in milliseconds, for an attempt to retrieve a certificate revocation list from the remote URL.

### `pDefaultSslCtlIdentifier`

A pointer to an SSL control identifier, which enables an application to restrict the group of certificate issuers to be trusted. This group must be a subset of the certificate issuers trusted by the machine on which the application is running.

### `pDefaultSslCtlStoreName`

The name of the store where the control identifier pointed to by **pDefaultSslCtlIdentifier** is stored.

### `DefaultFlags`

A combination of zero or more of the following flag values can be combined with OR as appropriate.

| Flags | Meaning |
| --- | --- |
| **HTTP_SERVICE_CONFIG_SSL_FLAG_NEGOTIATE_CLIENT_CERT** | Enables a client certificate to be cached locally for subsequent use. |
| **HTTP_SERVICE_CONFIG_SSL_FLAG_NO_RAW_FILTER** | Prevents SSL requests from being passed to low-level ISAPI filters. |
| **HTTP_SERVICE_CONFIG_SSL_FLAG_USE_DS_MAPPER** | Client certificates are mapped where possible to corresponding operating-system user accounts based on the certificate mapping rules stored in Active Directory. <br><br>If this flag is set and the mapping is successful, the **Token** member of the [HTTP_SSL_CLIENT_CERT_INFO](https://learn.microsoft.com/windows/desktop/api/http/ns-http-http_ssl_client_cert_info) structure is a handle to an [access token](https://learn.microsoft.com/windows/desktop/SecAuthZ/access-tokens). Release this token explicitly by closing the handle when the **HTTP_SSL_CLIENT_CERT_INFO** structure is no longer required. |

## Remarks

Together with a
[HTTP_SERVICE_CONFIG_SSL_KEY](https://learn.microsoft.com/windows/desktop/api/http/ns-http-http_service_config_ssl_key) structure, the **HTTP_SERVICE_CONFIG_SSL_PARAM** structure makes up the
[HTTP_SERVICE_CONFIG_SSL_SET](https://learn.microsoft.com/windows/desktop/api/http/ns-http-http_service_config_ssl_set) structure passed to
[HttpSetServiceConfiguration](https://learn.microsoft.com/windows/desktop/api/http/nf-http-httpsetserviceconfiguration) function in the *pConfigInformation* parameter when the *ConfigId* parameter is set to **HttpServiceConfigSSLCertInfo**.

Together with a
[HTTP_SERVICE_CONFIG_SSL_CCS_KEY](https://learn.microsoft.com/windows/desktop/api/http/ns-http-http_service_config_ssl_ccs_key) structure, the **HTTP_SERVICE_CONFIG_SSL_PARAM** structure makes up the
[HTTP_SERVICE_CONFIG_SSL_CCS_SET](https://learn.microsoft.com/windows/desktop/api/http/ns-http-http_service_config_ssl_ccs_set) structure passed to
[HttpSetServiceConfiguration](https://learn.microsoft.com/windows/desktop/api/http/nf-http-httpsetserviceconfiguration) function in the *pConfigInformation* parameter when the *ConfigId* parameter is set to **HttpServiceConfigSslCcsCertInfo**.

## See also

[HTTP_SERVICE_CONFIG_SSL_CCS_SET](https://learn.microsoft.com/windows/desktop/api/http/ns-http-http_service_config_ssl_ccs_set)

[HTTP_SERVICE_CONFIG_SSL_SET](https://learn.microsoft.com/windows/desktop/api/http/ns-http-http_service_config_ssl_set)

[HttpSetServiceConfiguration](https://learn.microsoft.com/windows/desktop/api/http/nf-http-httpsetserviceconfiguration)