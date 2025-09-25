# WsRemoveHeader function

## Description

Removes the standard [WS_HEADER_TYPE](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_header_type) object from a message.
The function is designed to handle types of headers that appear once in the message and are targeted at the ultimate receiver. Headers targeted with a role other than ultimate receiver are ignored.

For application-defined header types use the [WsRemoveCustomHeader](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wsremovecustomheader) function.

## Parameters

### `message` [in]

A pointer to the **Message** object with the header to be removed. The message can be in any state except **WS_MESSAGE_STATE_EMPTY**.

### `headerType` [in]

Indicates the type of header to be removed.

### `error` [in, optional]

A pointer to a [WS_ERROR](https://learn.microsoft.com/windows/desktop/wsw/ws-error) object where additional information about the error should be stored if the function fails.

## Return value

This function can return one of these values.

| Return code | Description |
| --- | --- |
| **WS_E_INVALID_FORMAT** | There are multiple instances of the type of header present in the message. |
| **E_INVALIDARG** | One or more of the parameters are incorrect. |
| **Other Errors** | This function may return other errors not listed above. |

## Remarks

If a header of the given type exists in the message it is removed. If the header does not exist, no action is taken
and the function completes successfully.