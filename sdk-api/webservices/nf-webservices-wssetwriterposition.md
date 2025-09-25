# WsSetWriterPosition function

## Description

Sets the current position of the writer. The position must have been obtained by a
call to [WsGetReaderPosition](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wsgetreaderposition) or [WsGetWriterPosition](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wsgetwriterposition).

## Parameters

### `writer` [in]

The writer for which the current position will be set.

### `nodePosition` [in]

The position to set the writer to.

### `error` [in, optional]

Specifies where additional error information should be stored if the function fails.

## Return value

This function can return one of these values.

| Return code | Description |
| --- | --- |
| **E_INVALIDARG** | One or more arguments are invalid. |
| **WS_E_INVALID_OPERATION** | The operation is not allowed due to the current state of the object. |

## Remarks

This can only be used on a writer that is set to an [WS_XML_BUFFER](https://learn.microsoft.com/windows/desktop/wsw/ws-xml-buffer).

When writing to a buffer, the position represents the xml node before which new data will be placed.

See [WS_XML_NODE_POSITION](https://learn.microsoft.com/windows/desktop/api/webservices/ns-webservices-ws_xml_node_position) for more information on using positions.