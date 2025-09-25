# WsReadXmlBuffer function

## Description

Reads the current node from a reader into a [WS_XML_BUFFER](https://learn.microsoft.com/windows/desktop/wsw/ws-xml-buffer).

## Parameters

### `reader` [in]

The reader from which to read into the XML buffer.

### `heap` [in]

The heap from which to allocate the XML buffer.

### `xmlBuffer`

The XML buffer is returned here.

### `error` [in, optional]

Specifies where additional error information should be stored if the function fails.

## Return value

This function can return one of these values.

| Return code | Description |
| --- | --- |
| **E_INVALIDARG** | One or more arguments are invalid. |
| **WS_E_INVALID_OPERATION** | The operation is not allowed due to the current state of the object. |
| **WS_E_QUOTA_EXCEEDED** | A quota was exceeded. |

## Remarks

If the reader must be positioned at either [WS_XML_NODE_TYPE_BOF](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_xml_node_type), or **WS_XML_NODE_TYPE_ELEMENT**.

If the reader is positioned at [WS_XML_NODE_TYPE_BOF](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_xml_node_type), then the entire document will be copied from the
reader into the XML buffer.

If the reader is positioned at [WS_XML_NODE_TYPE_ELEMENT](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_xml_node_type), then the element and all its children will be
read into the XML buffer.