# HTTP_SERVICE_CONFIG_SSL_SET structure

## Description

The
**HTTP_SERVICE_CONFIG_SSL_SET** structure is used to add a new record to the SSL store or retrieve an existing record from it. An instance of the structure is used to pass data in to the
[HTTPSetServiceConfiguration](https://learn.microsoft.com/windows/desktop/api/http/nf-http-httpsetserviceconfiguration) function through the *pConfigInformation* parameter or to retrieve data from the
[HTTPQueryServiceConfiguration](https://learn.microsoft.com/windows/desktop/api/http/nf-http-httpqueryserviceconfiguration) function through the *pOutputConfigInformation* parameter when the *ConfigId* parameter of either function is equal to **HTTPServiceConfigSSLCertInfo**.

## Members

### `KeyDesc`

An
[HTTP_SERVICE_CONFIG_SSL_KEY](https://learn.microsoft.com/windows/desktop/api/http/ns-http-http_service_config_ssl_key) structure that identifies the SSL certificate record.

### `ParamDesc`

An
[HTTP_SERVICE_CONFIG_SSL_PARAM](https://learn.microsoft.com/windows/desktop/api/http/ns-http-http_service_config_ssl_param) structure that holds the contents of the specified SSL certificate record.

## See also

[HTTPQueryServiceConfiguration](https://learn.microsoft.com/windows/desktop/api/http/nf-http-httpqueryserviceconfiguration)

[HTTPSetServiceConfiguration](https://learn.microsoft.com/windows/desktop/api/http/nf-http-httpsetserviceconfiguration)

[HTTP_SERVICE_CONFIG_SSL_KEY](https://learn.microsoft.com/windows/desktop/api/http/ns-http-http_service_config_ssl_key)

[HTTP_SERVICE_CONFIG_SSL_PARAM](https://learn.microsoft.com/windows/desktop/api/http/ns-http-http_service_config_ssl_param)