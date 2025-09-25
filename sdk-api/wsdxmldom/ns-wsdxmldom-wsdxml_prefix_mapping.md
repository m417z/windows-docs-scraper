# WSDXML_PREFIX_MAPPING structure

## Description

Describes an XML namespace prefix.

## Members

### `Refs`

The number of references to the mapping. When the value reaches zero, the mapping is deleted.

### `Next`

Reference to the next node in a linked list of **WSDXML_PREFIX_MAPPING** structures.

### `Space`

Reference to a [WSDXML_NAMESPACE](https://learn.microsoft.com/windows/desktop/api/wsdxmldom/ns-wsdxmldom-wsdxml_namespace) structure.

### `Prefix`

The text of the XML prefix.