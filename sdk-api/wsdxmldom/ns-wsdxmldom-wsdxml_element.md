# WSDXML_ELEMENT structure

## Description

Describes an XML element.

## Members

### `Node`

Reference to a [WSDXML_NODE](https://learn.microsoft.com/windows/desktop/api/wsdxmldom/ns-wsdxmldom-wsdxml_node) structure that specifies the parent element, next sibling and type of the node.

### `Name`

Reference to a [WSDXML_NAME](https://learn.microsoft.com/windows/desktop/api/wsdxmldom/ns-wsdxmldom-wsdxml_name) structure that specifies name.

### `FirstAttribute`

Reference to a [WSDXML_ATTRIBUTE](https://learn.microsoft.com/windows/desktop/api/wsdxmldom/ns-wsdxmldom-wsdxml_attribute) structure that specifies the first attribute.

### `FirstChild`

Reference to a [WSDXML_NODE](https://learn.microsoft.com/windows/desktop/api/wsdxmldom/ns-wsdxmldom-wsdxml_node) structure that specifies the first child.

### `PrefixMappings`

Reference to a [WSDXML_PREFIX_MAPPING](https://learn.microsoft.com/windows/desktop/api/wsdxmldom/ns-wsdxmldom-wsdxml_prefix_mapping) structure that specifies the prefix mappings.

## Remarks

**WSDXML_ELEMENT** represents an XML element in the DOM tree. The **Name** member can be used to determine the name and namespace of this element. **FirstAttribute** points to any attributes, and **FirstChild** points to anything contained within the element.