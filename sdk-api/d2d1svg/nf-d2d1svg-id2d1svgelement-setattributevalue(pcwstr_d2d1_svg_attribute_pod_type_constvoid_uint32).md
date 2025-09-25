# ID2D1SvgElement::SetAttributeValue(PCWSTR,D2D1_SVG_ATTRIBUTE_POD_TYPE,const void,UINT32)

## Description

Sets an attribute of this element using a POD type.

## Parameters

### `name` [in]

Type: **PCWSTR**

Name of the attribute to set.

### `type`

Type: **[D2D1_SVG_ATTRIBUTE_POD_TYPE](https://learn.microsoft.com/windows/desktop/api/d2d1svg/ne-d2d1svg-d2d1_svg_attribute_pod_type)**

The POD type of the attribute.

### `value` [in]

Type: **const void***

The new value of the attribute.

### `valueSizeInBytes`

Type: **UINT32**

The size of the new value in bytes.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

This method returns an HRESULT success or error code. Returns an error if the attribute name is not valid on this element. Returns an error if the attribute
cannot be expressed as the specified type.

## See also

[ID2D1SvgElement](https://learn.microsoft.com/windows/desktop/api/d2d1svg/nn-d2d1svg-id2d1svgelement)