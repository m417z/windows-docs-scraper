# WS_XML_ATTRIBUTE structure

## Description

Represents an attribute (for example, <a:purchaseOrder xmlns:a="http://tempuri.org" id="5">)

## Members

### `singleQuote`

Whether to use a single quote or double quote to surround an attribute value. In the example, the value of singleQuote for attribute "id" would be **FALSE**.

### `isXmlNs`

Whether or not the attribute is an xmlns attribute. In the example above, this would be **TRUE** for the attribute "xmlns:a", but **FALSE** for the attribute "id".

### `prefix`

The prefix of the attribute. In the example above, the prefix for attribute "xmlns:a" is "a", while the prefix for "id" is a zero length string.

The prefix for the attribute "xmlns" is a zero length string.

### `localName`

The localName of the attribute. In the example above, the localName for attribute "xmlns:a" is not used so it is **NULL**. The localName for attribute "id" is "id".

### `ns`

The namespace of the attribute. In the example above, the namespace for the attribute "xmlns:a" is "http://tempuri.org". The namespace for attribute "id" is the
empty namespace which is represented by a zero length string.

### `value`

The value of the attribute. In the example above the value for attribute "xmlns:a" is not used so it is **NULL**. The value for the attribute "id" is a [WS_XML_TEXT](https://learn.microsoft.com/windows/desktop/api/webservices/ns-webservices-ws_xml_text) that refers to the value "5".