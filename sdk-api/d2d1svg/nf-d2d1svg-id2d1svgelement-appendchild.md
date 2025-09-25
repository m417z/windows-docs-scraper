# ID2D1SvgElement::AppendChild

## Description

Appends an element to the list of children.
If the element already has a parent, it is removed from this parent as part of the append operation.

## Parameters

### `newChild` [in]

Type: **ID2D1SvgElement***

The element to append.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

This method returns an HRESULT success or error code.
Returns an error if this element cannot accept children of the type of newChild.
Returns an error if the newChild is an ancestor of this element.

## See also

[ID2D1SvgElement](https://learn.microsoft.com/windows/desktop/api/d2d1svg/nn-d2d1svg-id2d1svgelement)