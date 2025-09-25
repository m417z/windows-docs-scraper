## Description

Gets an attribute of this element as a string.

## Parameters

### `name`

Type: [in] **PCWSTR**

The name of the attribute.

### `type`

Type: [in] **[D2D1_SVG_ATTRIBUTE_STRING_TYPE](https://learn.microsoft.com/windows/desktop/api/d2d1svg/ne-d2d1svg-d2d1_svg_attribute_string_type)**

The string type.

### `value`

Type: [out] **PWSTR**

The value of the attribute.

### `valueCount`

Type: [out] **UINT32**

The number of elements in the returned value.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

This method returns an HRESULT success or error code. Returns an error if the attribute name is not valid on this element. Returns an error if the attribute cannot be expressed as the specified string type. Returns an error if the attribute is not specified.

## See also

[ID2D1SvgElement](https://learn.microsoft.com/windows/desktop/api/d2d1svg/nn-d2d1svg-id2d1svgelement)