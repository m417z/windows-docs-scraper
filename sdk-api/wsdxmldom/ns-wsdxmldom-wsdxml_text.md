# WSDXML_TEXT structure

## Description

Describes the text in an XML node.

## Members

### `Node`

The current node in a linked list of [WSDXML_NODE](https://learn.microsoft.com/windows/desktop/api/wsdxmldom/ns-wsdxmldom-wsdxml_node) structures.

### `Text`

The text contained in the XML node. The maximum length of this string is WSD_MAX_TEXT_LENGTH (8192). The text must consist of UTF-16 encoded characters. The text cannot contain raw XML, as special characters are rendered using the equivalent entity reference. For example, `<` is rendered as `&lt;`.

## Remarks

**WSDXML_TEXT** is used to represent the contents of an element. Since no type information exists for elements in DOM, the **Text** member is the exact representation of the element contents from the XML document.