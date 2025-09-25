# ID2D1SvgElement::InsertChildBefore

## Description

Inserts newChild as a child of this element, before the referenceChild element.
If the newChild element already has a parent, it is removed from this parent as
part of the insertion.

## Parameters

### `newChild` [in]

Type: **ID2D1SvgElement***

The element to be inserted.

### `referenceChild` [in, optional]

Type: **ID2D1SvgElement***

The element that the child should be inserted before.
If referenceChild is null, the newChild is placed as the last child.
If referenceChild is non-null, it must be an immediate child of this element.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

This method returns an HRESULT success or error code. Returns an error if this element cannot accept children
of the type of newChild. Returns an error if the newChild is an ancestor of this
element.

## See also

[ID2D1SvgElement](https://learn.microsoft.com/windows/desktop/api/d2d1svg/nn-d2d1svg-id2d1svgelement)