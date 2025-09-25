# ID2D1SvgElement::SetAttributeValue(PCWSTR,D2D1_SVG_ATTRIBUTE_STRING_TYPE,PCWSTR)

## Description

Sets an attribute of this element using a string.

## Parameters

### `name` [in]

Type: **PCWSTR**

Name of the attribute to set.

### `type`

Type: **[D2D1_SVG_ATTRIBUTE_STRING_TYPE](https://learn.microsoft.com/windows/desktop/api/d2d1svg/ne-d2d1svg-d2d1_svg_attribute_string_type)**

The type of the string.

### `value` [in]

Type: **PCWSTR**

The new value of the attribute.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

This method returns an HRESULT success or error code. Returns an error if the
attribute name is not valid on this element. Returns an error if the attribute
cannot be expressed as the specified type.

## See also

[ID2D1SvgElement](https://learn.microsoft.com/windows/desktop/api/d2d1svg/nn-d2d1svg-id2d1svgelement)