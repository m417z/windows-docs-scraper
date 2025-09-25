# ID2D1SvgElement::SetAttributeValue(PCWSTR,ID2D1SvgAttribute)

## Description

Sets an attribute of this element using an interface.

A given attribute object may only be set on one element in one attribute location at a time.

## Parameters

### `name` [in]

Type: **PCWSTR**

Name of the attribute to set.

### `value` [in]

Type: **ID2D1SvgAttribute***

The new value of the attribute.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

This method returns an HRESULT success or error code. Returns an error if the attribute name is not valid on this element.
Returns an error if the attribute cannot be expressed as the specified interface type.
Returns an error if the attribute object is already set on an element.

## See also

[ID2D1SvgElement](https://learn.microsoft.com/windows/desktop/api/d2d1svg/nn-d2d1svg-id2d1svgelement)