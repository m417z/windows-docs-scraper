# ID2D1SvgDocument::CreateStrokeDashArray

## Description

Creates a dash array object which can be used to set the stroke-dasharray property.

## Parameters

### `dashes` [in, optional]

Type: **const [D2D1_SVG_LENGTH](https://learn.microsoft.com/windows/desktop/api/d2d1svg/ns-d2d1svg-d2d1_svg_length)***

An array of dashes.

### `dashesCount`

Type: **UINT32**

Size of the array in th dashes argument.

### `strokeDashArray` [out]

Type: **ID2D1SvgStrokeDashArray****

The created [ID2D1SvgStrokeDashArray](https://learn.microsoft.com/windows/desktop/api/d2d1svg/nn-d2d1svg-id2d1svgstrokedasharray).

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

This method returns an HRESULT success or error code.

## See also

[ID2D1SvgDocument](https://learn.microsoft.com/windows/desktop/api/d2d1svg/nn-d2d1svg-id2d1svgdocument)