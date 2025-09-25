# WsRemoveCustomHeader function

## Description

Removes a custom header from the message.
This function is designed to handle types of headers that appear once in the message and are targeted at the ultimate receiver. Headers targeted with a role other than ultimate receiver are ignored.

## Parameters

### `message` [in]

A pointer to the **Message** object with the header to be removed.

The message can be in any state except **WS_MESSAGE_STATE_EMPTY**.

### `headerName` [in]

A pointer to the [WS_XML_STRING](https://learn.microsoft.com/windows/desktop/api/webservices/ns-webservices-ws_xml_string) object that references the "local name" of the header element to be removed.

### `headerNs` [in]

A pointer to the [WS_XML_STRING](https://learn.microsoft.com/windows/desktop/api/webservices/ns-webservices-ws_xml_string) object that references the namespace of the header element to be removed.

### `error` [in, optional]

A pointer to a [WS_ERROR](https://learn.microsoft.com/windows/desktop/wsw/ws-error) object where additional information about the error should be stored if the function fails.

## Return value

This function can return one of these values.

| Return code | Description |
| --- | --- |
| **WS_E_INVALID_FORMAT** | There are multiple instances of the type of header present in the message. |
| **E_OUTOFMEMORY** | There was not enough memory available to serialize the header. |
| **E_INVALIDARG** | One or more of the parameters are incorrect. |
| **Other Errors** | This function may return other errors not listed above. |

## Remarks

If a header of the given type exists in the message it is removed. If the header does not exist, the function takes no action and completes successfully.