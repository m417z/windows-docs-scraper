# HTTP_SERVICE_CONFIG_SSL_KEY structure

## Description

The
**HTTP_SERVICE_CONFIG_SSL_KEY** structure serves as the key by which a given Secure Sockets Layer (SSL) certificate record is identified. It appears in the
[HTTP_SERVICE_CONFIG_SSL_SET](https://learn.microsoft.com/windows/desktop/api/http/ns-http-http_service_config_ssl_set) and the
[HTTP_SERVICE_CONFIG_SSL_QUERY](https://learn.microsoft.com/windows/desktop/api/http/ns-http-http_service_config_ssl_query) structures, and is passed as the *pConfigInformation* parameter to
[HTTPDeleteServiceConfiguration](https://learn.microsoft.com/windows/desktop/api/http/nf-http-httpdeleteserviceconfiguration),
[HttpQueryServiceConfiguration](https://learn.microsoft.com/windows/desktop/api/http/nf-http-httpqueryserviceconfiguration), and
[HttpSetServiceConfiguration](https://learn.microsoft.com/windows/desktop/api/http/nf-http-httpsetserviceconfiguration) when the *ConfigId* parameter is set to **HttpServiceConfigSSLCertInfo**.

## Members

### `pIpPort`

Pointer to a [sockaddr](https://learn.microsoft.com/windows/desktop/WinSock/sockaddr-2) structure that contains the Internet Protocol (IP) address with which this SSL certificate is associated.

If the **sin_addr** field in **IpPort** is set to 0.0.0.0, the certificate is applicable to all IPv4 and IPv6 addresses.
If the **sin6_addr** field in **IpPort** is set to [::], the certificate is applicable to all IPv6 addresses.

## See also

[HTTPDeleteServiceConfiguration](https://learn.microsoft.com/windows/desktop/api/http/nf-http-httpdeleteserviceconfiguration)

[HTTP_SERVICE_CONFIG_SSL_QUERY](https://learn.microsoft.com/windows/desktop/api/http/ns-http-http_service_config_ssl_query)

[HTTP_SERVICE_CONFIG_SSL_SET](https://learn.microsoft.com/windows/desktop/api/http/ns-http-http_service_config_ssl_set)