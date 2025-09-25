# ID2D1SvgElement::RemoveAttribute

## Description

Removes the attribute from this element. Also removes this attribute from within
an inline style if present.

## Parameters

### `name` [in]

Type: **PCWSTR**

The name of the attribute to remove.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

This method returns an HRESULT success or error code. Returns an error if the attribute name is not valid
on this element.

## See also

[ID2D1SvgElement](https://learn.microsoft.com/windows/desktop/api/d2d1svg/nn-d2d1svg-id2d1svgelement)