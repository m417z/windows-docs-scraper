# WsAddErrorString function

## Description

Adds a specified error string to the error object.

## Parameters

### `error` [in]

Pointer to a [WS_ERROR](https://learn.microsoft.com/windows/desktop/wsw/ws-error) structure representing the error object to which to add the string.

### `string` [in]

The string to add. The error object will
make a copy of the string.

## Return value

If the function succeeds, it returns NO_ERROR; otherwise, it returns an HRESULT error code.

| Return code | Description |
| --- | --- |
| **E_INVALIDARG** | One or more arguments are invalid. |
| **E_OUTOFMEMORY** | Insufficient memory to complete the operation. |
| **Other Errors** | This function may return other errors not listed above. |

## Remarks

This function requires that the string be in the language specified by the LANGID of the
error object. You can retrieve this LANGID value by calling the [WsGetErrorProperty](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wsgeterrorproperty) function with the WS_ERROR_PROPERTY_LANGID value of the [WS_ERROR_PROPERTY_ID](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_error_property_id) enumeration.