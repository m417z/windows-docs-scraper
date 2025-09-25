# WsGetReaderPosition function

## Description

Returns the current position of the reader. This can only be used on a reader
that is set to an XmlBuffer.

## Parameters

### `reader` [in]

The reader for which the current position will be obtained.

### `nodePosition` [out]

The current position of the reader.

### `error` [in, optional]

Specifies where additional error information should be stored if the function fails.

## Return value

This function can return one of these values.

| Return code | Description |
| --- | --- |
| **E_INVALIDARG** | One or more arguments are invalid. |

## Remarks

See [WS_XML_NODE_POSITION](https://learn.microsoft.com/windows/desktop/api/webservices/ns-webservices-ws_xml_node_position) for more information on using positions.