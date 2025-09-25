# HTTP_SERVICE_CONFIG_URLACL_KEY structure

## Description

The
**HTTP_SERVICE_CONFIG_URLACL_KEY** structure is used to specify a particular reservation record in the URL namespace reservation store. It is a member of the
[HTTP_SERVICE_CONFIG_URLACL_SET](https://learn.microsoft.com/windows/desktop/api/http/ns-http-http_service_config_urlacl_set) and
[HTTP_SERVICE_CONFIG_URLACL_QUERY](https://learn.microsoft.com/windows/desktop/api/http/ns-http-http_service_config_urlacl_query) structures.

## Members

### `pUrlPrefix`

A pointer to the
[UrlPrefix string](https://learn.microsoft.com/windows/desktop/Http/urlprefix-strings) that defines the portion of the URL namespace to which this reservation pertains.

## See also

[HTTP_SERVICE_CONFIG_URLACL_QUERY](https://learn.microsoft.com/windows/desktop/api/http/ns-http-http_service_config_urlacl_query)

[HTTP_SERVICE_CONFIG_URLACL_SET](https://learn.microsoft.com/windows/desktop/api/http/ns-http-http_service_config_urlacl_set)

[UrlPrefix Strings](https://learn.microsoft.com/windows/desktop/Http/urlprefix-strings)