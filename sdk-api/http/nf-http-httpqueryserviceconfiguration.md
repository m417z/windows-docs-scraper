## Description

The **HttpQueryServiceConfiguration** function retrieves one or more HTTP Server API configuration records.

## Parameters

### `ServiceHandle` [in]

Reserved. Must be zero.

### `ConfigId` [in]

The configuration record query type. This parameter is one of the following values from the
[HTTP_SERVICE_CONFIG_ID](https://learn.microsoft.com/windows/desktop/api/http/ne-http-http_service_config_id) enumeration.

| *ConfigId* value | Meaning |
| --- | --- |
| **HttpServiceConfigIPListenList** | Queries the IP Listen List. |
| **HttpServiceConfigSSLCertInfo** | Queries the SSL store for a specific certificate record. |
| **HttpServiceConfigUrlAclInfo** | Queries URL reservation information. |
| **HttpServiceConfigTimeout** | Queries HTTP Server API wide connection timeouts.<br><br>**Windows Vista and later:** This enumeration is supported. |
| **HttpServiceConfigSslSniCertInfo** | Queries the SSL Server Name Indication (SNI) store for a specific certificate record.<br><br>**Windows 8 and later:** This enumeration value is supported. |
| **HttpServiceConfigSslCcsCertInfo** | Queries the SSL configuration for an SSL Centralized Certificate Store (CCS) record on the port. The port is specified by the **KeyDesc** member of the [HTTP_SERVICE_CONFIG_SSL_CCS_QUERY](https://learn.microsoft.com/windows/desktop/api/http/ns-http-http_service_config_ssl_ccs_query) structure that you pass to the *pInputConfigInfo* parameter.<br><br>**Windows 8 and later:** This enumeration value is supported. |

### `pInput` [in, optional]

A pointer to a structure whose contents further define the query and of the type that correlates with *ConfigId* in the following table.

| *ConfigId* value | Meaning |
| --- | --- |
| **HttpServiceConfigIPListenList** | No input data; set to **NULL**. |
| **HttpServiceConfigSSLCertInfo** | [HTTP_SERVICE_CONFIG_SSL_QUERY](https://learn.microsoft.com/windows/desktop/api/http/ns-http-http_service_config_ssl_query) structure. |
| **HttpServiceConfigUrlAclInfo** | [HTTP_SERVICE_CONFIG_URLACL_QUERY](https://learn.microsoft.com/windows/desktop/api/http/ns-http-http_service_config_urlacl_query) structure. |
| **HttpServiceConfigTimeout** | [HTTP_SERVICE_CONFIG_TIMEOUT_KEY](https://learn.microsoft.com/windows/desktop/api/http/ne-http-http_service_config_timeout_key) structure.<br><br>**Windows Vista and later:** This structure is supported. |
| **HttpServiceConfigSslSniCertInfo** | [HTTP_SERVICE_CONFIG_SSL_SNI_QUERY](https://learn.microsoft.com/windows/desktop/api/http/ns-http-http_service_config_ssl_sni_query) structure.<br><br>**Windows 8 and later:** This structure is supported. |
| **HttpServiceConfigSslCcsCertInfo** | [HTTP_SERVICE_CONFIG_SSL_CCS_QUERY](https://learn.microsoft.com/windows/desktop/api/http/ns-http-http_service_config_ssl_ccs_query) structure.<br><br>**Windows 8 and later:** This structure is supported. |

For more information, see the appropriate query structures.

### `InputLength` [in, optional]

Size, in bytes, of the *pInputConfigInfo* buffer.

### `pOutput` [in, out, optional]

A pointer to a buffer in which the query results are returned. The type of this buffer correlates with *ConfigId*.

| *ConfigId* value | Meaning |
| --- | --- |
| **HttpServiceConfigIPListenList** | [HTTP_SERVICE_CONFIG_IP_LISTEN_QUERY](https://learn.microsoft.com/windows/desktop/api/http/ns-http-http_service_config_ip_listen_query) structure. |
| **HttpServiceConfigSSLCertInfo** | [HTTP_SERVICE_CONFIG_SSL_SET](https://learn.microsoft.com/windows/desktop/api/http/ns-http-http_service_config_ssl_set) structure. |
| **HttpServiceConfigUrlAclInfo** | [HTTP_SERVICE_CONFIG_URLACL_SET](https://learn.microsoft.com/windows/desktop/api/http/ns-http-http_service_config_urlacl_set) structure. |
| **HttpServiceConfigTimeout** | [HTTP_SERVICE_CONFIG_TIMEOUT_PARAM](https://learn.microsoft.com/windows/desktop/Http/http-server-api-version-2-0-data-types) data type.<br><br>**Windows Vista and later:** This structure is supported. |
| **HttpServiceConfigSslSniCertInfo** | [HTTP_SERVICE_CONFIG_SSL_SNI_SET](https://learn.microsoft.com/windows/desktop/api/http/ns-http-http_service_config_ssl_sni_set) structure.<br><br>**Windows 8 and later:** This structure is supported. |
| **HttpServiceConfigSslCcsCertInfo** | [HTTP_SERVICE_CONFIG_SSL_CCS_SET](https://learn.microsoft.com/windows/desktop/api/http/ns-http-http_service_config_ssl_ccs_set) structure.<br><br>**Windows 8 and later:** This structure is supported. |

### `OutputLength` [in, optional]

Size, in bytes, of the *pOutputConfigInfo* buffer.

### `pReturnLength` [out, optional]

A pointer to a variable that receives the number of bytes to be written in the output buffer. If the output buffer is too small, the call fails with a return value of **ERROR_INSUFFICIENT_BUFFER**. The value pointed to by *pReturnLength* can be used to determine the minimum length the buffer requires for the call to succeed.

### `pOverlapped` [in]

Reserved for asynchronous operation and must be set to **NULL**.

## Return value

If the function succeeds, the return value is **NO_ERROR**.

If the function fails, the return value is one of the following error codes.

| Value | Meaning |
| --- | --- |
| **ERROR_INVALID_PARAMETER** | One of the parameters are invalid. |
| **ERROR_INSUFFICIENT_BUFFER** | The buffer pointed to by *pOutputConfigInfo* is too small to receive the output data. Call the function again with a buffer at least as large as the size pointed to by *pReturnLength* on exit. |
| **ERROR_MORE_DATA** | The buffer pointed to by *pOutputConfigInfo* is too small to receive the output data. Call the function again with a buffer at least as large as the size pointed to by *pReturnLength* on exit. |
| **ERROR_NO_MORE_ITEMS** | There are no more items to return that meet the specified criteria. |
| **Other** | A [system error code](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes) defined in WinError.h. |

## See also

[HTTP Server API Version 1.0 Functions](https://learn.microsoft.com/windows/desktop/Http/http-server-api-version-1-0-functions)

[HttpDeleteServiceConfiguration](https://learn.microsoft.com/windows/desktop/api/http/nf-http-httpdeleteserviceconfiguration)

[HttpSetServiceConfiguration](https://learn.microsoft.com/windows/desktop/api/http/nf-http-httpsetserviceconfiguration)

[HttpUpdateServiceConfiguration](https://learn.microsoft.com/windows/desktop/api/http/nf-http-httpupdateserviceconfiguration)