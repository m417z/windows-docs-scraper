# ID2D1SvgElement::IsAttributeSpecified

## Description

Returns a boolean indicating if the attribute is explicitly set on the element.

## Parameters

### `name` [in]

Type: **PCWSTR**

The name of the attribute.

### `inherited` [out, optional]

Type: **BOOL***

Outputs whether the attribute is set to the inherit value.

## Return value

Type: **BOOL**

TReturns true if the attribute is explicitly set on the element or if it is present within an inline style. Returns FALSE if the attribute is not a valid
attribute on this element.

## See also

[ID2D1SvgElement](https://learn.microsoft.com/windows/desktop/api/d2d1svg/nn-d2d1svg-id2d1svgelement)