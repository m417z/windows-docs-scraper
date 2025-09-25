# WsGetWriterPosition function

## Description

Returns the current position of the writer. This can only be used on a
writer that is set to an XmlBuffer. When writing to a buffer, the position
represents the xml node before which new data will be placed.

## Parameters

### `writer` [in]

The writer for which the current position will be obtained.

### `nodePosition` [out]

The current position of the writer is returned here.

### `error` [in, optional]

Specifies where additional error information should be stored if the function fails.

## Return value

This function can return one of these values.

| Return code | Description |
| --- | --- |
| **E_INVALIDARG** | One or more arguments are invalid. |

## Remarks

See [WS_XML_NODE_POSITION](https://learn.microsoft.com/windows/desktop/api/webservices/ns-webservices-ws_xml_node_position) for more information on using positions.

It may be useful to call [WsWriteEndStartElement](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wswriteendstartelement) to force an element to be committed before
obtaining the position.