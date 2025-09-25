# ID2D1SvgDocument::Deserialize

## Description

Deserializes a subtree from the stream. The stream must have only one root element, but that root element need not be an 'svg' element.
The output element is not inserted into this document tree.

## Parameters

### `inputXmlStream` [in]

Type: **IStream***

An input stream containing the SVG XML subtree.

### `subtree` [out]

Type: **ID2D1SvgElement****

The root of the subtree.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

This method returns an HRESULT success or error code.

## See also

[ID2D1SvgDocument](https://learn.microsoft.com/windows/desktop/api/d2d1svg/nn-d2d1svg-id2d1svgdocument)