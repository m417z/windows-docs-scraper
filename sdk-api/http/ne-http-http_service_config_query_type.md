# HTTP_SERVICE_CONFIG_QUERY_TYPE enumeration

## Description

The
**HTTP_SERVICE_CONFIG_QUERY_TYPE** enumeration type defines various types of queries to make. It is used in the
[HTTP_SERVICE_CONFIG_SSL_QUERY](https://learn.microsoft.com/windows/desktop/api/http/ns-http-http_service_config_ssl_query), [HTTP_SERVICE_CONFIG_SSL_CCS_QUERY](https://learn.microsoft.com/windows/desktop/api/http/ns-http-http_service_config_ssl_ccs_query), and
[HTTP_SERVICE_CONFIG_URLACL_QUERY](https://learn.microsoft.com/windows/desktop/api/http/ns-http-http_service_config_urlacl_query) structures.

## Constants

### `HttpServiceConfigQueryExact`

The query returns a single record that matches the specified key value.

### `HttpServiceConfigQueryNext`

The query iterates through the store and returns all records in sequence, using an index value that the calling process increments between query calls.

### `HttpServiceConfigQueryMax`

Terminates the enumeration; is not used to define a query type.

## See also

[HTTP_SERVICE_CONFIG_SSL_CCS_QUERY](https://learn.microsoft.com/windows/desktop/api/http/ns-http-http_service_config_ssl_ccs_query)

[HTTP_SERVICE_CONFIG_SSL_QUERY](https://learn.microsoft.com/windows/desktop/api/http/ns-http-http_service_config_ssl_query)

[HTTP_SERVICE_CONFIG_URLACL_QUERY](https://learn.microsoft.com/windows/desktop/api/http/ns-http-http_service_config_urlacl_query)