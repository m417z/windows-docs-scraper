# WS_HTTPS_URL structure

## Description

The URL subtype for specifying an HTTPS URL.

## Members

### `url`

The base type from which this URL subtype and all other URL subtypes derive. The [WS_URL_SCHEME_TYPE](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_url_scheme_type) is **WS_URL_HTTPS_SCHEME_TYPE**.

### `host`

The host name.

### `port`

The port number.

### `portAsString`

The port number as string.

### `path`

The path.

### `query`

The query.

### `fragment`

The fragment.

## Remarks

If used with the [WsDecodeUrl](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wsdecodeurl) field, portAsString is a zero-length string if no port is specified in url.

## See also

[WS_HTTP_URL](https://learn.microsoft.com/windows/desktop/api/webservices/ns-webservices-ws_http_url)

[WS_NETTCP_URL](https://learn.microsoft.com/windows/desktop/api/webservices/ns-webservices-ws_nettcp_url)

[WS_SOAPUDP_URL](https://learn.microsoft.com/windows/desktop/api/webservices/ns-webservices-ws_soapudp_url)