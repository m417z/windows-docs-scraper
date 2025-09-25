# ID2D1SvgElement::ReplaceChild

## Description

Replaces the oldChild element with the newChild. This operation removes the oldChild from the tree.
If the newChild element already has a parent, it is removed from this parent as part of the replace operation.

## Parameters

### `newChild` [in]

Type: **ID2D1SvgElement***

The element to be inserted.

### `oldChild` [in]

Type: **ID2D1SvgElement***

The child element to be replaced. The oldChild element must be an immediate child of this element.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

This method returns an HRESULT success or error code. Returns an error if
this element cannot accept children of the type of newChild. Returns an error if
the newChild is an ancestor of this element.

## See also

[ID2D1SvgElement](https://learn.microsoft.com/windows/desktop/api/d2d1svg/nn-d2d1svg-id2d1svgelement)