# HTTP_SERVICE_CONFIG_URLACL_QUERY structure

## Description

The
**HTTP_SERVICE_CONFIG_URLACL_QUERY** structure is used to specify a particular reservation record to query in the URL namespace reservation store. It is passed to the
[HttpQueryServiceConfiguration](https://learn.microsoft.com/windows/desktop/api/http/nf-http-httpqueryserviceconfiguration) function using the *pInputConfigInfo* parameter when the *ConfigId* parameter is equal to **HttpServiceConfigUrlAclInfo**.

## Members

### `QueryDesc`

One of the following values from the [HTTP_SERVICE_CONFIG_QUERY_TYPE](https://learn.microsoft.com/windows/desktop/api/http/ne-http-http_service_config_query_type) enumeration.

#### HttpServiceConfigQueryExact

Returns a single record.

#### HttpServiceConfigQueryNext

Returns a sequence of records in a sequence of calls, controlled by the *dwToken* parameter.

### `KeyDesc`

If the *QueryDesc* parameter is equal to **HttpServiceConfigQueryExact**, then *KeyDesc* should contain an
[HTTP_SERVICE_CONFIG_URLACL_KEY](https://learn.microsoft.com/windows/desktop/api/http/ns-http-http_service_config_urlacl_key) structure that identifies the reservation record queried.

If the *QueryDesc* parameter is equal to **HttpServiceConfigQueryNext**, *KeyDesc* is ignored.

### `dwToken`

If the *QueryDesc* parameter is equal to **HttpServiceConfigQueryNext**, then *dwToken* must be equal to zero on the first call to the
[HttpQueryServiceConfiguration](https://learn.microsoft.com/windows/desktop/api/http/nf-http-httpqueryserviceconfiguration) function, one on the second call, two on the third call, and so forth until all reservation records are returned, at which point
**HttpQueryServiceConfiguration** returns ERROR_NO_MORE_ITEMS.

If the *QueryDesc* parameter is equal to **HttpServiceConfigQueryExact**, then *dwToken* is ignored.

## See also

[HTTP_SERVICE_CONFIG_QUERY_TYPE](https://learn.microsoft.com/windows/desktop/api/http/ne-http-http_service_config_query_type)

[HTTP_SERVICE_CONFIG_URLACL_KEY](https://learn.microsoft.com/windows/desktop/api/http/ns-http-http_service_config_urlacl_key)

[HTTP_SERVICE_CONFIG_URLACL_SET](https://learn.microsoft.com/windows/desktop/api/http/ns-http-http_service_config_urlacl_set)

[HttpQueryServiceConfiguration](https://learn.microsoft.com/windows/desktop/api/http/nf-http-httpqueryserviceconfiguration)