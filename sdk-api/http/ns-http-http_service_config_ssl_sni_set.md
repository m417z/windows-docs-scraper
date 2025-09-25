# HTTP_SERVICE_CONFIG_SSL_SNI_SET structure

## Description

The
**HTTP_SERVICE_CONFIG_SSL_SNI_SET** structure is used to add a new Secure Sockets Layer (SSL) Server Name Indication (SNI) certificate record to the SSL SNI store or retrieve an existing record from it. It is passed to the
[HttpSetServiceConfiguration](https://learn.microsoft.com/windows/desktop/api/http/nf-http-httpsetserviceconfiguration) function through the *pConfigInformation* parameter or to retrieve data from the
[HttpQueryServiceConfiguration](https://learn.microsoft.com/windows/desktop/api/http/nf-http-httpqueryserviceconfiguration) function through the *pOutputConfigInformation* parameter when the *ConfigId* parameter of either function is set to **HttpServiceConfigSslSniCertInfo**.

## Members

### `KeyDesc`

An [HTTP_SERVICE_CONFIG_SSL_SNI_KEY](https://learn.microsoft.com/windows/desktop/api/http/ns-http-http_service_config_ssl_sni_key) structure that identifies the SSL SNI certificate record.

### `ParamDesc`

An [HTTP_SERVICE_CONFIG_SSL_PARAM](https://learn.microsoft.com/windows/desktop/api/http/ns-http-http_service_config_ssl_param) structure that holds the contents of the specified SSL SNI certificate record.

## See also

[HTTP_SERVICE_CONFIG_SSL_SNI_KEY](https://learn.microsoft.com/windows/desktop/api/http/ns-http-http_service_config_ssl_sni_key)

[HTTP_SERVICE_CONFIG_SSL_SNI_QUERY](https://learn.microsoft.com/windows/desktop/api/http/ns-http-http_service_config_ssl_sni_query)

[HttpDeleteServiceConfiguration](https://learn.microsoft.com/windows/desktop/api/http/nf-http-httpdeleteserviceconfiguration)

[HttpQueryServiceConfiguration](https://learn.microsoft.com/windows/desktop/api/http/nf-http-httpqueryserviceconfiguration)

[HttpSetServiceConfiguration](https://learn.microsoft.com/windows/desktop/api/http/nf-http-httpsetserviceconfiguration)