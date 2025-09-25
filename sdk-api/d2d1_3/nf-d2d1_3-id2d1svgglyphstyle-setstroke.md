# ID2D1SvgGlyphStyle::SetStroke

## Description

Provides values to an SVG glyph for stroke properties. The brush with opacity
set to 1 is used as the 'context-stroke'. The opacity of the brush is used as
the 'context-stroke-opacity' value.

## Parameters

### `brush` [in, optional]

Type: **[ID2D1Brush](https://learn.microsoft.com/windows/desktop/api/d2d1/nn-d2d1-id2d1brush)***

Describes how the stroke is painted. A null brush will cause the context-stroke value to be none.

### `strokeWidth`

Type: **FLOAT**

Specifies the 'context-value' for the 'stroke-width' property.

### `dashes` [in, optional]

Type: **const FLOAT***

Specifies the 'context-value' for the 'stroke-dasharray'
property. A null value will cause the stroke-dasharray to be set to 'none'.

### `dashesCount`

Type: **UINT32**

The number of dashes in the dash array.

### `dashOffset`

Type: **FLOAT**

Specifies the 'context-value' for the 'stroke-dashoffset' property.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

This method returns an HRESULT success or error code.

## See also

[ID2D1SvgGlyphStyle](https://learn.microsoft.com/windows/desktop/api/d2d1_3/nn-d2d1_3-id2d1svgglyphstyle)