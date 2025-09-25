# WsDecodeUrl function

## Description

Evaluates the components of an URL to determine its "scheme". A [WS_URL_SCHEME_TYPE](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_url_scheme_type) value is encapsulated in a [WS_URL](https://learn.microsoft.com/windows/desktop/api/webservices/ns-webservices-ws_url) structure and a reference to the structure is returned via output parameter.
If the scheme is not recognized, the function returns WS_E_INVALID_FORMAT.
Only scheme types identified in **WS_URL_SCHEME_TYPE** are supported.

## Parameters

### `url` [in]

A pointer to a [WS_STRING](https://learn.microsoft.com/windows/desktop/api/webservices/ns-webservices-ws_string) representation of the URL to evaluate.

### `flags` [in]

Determines the URL scheme evaluation method. See [WS_URL_FLAGS](https://learn.microsoft.com/windows/win32/api/webservices/ne-webservices-ws_xml_writer_encoding_type).

### `heap` [in]

A pointer to a [WS_HEAP](https://learn.microsoft.com/windows/desktop/wsw/ws-heap) in which to allocate the returned URL reference.

### `outUrl`

Reference to the [WS_URL](https://learn.microsoft.com/windows/desktop/api/webservices/ns-webservices-ws_url) structure that encapsulates the [WS_URL_SCHEME_TYPE](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_url_scheme_type) value.

### `error` [in, optional]

A pointer to a [WS_ERROR](https://learn.microsoft.com/windows/desktop/wsw/ws-error) object where additional information about the error should be stored if the function fails.

## Return value

This function can return one of these values.

| Return code | Description |
| --- | --- |
| **E_INVALIDARG** | One or more arguments are invalid. |
| **E_OUTOFMEMORY** | Ran out of memory. |
| **WS_E_INVALID_FORMAT** | The input URL was not in the correct format, or the scheme was not recognized. |
| **Other Errors** | This function may return other errors not listed above. |

## Remarks

The grammar parsed for the schemes "http", "https", "net.tcp" and "soap.udp" can be found at http://www.ietf.org/rfc/rfc3986.txt. For these schemes:

* A non-empty hostname is required.
* For the IP-literal production all the characters demarcated by "[" and "]" are returned. They are not enforced to follow the IPv6Address production.
* The userinfo part of authority (for example, userinfo@hostname:port) is not supported.

If no port is specified the default port for that scheme is returned.

If no port is specified for the soap.udp scheme 0xFFFFFFFF is returned as the default.