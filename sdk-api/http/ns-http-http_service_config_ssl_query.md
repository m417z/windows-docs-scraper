# HTTP_SERVICE_CONFIG_SSL_QUERY structure

## Description

The
**HTTP_SERVICE_CONFIG_SSL_QUERY** structure is used to specify a particular record to query in the SSL configuration store. It is passed to the
[HttpQueryServiceConfiguration](https://learn.microsoft.com/windows/desktop/api/http/nf-http-httpqueryserviceconfiguration) function using the *pInputConfigInfo* parameter when the *ConfigId* parameter is set to **HttpServiceConfigSSLCertInfo**.

## Members

### `QueryDesc`

One of the following values from the [HTTP_SERVICE_CONFIG_QUERY_TYPE](https://learn.microsoft.com/windows/desktop/api/http/ne-http-http_service_config_query_type) enumeration.

#### HttpServiceConfigQueryExact

Returns a single SSL record.

#### HttpServiceConfigQueryNext

Returns a sequence of SSL records in a sequence of calls, as controlled by the *dwToken* parameter.

### `KeyDesc`

If the *QueryDesc* parameter is equal to **HttpServiceConfigQueryExact**, then *KeyDesc* should contain an
[HTTP_SERVICE_CONFIG_SSL_KEY](https://learn.microsoft.com/windows/desktop/api/http/ns-http-http_service_config_ssl_key) structure that identifies the SSL certificate record queried. If the *QueryDesc* parameter is equal to HTTPServiceConfigQueryNext, then *KeyDesc* is ignored.

### `dwToken`

If the *QueryDesc* parameter is equal to **HTTPServiceConfigQueryNext**, then *dwToken* must be equal to zero on the first call to the
[HttpQueryServiceConfiguration](https://learn.microsoft.com/windows/desktop/api/http/nf-http-httpqueryserviceconfiguration) function, one on the second call, two on the third call, and so forth until all SSL certificate records are returned, at which point
**HttpQueryServiceConfiguration** returns ERROR_NO_MORE_ITEMS.

If the *QueryDesc* parameter is equal to **HttpServiceConfigQueryExact**, then *dwToken* is ignored.

## See also

[HTTP_SERVICE_CONFIG_QUERY_TYPE](https://learn.microsoft.com/windows/desktop/api/http/ne-http-http_service_config_query_type)

[HTTP_SERVICE_CONFIG_SSL_SET](https://learn.microsoft.com/windows/desktop/api/http/ns-http-http_service_config_ssl_set)

[HttpQueryServiceConfiguration](https://learn.microsoft.com/windows/desktop/api/http/nf-http-httpqueryserviceconfiguration)