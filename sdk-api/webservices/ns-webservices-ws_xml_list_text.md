# WS_XML_LIST_TEXT structure

## Description

Represents a list of text values separated by a single whitespace character.

(e.g. The list { { WS_XML_TEXT_TYPE_INT32 }, 123},
{ { WS_XML_TEXT_TYPE_BOOL }, 1 } represents the text "123 true")

## Members

### `text`

The base type for all types that derive from [WS_XML_TEXT](https://learn.microsoft.com/windows/desktop/api/webservices/ns-webservices-ws_xml_text).

### `itemCount`

The number of items in the list.

### `items`

The list of items.