# WsSetReaderPosition function

## Description

Sets the current position of the Reader. The position must have been obtained by a call to [WsGetReaderPosition](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wsgetreaderposition) or [WsGetWriterPosition](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wsgetwriterposition).
This function can only be used on a reader that is set to a [WS_XML_BUFFER](https://learn.microsoft.com/windows/desktop/wsw/ws-xml-buffer).

## Parameters

### `reader` [in]

A pointer to the [WS_XML_READER](https://learn.microsoft.com/windows/desktop/wsw/ws-xml-reader) object for which the current position is set. The pointer must reference a valid **XML Reader** object.

### `nodePosition` [in]

A pointer to the position to set the Reader.

### `error` [in, optional]

A pointer to a [WS_ERROR](https://learn.microsoft.com/windows/desktop/wsw/ws-error) object where additional information about the error should be stored if the function fails.

## Return value

This function can return one of these values.

| Return code | Description |
| --- | --- |
| **E_INVALIDARG** | One or more arguments are invalid. |
| **WS_E_INVALID_OPERATION** | The operation is not allowed due to the current state of the object. |

## Remarks

See [WS_XML_NODE_POSITION](https://learn.microsoft.com/windows/desktop/api/webservices/ns-webservices-ws_xml_node_position) for more information on using positions.

This function cannot be used while canonicalizing. If [WsStartReaderCanonicalization](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wsstartreadercanonicalization) has
been called, then it will return **WS_E_INVALID_OPERATION**.
(See [Windows Web Services Return Values](https://learn.microsoft.com/windows/desktop/wsw/windows-web-services-return-values).)