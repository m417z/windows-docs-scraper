# ID2D1SvgGlyphStyle::GetStroke

## Description

Returns the requested stroke parameters. Any parameters that are non-null will receive the value of the requested parameter.

## Parameters

### `brush` [out, optional]

Type: **[ID2D1Brush](https://learn.microsoft.com/windows/desktop/api/d2d1/nn-d2d1-id2d1brush)****

Describes how the stroke is painted.

### `strokeWidth` [out, optional]

Type: **FLOAT***

The 'context-value' for the 'stroke-width' property.

### `dashes` [out, optional]

Type: **FLOAT***

The 'context-value' for the 'stroke-dasharray'
property.

### `dashesCount`

Type: **UINT32**

The number of dashes in the dash array.

### `dashOffset` [out, optional]

Type: **FLOAT***

The 'context-value' for the 'stroke-dashoffset' property.

## See also

[ID2D1SvgGlyphStyle](https://learn.microsoft.com/windows/desktop/api/d2d1_3/nn-d2d1_3-id2d1svgglyphstyle)