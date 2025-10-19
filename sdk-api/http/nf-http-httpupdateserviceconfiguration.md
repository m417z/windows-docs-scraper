# HttpUpdateServiceConfiguration function

## Description

Updates atomically a service configuration parameter that specifies a Transport Layer Security (TLS) certificate in a configuration record within the HTTP Server API configuration store.

## Parameters

### `Handle` [in]

Reserved and must be **NULL**.

### `ConfigId` [in]

The type of configuration record to update. This parameter can be one of the following values from the [HTTP_SERVICE_CONFIG_ID](https://learn.microsoft.com/windows/desktop/api/http/ne-http-http_service_config_id) enumeration.

| *ConfigId* value | Meaning |
| --- | --- |
| **HttpServiceConfigSSLCertInfo** | Updates a specified SSL certificate record. |
| **HttpServiceConfigSslSniCertInfo** | Updates a specified SSL Server Name Indication (SNI) certificate record. |
| **HttpServiceConfigSslCcsCertInfo** | Updates the SSL certificate record that specifies that Http.sys should consult the Centralized Certificate Store (CCS) store to find certificates if the port receives a TLS handshake. The port is specified by the **KeyDesc** member of the [HTTP_SERVICE_CONFIG_SSL_CCS_SET](https://learn.microsoft.com/windows/desktop/api/http/ns-http-http_service_config_ssl_ccs_set) structure that you pass to the *pConfigInfo* parameter. |

### `ConfigInfo` [in]

A pointer to a buffer that contains the appropriate data to specify the type of record to update. The following table shows the type of data the buffer contains for the different possible values of the *ConfigId* parameter.

| *ConfigId* value | Type of data in the *pConfigInfo* buffer |
| --- | --- |
| **HttpServiceConfigSSLCertInfo** | [HTTP_SERVICE_CONFIG_SSL_SET](https://learn.microsoft.com/windows/desktop/api/http/ns-http-http_service_config_ssl_set) structure. |
| **HttpServiceConfigSslSniCertInfo** | [HTTP_SERVICE_CONFIG_SSL_SNI_SET](https://learn.microsoft.com/windows/desktop/api/http/ns-http-http_service_config_ssl_sni_set) structure. The hostname will be "*" when the SSL central certificate store is queried and wildcard bindings are used, and a host name for regular SNI. |
| **HttpServiceConfigSslCcsCertInfo** | [HTTP_SERVICE_CONFIG_SSL_CCS_SET](https://learn.microsoft.com/windows/desktop/api/http/ns-http-http_service_config_ssl_ccs_set) structure. This structure is used to add the CCS store on the specified port, as well as to delete, retrieve, or update an existing SSL CCS record. |

### `ConfigInfoLength` [in]

The size, in bytes, of the *ConfigInfo* buffer.

### `Overlapped` [in]

Reserved and must be **NULL**.

## Return value

If the function succeeds, the return value is **ERROR_SUCCESS**.

If the function fails, the return value is one of the following error codes.

| Value | Meaning |
| --- | --- |
| **ERROR_FILE_NOT_FOUND** | The specified record does not exist. |
| **ERROR_INSUFFICIENT_BUFFER** | The buffer size specified in the *ConfigInfoLength* parameter is insufficient. |
| **ERROR_INVALID_HANDLE** | The *ServiceHandle* parameter is invalid. |
| **ERROR_INVALID_PARAMETER** | One or more of the supplied parameters is in an unusable form. |
| **ERROR_NO_SUCH_LOGON_SESSION** | The SSL Certificate used is invalid. This can occur only if the *HttpServiceConfigSSLCertInfo* parameter is used. |
| **Other** | A [system error code](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes) defined in WinError.h. |

## Remarks

The configuration parameters that you update with **HttpUpdateServiceConfiguration** are applied to all the HTTP Server API applications on the machine, and persist when the HTTP Server API shuts down, or when the computer is restarted.

## See also

[HTTP Server API Version 1.0 Functions](https://learn.microsoft.com/windows/desktop/Http/http-server-api-version-1-0-functions)

[HTTP_SERVICE_CONFIG_ID](https://learn.microsoft.com/windows/desktop/api/http/ne-http-http_service_config_id)

[HTTP_SERVICE_CONFIG_SSL_CCS_SET](https://learn.microsoft.com/windows/desktop/api/http/ns-http-http_service_config_ssl_ccs_set)

[HTTP_SERVICE_CONFIG_SSL_SET](https://learn.microsoft.com/windows/desktop/api/http/ns-http-http_service_config_ssl_set)

[HTTP_SERVICE_CONFIG_SSL_SNI_SET](https://learn.microsoft.com/windows/desktop/api/http/ns-http-http_service_config_ssl_sni_set)

[HttpDeleteServiceConfiguration](https://learn.microsoft.com/windows/desktop/api/http/nf-http-httpdeleteserviceconfiguration)

[HttpQueryServiceConfiguration](https://learn.microsoft.com/windows/desktop/api/http/nf-http-httpqueryserviceconfiguration)

[HttpSetServiceConfiguration](https://learn.microsoft.com/windows/desktop/api/http/nf-http-httpsetserviceconfiguration)