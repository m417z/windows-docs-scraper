# WsGetErrorString function

## Description

Retrieves an error string from an error object.

## Parameters

### `error` [in]

The error object containing the string.

### `index` [in]

The zero-based index identifying the string to retrieve. The first
error string (index 0) will be the string most recently added to the
error object (using [WsAddErrorString](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wsadderrorstring)). When
[WS_ERROR_PROPERTY_ORIGINAL_ERROR_CODE](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_error_property_id) is presented in the
error object, the corresponding error text will be available in the last index.

The number of errors can be retrieved using [WS_ERROR_PROPERTY_STRING_COUNT](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_error_property_id).

### `string` [out]

The returned string. The string is valid until [WsResetError](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wsreseterror) or [WsFreeError](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wsfreeerror) is called.

The string is not zero terminated.

## Return value

This function can return one of these values.

| Return code | Description |
| --- | --- |
| **E_INVALIDARG** | One or more arguments are invalid. |
| **Other Errors** | This function may return other errors not listed above. |

## Remarks

The string is in the language specified by the LANGID property of
the error object. This can be retrieved using [WsGetErrorProperty](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wsgeterrorproperty) with [WS_ERROR_PROPERTY_LANGID](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_error_property_id).