# ID2D1DeviceContext5::CreateSvgDocument

## Description

Creates an SVG document from a stream.

## Parameters

### `inputXmlStream` [in, optional]

Type: **IStream***

An input stream containing the SVG XML document. If null, an empty document is created.

### `viewportSize`

Type: **D2D1_SIZE_F**

Size of the initial viewport of the document.

### `svgDocument` [out]

Type: **ID2D1SvgDocument****

When this method returns, contains a pointer to the created SVG document.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

This method returns an HRESULT success or error code.

## See also

[ID2D1DeviceContext5](https://learn.microsoft.com/windows/desktop/api/d2d1_3/nn-d2d1_3-id2d1devicecontext5)