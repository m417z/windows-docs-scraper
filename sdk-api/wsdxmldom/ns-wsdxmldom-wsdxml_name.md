# WSDXML_NAME structure

## Description

Specifies an XML qualified name.

## Members

### `Space`

Reference to a [WSDXML_NAMESPACE](https://learn.microsoft.com/windows/desktop/api/wsdxmldom/ns-wsdxmldom-wsdxml_namespace) structure that specifies the namespace of the qualified name.

### `LocalName`

The local name of the qualified name.

## Remarks

**WSDXML_NAME** represents a single name within a namespace. The relationship between the name and namespace is circular, in that the **Space** pointer of the name points to the namespace the name belongs to, and the **Names** array of the namespace will have an entry for the name.