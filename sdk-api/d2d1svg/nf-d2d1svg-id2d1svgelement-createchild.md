# ID2D1SvgElement::CreateChild

## Description

Creates an element from a tag name. The element is appended to the list of children.

## Parameters

### `tagName` [in]

Type: **PCWSTR**

The tag name of the new child. An empty string is interpreted to be a text content element.

### `newChild` [out]

Type: **ID2D1SvgElement****

The new child element.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

This method returns an HRESULT success or error code.
Returns an error if this element cannot accept children of the specified type.

## See also

[ID2D1SvgElement](https://learn.microsoft.com/windows/desktop/api/d2d1svg/nn-d2d1svg-id2d1svgelement)