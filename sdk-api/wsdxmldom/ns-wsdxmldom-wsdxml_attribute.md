# WSDXML_ATTRIBUTE structure

## Description

Describes an XML attribute.

## Members

### `Element`

Reference to a [WSDXML_ELEMENT](https://learn.microsoft.com/windows/desktop/api/wsdxmldom/ns-wsdxmldom-wsdxml_element) structure that specifies parent element of the attribute.

### `Next`

Reference to a **WSDXML_ATTRIBUTE** structure that specifies the next sibling attribute, if any.

### `Name`

Reference to a [WSDXML_NAME](https://learn.microsoft.com/windows/desktop/api/wsdxmldom/ns-wsdxmldom-wsdxml_name) structure that specifies the qualified name of the attribute.

### `Value`

The value of the attribute.

## Remarks

**WSDXML_ATTRIBUTE** is used to describe attribute values in an XML element.