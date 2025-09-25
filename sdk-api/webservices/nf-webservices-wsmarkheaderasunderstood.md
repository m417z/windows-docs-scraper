# WsMarkHeaderAsUnderstood function

## Description

This function marks a header as "understood" by the application.
The set of headers is extensible and Message assimilation by the receiver is not accessible by the sender. This function is the receiving applications method for making it known to the sender that the received header has been read and understood.

**Note** This function should be used only if the application receives a message indicating that the header must be understood and it did not acquire the header using [WsGetHeader](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wsgetheader) or [WsGetCustomHeader](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wsgetcustomheader).

The [WS_MESSAGE_STATE](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_message_state) must be in the set to **WS_MESSAGE_STATE_READING**. See .[WsCheckMustUnderstandHeaders](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wscheckmustunderstandheaders) for more information.

## Parameters

### `message` [in]

A pointer to the Message object with the header to mark.

### `headerPosition` [in]

A pointer to the position of the header element within the XML header segment.

### `error` [in, optional]

A pointer to a [WS_ERROR](https://learn.microsoft.com/windows/desktop/wsw/ws-error) object where additional information about the error should be stored if the function fails.

## Return value

This function can return one of these values.

| Return code | Description |
| --- | --- |
| **WS_E_INVALID_OPERATION** | The message is not in the correct state. |
| **E_INVALIDARG** | One or more arguments are invalid. |
| **E_OUTOFMEMORY** | Ran out of memory. |
| **Other Errors** | This function may return other errors not listed above. |

## Remarks

When the application reads the header using an XML Reader,
it should obtain a [WS_XML_NODE_POSITION](https://learn.microsoft.com/windows/desktop/api/webservices/ns-webservices-ws_xml_node_position) of the header element
and pass it to this function. See [WsGetReaderPosition](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wsgetreaderposition) for
how to obtain a **WS_XML_NODE_POSITION**.