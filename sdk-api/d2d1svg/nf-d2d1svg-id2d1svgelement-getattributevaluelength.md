# ID2D1SvgElement::GetAttributeValueLength

## Description

Gets the string length of an attribute of this element.

## Parameters

### `name` [in]

Type: **PCWSTR**

The name of the attribute.

### `type`

Type: **[D2D1_SVG_ATTRIBUTE_STRING_TYPE](https://learn.microsoft.com/windows/desktop/api/d2d1svg/ne-d2d1svg-d2d1_svg_attribute_string_type)**

The string type of the attribute.

### `valueLength` [out]

Type: **UINT32***

The length of the attribute. The returned string length does not include room for the null terminator.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

This method returns an HRESULT success or error code.
Returns an error if the attribute is not specified.
Returns an error if the attribute name is not valid on this element.
Returns an error if the attribute cannot be expressed as the specified string type.

## See also

[ID2D1SvgElement](https://learn.microsoft.com/windows/desktop/api/d2d1svg/nn-d2d1svg-id2d1svgelement)