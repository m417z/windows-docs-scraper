# HTTP_SERVICE_CONFIG_TIMEOUT_KEY enumeration

## Description

The **HTTP_SERVICE_CONFIG_TIMEOUT_KEY** enumeration defines the type of timer that is queried or configured through the [HTTP_SERVICE_CONFIG_TIMEOUT_SET](https://learn.microsoft.com/windows/desktop/api/http/ns-http-http_service_config_timeout_set) structure.

## Constants

### `IdleConnectionTimeout:0`

The maximum time allowed for a connection to remain idle, after which, the connection is timed out and reset.

### `HeaderWaitTimeout`

The maximum time allowed to parse all the request headers, including the request line, after which, the connection is timed out and reset.

## Remarks

 The **HTTP_SERVICE_CONFIG_TIMEOUT_KEY** enumeration is used in the [HTTP_SERVICE_CONFIG_TIMEOUT_SET](https://learn.microsoft.com/windows/desktop/api/http/ns-http-http_service_config_timeout_set) structure to define the type of timer that is configured. The **HTTP_SERVICE_CONFIG_TIMEOUT_SET** structure passes data to the [HTTPSetServiceConfiguration](https://learn.microsoft.com/windows/desktop/api/http/nf-http-httpsetserviceconfiguration) function through the *pConfigInformation* parameter or retrieves data from the
[HTTPQueryServiceConfiguration](https://learn.microsoft.com/windows/desktop/api/http/nf-http-httpqueryserviceconfiguration) function through the *pOutputConfigInformation* parameter when the *ConfigId* parameter of either function is equal to **HttpServiceConfigTimeout**.

## See also

[HTTP Server API Version 2.0 Enumeration Types](https://learn.microsoft.com/windows/desktop/Http/http-server-api-version-2-0-enumeration-types)

[HTTP_SERVICE_CONFIG_TIMEOUT_SET](https://learn.microsoft.com/windows/desktop/api/http/ns-http-http_service_config_timeout_set)