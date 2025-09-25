# ID2D1SvgElement::GetNextChild

## Description

Gets the next sibling of the referenceChild element.

## Parameters

### `referenceChild` [in]

Type: **ID2D1SvgElement***

The referenceChild must be an immediate child of this element.

### `nextChild`

Type: **ID2D1SvgElement****

The output nextChild element will be non-null if the referenceChild has a next sibling. If the referenceChild is the last child, the output is null.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

This method returns an HRESULT success or error code.

## See also

[ID2D1SvgElement](https://learn.microsoft.com/windows/desktop/api/d2d1svg/nn-d2d1svg-id2d1svgelement)