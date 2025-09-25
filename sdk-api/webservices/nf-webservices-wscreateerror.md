# WsCreateError function

## Description

Creates an error object that can passed to functions to record rich error information.

## Parameters

### `properties`

An array of [WS_ERROR_PROPERTY](https://learn.microsoft.com/windows/desktop/api/webservices/ns-webservices-ws_error_property) structures containing optional error properties.

### `propertyCount` [in]

The number of properties in the *properties* array.

### `error`

On success, a pointer that receives the address of the [WS_ERROR](https://learn.microsoft.com/windows/desktop/wsw/ws-error) structure representing the created error object.

## Return value

If the function succeeds, it returns NO_ERROR; otherwise, it returns an HRESULT error code.

| Return code | Description |
| --- | --- |
| **E_INVALIDARG** | One or more arguments are invalid. |
| **E_OUTOFMEMORY** | Insufficient memory to complete the operation. |
| **Other Errors** | This function may return other errors not listed above. |

## Remarks

When you no long need the error object, free it by calling the [WsFreeError](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wsfreeerror) function.

By default, the
language of any language-dependent information in the error object is the current
user default UI language. However, you can change the language by setting
the WS_ERROR_PROPERTY_LANGID property. See the [WS_ERROR_PROPERTY_ID](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_error_property_id) enumeration.