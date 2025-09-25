# WSDXML_NODE structure

## Description

Describes an XML node.

## Members

### `Parent`

Reference to the parent node in a linked list of [WSDXML_ELEMENT](https://learn.microsoft.com/windows/desktop/api/wsdxmldom/ns-wsdxmldom-wsdxml_element) structures.

### `Next`

Reference to the next node in the linked list of **WSDXML_NODE** structures.

#### - Type

Indicates whether the node is an element or text.

#### ElementType

Node represents an XML element.

#### TextType

Node represents text.

## Remarks

**WSDXML_NODE** represents an arbitrary node within the DOM tree. Nodes are weakly typed; the **Type** member must be inspected to determine the actual type of the node, and the node pointer must then be cast to the structure of the appropriate type (see [WSDXML_ELEMENT](https://learn.microsoft.com/windows/desktop/api/wsdxmldom/ns-wsdxmldom-wsdxml_element) and [WSDXML_TEXT](https://learn.microsoft.com/windows/desktop/api/wsdxmldom/ns-wsdxmldom-wsdxml_text)) to obtain the node contents. **Parent** points to the containing element for the current node, and **Next** points to any nodes at the same level as the current node.