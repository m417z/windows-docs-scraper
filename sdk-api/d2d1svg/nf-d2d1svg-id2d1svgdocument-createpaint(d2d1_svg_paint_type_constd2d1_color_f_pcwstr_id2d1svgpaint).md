# ID2D1SvgDocument::CreatePaint(D2D1_SVG_PAINT_TYPE,const D2D1_COLOR_F,PCWSTR,ID2D1SvgPaint)

## Description

Creates a paint object which can be used to set the 'fill' or 'stroke' properties.

## Parameters

### `paintType`

Type: **[D2D1_SVG_PAINT_TYPE](https://learn.microsoft.com/windows/desktop/api/d2d1svg/ne-d2d1svg-d2d1_svg_paint_type)**

Specifies the type of paint object to create.

### `color` [in, optional]

Type: **const D2D1_COLOR_F***

The color used if the paintType is D2D1_SVG_PAINT_TYPE_COLOR.

### `id` [in, optional]

Type: **PCWSTR**

The element id which acts as the paint server. This id is used if the paint type is D2D1_SVG_PAINT_TYPE_URI.

### `paint` [out]

Type: **ID2D1SvgPaint****

When the method completes, this will contain a pointer to the created paint object.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

This method returns an HRESULT success or error code.

## See also

[ID2D1SvgDocument](https://learn.microsoft.com/windows/desktop/api/d2d1svg/nn-d2d1svg-id2d1svgdocument)