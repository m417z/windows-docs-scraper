# HTTP_SERVICE_CONFIG_TIMEOUT_SET structure

## Description

The **HTTP_SERVICE_CONFIG_TIMEOUT_SET** structure is used to set the HTTP Server API wide timeout value.

## Members

### `KeyDesc`

A member of the [HTTP_SERVICE_CONFIG_TIMEOUT_KEY](https://learn.microsoft.com/windows/desktop/api/http/ne-http-http_service_config_timeout_key) enumeration identifying the timer that is set.

### `ParamDesc`

The value, in seconds, for the timer. The value must be greater than zero.

## Remarks

An instance of the **HTTP_SERVICE_CONFIG_TIMEOUT_SET** structure is used to pass data in to the
[HTTPSetServiceConfiguration](https://learn.microsoft.com/windows/desktop/api/http/nf-http-httpsetserviceconfiguration) function through the *pConfigInformation* parameter or to retrieve data from the
[HTTPQueryServiceConfiguration](https://learn.microsoft.com/windows/desktop/api/http/nf-http-httpqueryserviceconfiguration) function through the *pOutputConfigInformation* parameter when the *ConfigId* parameter of either function is equal to **HttpServiceConfigTimeout**.

Querying the existing value of an HTTP Server API wide timeout does not require administrative privileges. Setting the value, however, does require administrative privileges.

When the HTTP Server API wide timeout value is set with [HTTPSetServiceConfiguration](https://learn.microsoft.com/windows/desktop/api/http/nf-http-httpsetserviceconfiguration), the setting persists when the HTTP service is stopped and restarted. The timeout value is applied to all the HTTP Server API applications on the machine.

The HTTP Server API timeout value is deleted by calling [HTTPDeleteServiceConfiguration](https://learn.microsoft.com/windows/desktop/api/http/nf-http-httpdeleteserviceconfiguration) with the *ConfigId* parameter set to **HttpServiceConfigTimeout** and the *pConfigInformation* parameter pointing to the **HTTP_SERVICE_CONFIG_TIMEOUT_SET** structure. When a timer value is deleted, the persistent setting goes away, and HTTP Server API uses its hardcoded defaults.

## See also

[HTTP Server API Version 2.0 Structures](https://learn.microsoft.com/windows/desktop/Http/http-server-api-version-2-0-structures)

[HTTPDeleteServiceConfiguration](https://learn.microsoft.com/windows/desktop/api/http/nf-http-httpdeleteserviceconfiguration)

[HTTPQueryServiceConfiguration](https://learn.microsoft.com/windows/desktop/api/http/nf-http-httpqueryserviceconfiguration)

[HTTPSetServiceConfiguration](https://learn.microsoft.com/windows/desktop/api/http/nf-http-httpsetserviceconfiguration)