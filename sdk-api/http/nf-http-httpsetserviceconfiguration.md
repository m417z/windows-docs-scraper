# HttpSetServiceConfiguration function

## Description

The
**HttpSetServiceConfiguration** function creates and sets a configuration record for the HTTP Server API configuration store. The call fails if the specified record already exists. To change a given configuration record, delete it and then recreate it with a different value.

## Parameters

### `ServiceHandle` [in]

Reserved. Must be zero.

### `ConfigId` [in]

Type of configuration record to be set. This parameter can be one of the following values from the [HTTP_SERVICE_CONFIG_ID](https://learn.microsoft.com/windows/desktop/api/http/ne-http-http_service_config_id) enumeration.

| *ConfigId* value | Meaning |
| --- | --- |
| **HttpServiceConfigIPListenList** | Sets a record in the IP Listen List. |
| **HttpServiceConfigSSLCertInfo** | Sets a specified SSL certificate record. |
| **HttpServiceConfigUrlAclInfo** | Sets a URL reservation record. |
| **HttpServiceConfigTimeout** | Sets a specified HTTP Server API wide connection time-out.<br><br>**Windows Vista and later:** This enumeration value is supported. |
| **HttpServiceConfigSslSniCertInfo** | Sets a specified SSL Server Name Indication (SNI) certificate record.<br><br>**Windows 8 and later:** This enumeration value is supported. |
| **HttpServiceConfigSslCcsCertInfo** | Sets the SSL certificate record that specifies that Http.sys should consult the Centralized Certificate Store (CCS) store to find certificates if the port receives a Transport Layer Security (TLS) handshake. The port is specified by the **KeyDesc** member of the [HTTP_SERVICE_CONFIG_SSL_CCS_SET](https://learn.microsoft.com/windows/desktop/api/http/ns-http-http_service_config_ssl_ccs_set) structure that you pass to the *pConfigInformation* parameter.<br><br>**Windows 8 and later:** This enumeration value is supported. |

### `pConfigInformation` [in]

A pointer to a buffer that contains the appropriate data to specify the type of record to be set.

| *ConfigId* value | Meaning |
| --- | --- |
| **HttpServiceConfigIPListenList** | [HTTP_SERVICE_CONFIG_IP_LISTEN_PARAM](https://learn.microsoft.com/windows/desktop/api/http/ns-http-http_service_config_ip_listen_param) structure. |
| **HttpServiceConfigSSLCertInfo** | [HTTP_SERVICE_CONFIG_SSL_SET](https://learn.microsoft.com/windows/desktop/api/http/ns-http-http_service_config_ssl_set) structure. |
| **HttpServiceConfigUrlAclInfo** | [HTTP_SERVICE_CONFIG_URLACL_SET](https://learn.microsoft.com/windows/desktop/api/http/ns-http-http_service_config_urlacl_set) structure. |
| **HttpServiceConfigTimeout** | [HTTP_SERVICE_CONFIG_TIMEOUT_SET](https://learn.microsoft.com/windows/desktop/api/http/ns-http-http_service_config_timeout_set) structure.<br><br>**Windows Vista and later:** This structure is supported. |
| **HttpServiceConfigSslSniCertInfo** | [HTTP_SERVICE_CONFIG_SSL_SNI_SET](https://learn.microsoft.com/windows/desktop/api/http/ns-http-http_service_config_ssl_sni_set) structure. The hostname will be "*" when the SSL central certificate store is queried and wildcard bindings are used, and a host name for regular SNI.<br><br>**Windows 8 and later:** This structure is supported. |
| **HttpServiceConfigSslCcsCertInfo** | [HTTP_SERVICE_CONFIG_SSL_CCS_SET](https://learn.microsoft.com/windows/desktop/api/http/ns-http-http_service_config_ssl_ccs_set) structure.<br><br>**Windows 8 and later:** This structure is supported. |

### `ConfigInformationLength` [in]

Size, in bytes, of the *pConfigInformation* buffer.

### `pOverlapped` [in]

This parameter is reserved and must be **NULL**.

## Return value

If the function succeeds, the return value is **NO_ERROR**.

If the function fails, the return value is one of the following error codes.

| Value | Meaning |
| --- | --- |
| **ERROR_ALREADY_EXISTS** | The specified record already exists, and must be deleted in order for its value to be re-set. |
| **ERROR_INSUFFICIENT_BUFFER** | The buffer size specified in the *ConfigInformationLength* parameter is insufficient. |
| **ERROR_INVALID_HANDLE** | The *ServiceHandle* parameter is invalid. |
| **ERROR_INVALID_PARAMETER** | One or more of the supplied parameters is in an unusable form. |
| **ERROR_NO_SUCH_LOGON_SESSION** | The SSL Certificate used is invalid. This can occur only if the *HttpServiceConfigSSLCertInfo* parameter is used. |
| **Other** | A [system error code](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes) defined in WinError.h. |

## Remarks

The configuration parameters set with **HttpSetServiceConfiguration** are applied to all the HTTP Server API applications on the machine, and persist when the HTTP Server API shuts down, or when the computer is restarted.

## See also

[HTTP Server API Version 1.0 Functions](https://learn.microsoft.com/windows/desktop/Http/http-server-api-version-1-0-functions)

[HttpDeleteServiceConfiguration](https://learn.microsoft.com/windows/desktop/api/http/nf-http-httpdeleteserviceconfiguration)

[HttpQueryServiceConfiguration](https://learn.microsoft.com/windows/desktop/api/http/nf-http-httpqueryserviceconfiguration)

[HttpUpdateServiceConfiguration](https://learn.microsoft.com/windows/desktop/api/http/nf-http-httpupdateserviceconfiguration)