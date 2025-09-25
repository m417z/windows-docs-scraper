# HTTP_SERVICE_CONFIG_SSL_SNI_KEY structure

## Description

The
**HTTP_SERVICE_CONFIG_SSL_SNI_KEY** structure serves as the key by which a given Secure Sockets Layer (SSL) Server Name Indication (SNI) certificate record is identified in the SSL SNI store. It appears in the
[HTTP_SERVICE_CONFIG_SSL_SNI_SET](https://learn.microsoft.com/windows/desktop/api/http/ns-http-http_service_config_ssl_sni_set) and the
[HTTP_SERVICE_CONFIG_SSL_SNI_QUERY](https://learn.microsoft.com/windows/desktop/api/http/ns-http-http_service_config_ssl_sni_query) structures, and is passed as the *pConfigInformation* parameter to
[HttpDeleteServiceConfiguration](https://learn.microsoft.com/windows/desktop/api/http/nf-http-httpdeleteserviceconfiguration),
[HttpQueryServiceConfiguration](https://learn.microsoft.com/windows/desktop/api/http/nf-http-httpqueryserviceconfiguration), and
[HttpSetServiceConfiguration](https://learn.microsoft.com/windows/desktop/api/http/nf-http-httpsetserviceconfiguration) when the *ConfigId* parameter is set to **HttpServiceConfigSslSniCertInfo**.

## Members

### `IpPort`

A [SOCKADDR_STORAGE](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms740504(v=vs.85)) structure that contains the Internet Protocol version 4 (IPv4) address with which this SSL SNI certificate is associated. It must be set to the IPv4 wildcard address of type **SOCKADDR_IN** with **ss_family** set to **AF_INET** and **sin_addr** filled with zeros. **Port** can be any valid port.

### `Host`

A pointer to a null-terminated Unicode UTF-16 string that represents the hostname.

## See also

[HTTP_SERVICE_CONFIG_SSL_SNI_QUERY](https://learn.microsoft.com/windows/desktop/api/http/ns-http-http_service_config_ssl_sni_query)

[HTTP_SERVICE_CONFIG_SSL_SNI_SET](https://learn.microsoft.com/windows/desktop/api/http/ns-http-http_service_config_ssl_sni_set)

[HttpDeleteServiceConfiguration](https://learn.microsoft.com/windows/desktop/api/http/nf-http-httpdeleteserviceconfiguration)

[HttpQueryServiceConfiguration](https://learn.microsoft.com/windows/desktop/api/http/nf-http-httpqueryserviceconfiguration)

[HttpSetServiceConfiguration](https://learn.microsoft.com/windows/desktop/api/http/nf-http-httpsetserviceconfiguration)