# HttpDeleteServiceConfiguration function

## Description

The
**HttpDeleteServiceConfiguration** function deletes specified data, such as IP addresses or SSL Certificates, from the HTTP Server API configuration store, one record at a time.

## Parameters

### `ServiceHandle` [in]

This parameter is reserved and must be zero.

### `ConfigId` [in]

Type of configuration. This parameter is one of the values in
the [HTTP_SERVICE_CONFIG_ID](https://learn.microsoft.com/windows/desktop/api/http/ne-http-http_service_config_id) enumeration.

| *ConfigId* value | Meaning |
| --- | --- |
| **HttpServiceConfigIPListenList** | Deletes a specified IP address from the IP Listen List. |
| **HttpServiceConfigSSLCertInfo** | Deletes a specified SSL certificate record. |
| **HttpServiceConfigUrlAclInfo** | Deletes a specified URL reservation record. |
| **HttpServiceConfigTimeout** | Deletes a specified connection timeout.<br><br>**Windows Vista and later:** This enumeration is supported. |
| **HttpServiceConfigSslSniCertInfo** | Deletes a specified SSL Server Name Indication (SNI) certificate record.<br><br>**Windows 8 and later:** This enumeration value is supported. |
| **HttpServiceConfigSslCcsCertInfo** | Deletes the SSL certificate record that specifies that Http.sys should consult the Centralized Certificate Store (CCS) store to find certificates if the port receives a Transport Layer Security (TLS) handshake. The port is specified by the **KeyDesc** member of the [HTTP_SERVICE_CONFIG_SSL_CCS_SET](https://learn.microsoft.com/windows/desktop/api/http/ns-http-http_service_config_ssl_ccs_set) structure that you pass to the *pConfigInformation* parameter.<br><br>**Windows 8 and later:** This enumeration value is supported. |

### `pConfigInformation` [in]

Pointer to a buffer that contains data required for the type of configuration specified in the *ConfigId* parameter.

| *ConfigId* value | Meaning |
| --- | --- |
| **HttpServiceConfigIPListenList** | [HTTP_SERVICE_CONFIG_IP_LISTEN_PARAM](https://learn.microsoft.com/windows/desktop/api/http/ns-http-http_service_config_ip_listen_param) structure. |
| **HttpServiceConfigSSLCertInfo** | [HTTP_SERVICE_CONFIG_SSL_SET](https://learn.microsoft.com/windows/desktop/api/http/ns-http-http_service_config_ssl_set) structure. |
| **HttpServiceConfigUrlAclInfo** | [HTTP_SERVICE_CONFIG_URLACL_SET](https://learn.microsoft.com/windows/desktop/api/http/ns-http-http_service_config_urlacl_set) structure. |
| **HttpServiceConfigTimeouts** | [HTTP_SERVICE_CONFIG_TIMEOUT_KEY](https://learn.microsoft.com/windows/desktop/api/http/ne-http-http_service_config_timeout_key) structure.<br><br>**Windows Vista and later:** This structure is supported. |
| **HttpServiceConfigSslSniCertInfo** | [HTTP_SERVICE_CONFIG_SSL_SNI_SET](https://learn.microsoft.com/windows/desktop/api/http/ns-http-http_service_config_ssl_sni_set) structure. The hostname will be "*" when the SSL central certificate store is queried and wildcard bindings are used, and a host name for regular SNI.<br><br>**Windows 8 and later:** This structure is supported. |
| **HttpServiceConfigSslCcsCertInfo** | [HTTP_SERVICE_CONFIG_SSL_CCS_SET](https://learn.microsoft.com/windows/desktop/api/http/ns-http-http_service_config_ssl_ccs_set) structure.<br><br>**Windows 8 and later:** This structure is supported. |

### `ConfigInformationLength` [in]

Size, in bytes, of the *pConfigInformation* buffer.

### `pOverlapped` [in]

Reserved for future asynchronous operation. This parameter must be set to **NULL**.

## Return value

If the function succeeds, the function returns NO_ERROR.

If the function fails, it returns one of the following error codes.

| Value | Meaning |
| --- | --- |
| **ERROR_INVALID_PARAMETER** | One of the parameters are invalid. |
| **Other** | A [system error code](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes) defined in WinError.h. |

## See also

[HTTP Server API Version 1.0 Functions](https://learn.microsoft.com/windows/desktop/Http/http-server-api-version-1-0-functions)

[HttpQueryServiceConfiguration](https://learn.microsoft.com/windows/desktop/api/http/nf-http-httpqueryserviceconfiguration)

[HttpSetServiceConfiguration](https://learn.microsoft.com/windows/desktop/api/http/nf-http-httpsetserviceconfiguration)

[HttpUpdateServiceConfiguration](https://learn.microsoft.com/windows/desktop/api/http/nf-http-httpupdateserviceconfiguration)