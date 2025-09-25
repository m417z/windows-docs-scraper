# WS_XML_ELEMENT_NODE structure

## Description

Represents a start element in xml (e.g.
<a:purchaseOrder xmlns:a="http://tempuri.org" id="5">)

## Members

### `node`

The base type for all types that derive from [WS_XML_NODE](https://learn.microsoft.com/windows/desktop/api/webservices/ns-webservices-ws_xml_node).

### `prefix`

The prefix of the element. In the example, it refers to "a". Empty prefixes are represented by a zero length [WS_XML_STRING](https://learn.microsoft.com/windows/desktop/api/webservices/ns-webservices-ws_xml_string).

### `localName`

The localName of the element. In the example, it refers to "purchaseOrder".

### `ns`

The resolved namespace of the prefix. In the example, it refers to "http://tempuri.org".

### `attributeCount`

The number of attributes on the element. In the example, it would be 2.

### `attributes`

The array of attributes for the element.

### `isEmpty`

Whether the element is an empty element or not. In the example, it would be **FALSE**.