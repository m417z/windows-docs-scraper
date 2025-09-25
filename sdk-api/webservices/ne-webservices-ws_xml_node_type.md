# WS_XML_NODE_TYPE enumeration

## Description

The type of [WS_XML_NODE](https://learn.microsoft.com/windows/desktop/api/webservices/ns-webservices-ws_xml_node) structure.

## Constants

### `WS_XML_NODE_TYPE_ELEMENT:1`

A start element. (e.g. <a:purchaseOrder xmlns:a="http://tempuri.org" id="5">)

### `WS_XML_NODE_TYPE_TEXT:2`

Element, attribute, or CDATA content.

### `WS_XML_NODE_TYPE_END_ELEMENT:3`

An end element. (e.g. </purchaseOrder>)

### `WS_XML_NODE_TYPE_COMMENT:4`

A comment. (For example, <!--The message follows-->)

### `WS_XML_NODE_TYPE_CDATA:6`

The start of a CDATA section (i.e. <![CDATA[)

### `WS_XML_NODE_TYPE_END_CDATA:7`

The end of a CDATA section (i.e. ]]>)

### `WS_XML_NODE_TYPE_EOF:8`

The final node of an xml stream.

### `WS_XML_NODE_TYPE_BOF:9`

The first node of an xml stream.

## Remarks

The BNF for node types within a document is:

``` syntax
Xml := StartInput Whitespace Element Whitespace EndInput
Whitespace := (Text | Comment)* // Text is whitespace only
Element := StartElement ElementContent EndElement
ElementContent := (Element | Text | Comment | CData)*
StartElement := WS_XML_NODE_TYPE_ELEMENT
EndElement := WS_XML_NODE_TYPE_END_ELEMENT
Text := WS_XML_NODE_TYPE_TEXT
Comment := WS_XML_NODE_TYPE_COMMENT
CData := WS_XML_NODE_TYPE_CDATA Text* WS_XML_NODE_TYPE_END_CDATA
StartInput := WS_XML_NODE_TYPE_BOF
EndInput := WS_XML_NODE_TYPE_EOF
```