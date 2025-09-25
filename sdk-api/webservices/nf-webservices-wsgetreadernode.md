# WsGetReaderNode function

## Description

The function returns the XML [node](https://learn.microsoft.com/windows/desktop/api/webservices/ns-webservices-ws_xml_node) at the current position of the XML [reader](https://learn.microsoft.com/windows/desktop/wsw/ws-xml-reader).

## Parameters

### `xmlReader` [in]

A pointer to the reader for which the current node will be obtained. This must be valid WS_XML_READER object.

### `node`

A reference to a [WS_XML_NODE](https://learn.microsoft.com/windows/desktop/api/webservices/ns-webservices-ws_xml_node) structure where the current node is returned.

### `error` [in, optional]

A pointer to a [WS_ERROR](https://learn.microsoft.com/windows/desktop/wsw/ws-error) object where additional information about the error should be stored if the function fails.

## Return value

This function can return one of these values.

| Return code | Description |
| --- | --- |
| **E_INVALIDARG** | One or more arguments are invalid. |

## Remarks

The [nodeType](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_xml_node_type) field of the node [node](https://learn.microsoft.com/windows/desktop/api/webservices/ns-webservices-ws_xml_node) should be inspected
to determine the kind of node returned. The **node** may then be cast to the appropriate
data structure to get the data.

``` syntax
WS_XML_NODE* node;
if (SUCCEEDED(WsGetReaderNode(reader, &node, error)))
{
    if (node->nodeType == WS_XML_NODE_TYPE_ELEMENT)
    {
        WS_XML_ELEMENT_NODE* elementNode = (WS_XML_ELEMENT_NODE*) node;
        // Refer to elementNode->localName, elementNode->ns
    }
}
```

The [nodeTypes](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_xml_node_type) with extended structures include:

* **WS_XML_NODE_TYPE_ELEMENT** => [WS_XML_ELEMENT_NODE](https://learn.microsoft.com/windows/desktop/api/webservices/ns-webservices-ws_xml_element_node)
* **WS_XML_NODE_TYPE_TEXT** => [WS_XML_TEXT_NODE](https://learn.microsoft.com/windows/desktop/api/webservices/ns-webservices-ws_xml_text_node)
* **WS_XML_NODE_TYPE_COMMENT** => [WS_XML_COMMENT_NODE](https://learn.microsoft.com/windows/desktop/api/webservices/ns-webservices-ws_xml_comment_node)

The node returned should not be modified and is only valid until the reader advances.
For the attributes in a [WS_XML_ELEMENT_NODE](https://learn.microsoft.com/windows/desktop/api/webservices/ns-webservices-ws_xml_element_node) callers should not expect the
attributes to appear in any particular order.