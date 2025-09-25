# HTTP_SERVICE_CONFIG_SSL_CCS_KEY structure

## Description

Serves as the key by which identifies the SSL certificate record that specifies that Http.sys should consult the Centralized Certificate Store (CCS) store to find certificates if the port receives a Transport Layer Security (TLS) handshake.

## Members

### `LocalAddress`

A [SOCKADDR_STORAGE](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms740504(v=vs.85)) structure that contains the Internet Protocol version 4 (IPv4) address with which this SSL certificate record is associated. It must be set to the IPv4 wildcard address of type [SOCKADDR_IN](https://learn.microsoft.com/windows/desktop/api/ws2def/ns-ws2def-sockaddr_in) with the **sin_family** member set to AF_INET and the **sin_addr** member filled with zeros (0.0.0.0). The **sin_port** member can be any valid port.

## Remarks

 The **HTTP_SERVICE_CONFIG_SSL_CCS_KEY** structure appears in the [HTTP_SERVICE_CONFIG_SSL_CCS_SET](https://learn.microsoft.com/windows/desktop/api/http/ns-http-http_service_config_ssl_ccs_set) and the [HTTP_SERVICE_CONFIG_SSL_CCS_QUERY](https://learn.microsoft.com/windows/desktop/api/http/ns-http-http_service_config_ssl_ccs_query) structures. **HTTP_SERVICE_CONFIG_SSL_CCS_KEY** is passed as part of these structures in the *pConfigInformation*, *ConfigInfo*, *pInputConfigInfo*, and *pOutputConfigInfo* parameters to the [HttpDeleteServiceConfiguration](https://learn.microsoft.com/windows/desktop/api/http/nf-http-httpdeleteserviceconfiguration), [HttpQueryServiceConfiguration](https://learn.microsoft.com/windows/desktop/api/http/nf-http-httpqueryserviceconfiguration), [HttpSetServiceConfiguration](https://learn.microsoft.com/windows/desktop/api/http/nf-http-httpsetserviceconfiguration), and [HttpUpdateServiceConfiguration](https://learn.microsoft.com/windows/desktop/api/http/nf-http-httpupdateserviceconfiguration) functions when the *ConfigId* parameter is set to **HttpServiceConfigSslCcsCertInfo**.

## See also

[HTTP_SERVICE_CONFIG_SSL_CCS_QUERY](https://learn.microsoft.com/windows/desktop/api/http/ns-http-http_service_config_ssl_ccs_query)

[HTTP_SERVICE_CONFIG_SSL_CCS_SET](https://learn.microsoft.com/windows/desktop/api/http/ns-http-http_service_config_ssl_ccs_set)

[HttpDeleteServiceConfiguration](https://learn.microsoft.com/windows/desktop/api/http/nf-http-httpdeleteserviceconfiguration)

[HttpQueryServiceConfiguration](https://learn.microsoft.com/windows/desktop/api/http/nf-http-httpqueryserviceconfiguration)

[HttpSetServiceConfiguration](https://learn.microsoft.com/windows/desktop/api/http/nf-http-httpsetserviceconfiguration)

[HttpUpdateServiceConfiguration](https://learn.microsoft.com/windows/desktop/api/http/nf-http-httpupdateserviceconfiguration)