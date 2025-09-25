# WsEncodeUrl function

## Description

Encodes the specified [WS_URL](https://learn.microsoft.com/windows/desktop/api/webservices/ns-webservices-ws_url) into a URL string given its component parts. Values are escaped as necessary,
combined, and stored in the specified [WS_HEAP](https://learn.microsoft.com/windows/desktop/wsw/ws-heap), and the result is returned as a [WS_STRING](https://learn.microsoft.com/windows/desktop/api/webservices/ns-webservices-ws_string).

## Parameters

### `url` [in]

A reference to the [WS_URL](https://learn.microsoft.com/windows/desktop/api/webservices/ns-webservices-ws_url) to encode.

### `flags` [in]

The value of this parameter determines the URL scheme evaluation method. See [WS_URL_FLAGS](https://learn.microsoft.com/windows/win32/api/webservices/ne-webservices-ws_xml_writer_encoding_type).

### `heap` [in]

A pointer to a [WS_HEAP](https://learn.microsoft.com/windows/desktop/wsw/ws-heap) in which to allocate URL.

### `outUrl` [out]

A pointer to the resulting URL string.

### `error` [in, optional]

A pointer to a [WS_ERROR](https://learn.microsoft.com/windows/desktop/wsw/ws-error) object where additional information about the error should be stored if the function fails.

## Return value

This function can return one of these values.

| Return code | Description |
| --- | --- |
| **E_INVALIDARG** | One or more arguments are invalid. |
| **E_OUTOFMEMORY** | Ran out of memory. |
| **WS_E_INVALID_FORMAT** | The URL data being encoded was not valid according to the URL syntax. |
| **Other Errors** | This function may return other errors not listed above. |

## Remarks

If a scheme is not recognized in the *url* parameter the function returns WS_E_INVALID_FORMAT.
Only scheme types identified in [WS_URL_SCHEME_TYPE](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_url_scheme_type) are supported.