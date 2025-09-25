# D2D1_SVG_ATTRIBUTE_STRING_TYPE enumeration

## Description

Defines the type of SVG string attribute to set or get.

## Constants

### `D2D1_SVG_ATTRIBUTE_STRING_TYPE_SVG:0`

The attribute is a string in the same form as it would appear in the SVG XML.
Note that when getting values of this type, the value returned may not exactly match the value that was set. Instead, the output value is a normalized version
of the value. For example, an input color of 'red' may be output as '#FF0000'.

### `D2D1_SVG_ATTRIBUTE_STRING_TYPE_ID:1`

The attribute is an element ID.

### `D2D1_SVG_ATTRIBUTE_STRING_TYPE_FORCE_DWORD:0xffffffff`