# HTTP_SERVICE_CONFIG_URLACL_SET structure

## Description

The
**HTTP_SERVICE_CONFIG_URLACL_SET** structure is used to add a new record to the URL reservation store or retrieve an existing record from it. An instance of the structure is used to pass data in through the *pConfigInformation* parameter of the
[HTTPSetServiceConfiguration](https://learn.microsoft.com/windows/desktop/api/http/nf-http-httpsetserviceconfiguration) function, or to retrieve data through the *pOutputConfigInformation* parameter of the
[HTTPQueryServiceConfiguration](https://learn.microsoft.com/windows/desktop/api/http/nf-http-httpqueryserviceconfiguration) function when the *ConfigId* parameter of either function is equal to **HTTPServiceConfigUrlAclInfo**.

## Members

### `KeyDesc`

An
[HTTP_SERVICE_CONFIG_URLACL_KEY](https://learn.microsoft.com/windows/desktop/api/http/ns-http-http_service_config_urlacl_key) structure that identifies the URL reservation record.

### `ParamDesc`

An
[HTTP_SERVICE_CONFIG_URLACL_PARAM](https://learn.microsoft.com/windows/desktop/api/http/ns-http-http_service_config_urlacl_param) structure that holds the contents of the specified URL reservation record.

## See also

[HTTPQueryServiceConfiguration](https://learn.microsoft.com/windows/desktop/api/http/nf-http-httpqueryserviceconfiguration)

[HTTPSetServiceConfiguration](https://learn.microsoft.com/windows/desktop/api/http/nf-http-httpsetserviceconfiguration)

[HTTP_SERVICE_CONFIG_URLACL_KEY](https://learn.microsoft.com/windows/desktop/api/http/ns-http-http_service_config_urlacl_key)

[HTTP_SERVICE_CONFIG_URLACL_PARAM](https://learn.microsoft.com/windows/desktop/api/http/ns-http-http_service_config_urlacl_param)