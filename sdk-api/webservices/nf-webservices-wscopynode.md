# WsCopyNode function

## Description

Copies the current node from the specified [XML reader](https://learn.microsoft.com/windows/desktop/wsw/xml-reader) to the specified [XML writer](https://learn.microsoft.com/windows/desktop/wsw/xml-writer).

## Parameters

### `writer` [in]

Pointer to the [WS_XML_WRITER](https://learn.microsoft.com/windows/desktop/wsw/ws-xml-writer) to which to copy the XML node.

### `reader` [in]

Pointer to the [WS_XML_READER](https://learn.microsoft.com/windows/desktop/wsw/ws-xml-reader) from which to copy the XML node.

### `error` [in, optional]

Pointer to a [WS_ERROR](https://learn.microsoft.com/windows/desktop/wsw/ws-error) structure that receives additional error information if the function fails.

## Return value

If the function succeeds, it returns NO_ERROR; otherwise, it returns an HRESULT error code.

| Return code | Description |
| --- | --- |
| **WS_E_INVALID_OPERATION** | The operation is not allowed due to the current state of the object. |
| **WS_E_INVALID_FORMAT** | The input data was not in the expected format or did not have the expected value. |
| **WS_E_QUOTA_EXCEEDED** | A quota was exceeded. |

## Remarks

If the current node type is WS_XML_NODE_TYPE_ELEMENT,the current node,
all its children, and the corresponding end element, are copied to the XML writer.

If the current node type is WS_XML_NODE_TYPE_BOF, nodes are copied
until a node of type WS_XML_NODE_TYPE_EOF is reached.
For information on node types, see the [WS_XML_NODE_TYPE](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_xml_node_type) enumeration.

The reader will be positioned on the node following the node copied.