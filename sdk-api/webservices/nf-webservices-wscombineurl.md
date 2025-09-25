# WsCombineUrl function

## Description

Produces an absolute URL from a specified URL reference (absolute or relative URL) and a specified absolute base URL.

## Parameters

### `baseUrl` [in]

Pointer to a [WS_STRING](https://learn.microsoft.com/windows/desktop/wsw/ws-listener) structure containing an absolute URL in encoded format.

### `referenceUrl` [in]

Pointer to a [WS_STRING](https://learn.microsoft.com/windows/desktop/wsw/ws-listener) structure containing an absolute or relative URL in encoded format.

### `flags` [in]

Controls the format of the resulting URL. For more information, see [WS_URL_FLAGS](https://learn.microsoft.com/windows/win32/api/webservices/ne-webservices-ws_xml_writer_encoding_type).

### `heap` [in]

Pointer to the [WS_HEAP](https://learn.microsoft.com/windows/desktop/wsw/ws-heap) object from which the memory for the resulting URL is allocated.

### `resultUrl` [out]

Pointer to a [WS_STRING](https://learn.microsoft.com/windows/desktop/wsw/ws-listener) structure that receives the resulting URL.
This is an absolute URL in encoded format.

### `error` [in, optional]

Pointer to a [WS_ERROR](https://learn.microsoft.com/windows/desktop/wsw/ws-error) structure that receives additional error information if the function fails.

## Return value

If the function succeeds, it returns NO_ERROR; otherwise, it returns an HRESULT error code.

| Return code | Description |
| --- | --- |
| **E_INVALIDARG** | One or more arguments are not valid. |
| **E_OUTOFMEMORY** | Insufficient memory to complete the operation. |
| **WS_E_INVALID_FORMAT** | The base URL or reference URL was not in the correct format, or had a scheme that was not recognized. |
| **Other Errors** | This function may return other errors not listed above. |

## Remarks

If the reference URL is absolute, it is returned unchanged, if the specified flags permit.
If the reference URL is relative, it is combined with the base URL before being returned.

Only the schemes listed in [WS_URL_SCHEME_TYPE](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_url_scheme_type) are supported.