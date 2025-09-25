# ID2D1SvgDocument::Serialize

## Description

Serializes an element and its subtree to XML. The output XML is encoded as UTF-8.

## Parameters

### `outputXmlStream` [in]

Type: **IStream***

An output stream to contain the SVG XML subtree.

### `subtree` [in, optional]

Type: **ID2D1SvgElement***

The root of the subtree. If null, the entire document is serialized.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

This method returns an HRESULT success or error code.

## See also

[ID2D1SvgDocument](https://learn.microsoft.com/windows/desktop/api/d2d1svg/nn-d2d1svg-id2d1svgdocument)