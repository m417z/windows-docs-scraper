# D2D1_SVG_PAINT_TYPE enumeration

## Description

Specifies the paint type for an SVG fill or stroke.

## Constants

### `D2D1_SVG_PAINT_TYPE_NONE:0`

The fill or stroke is not rendered.

### `D2D1_SVG_PAINT_TYPE_COLOR:1`

A solid color is rendered.

### `D2D1_SVG_PAINT_TYPE_CURRENT_COLOR:2`

The current color is rendered.

### `D2D1_SVG_PAINT_TYPE_URI:3`

A paint server, defined by another element in the SVG document, is used.

### `D2D1_SVG_PAINT_TYPE_URI_NONE:4`

A paint server, defined by another element in the SVG document, is used. If the paint server reference is invalid, fall back to D2D1_SVG_PAINT_TYPE_NONE.

### `D2D1_SVG_PAINT_TYPE_URI_COLOR:5`

A paint server, defined by another element in the SVG document, is used. If the paint server reference is invalid, fall back to D2D1_SVG_PAINT_TYPE_COLOR.

### `D2D1_SVG_PAINT_TYPE_URI_CURRENT_COLOR:6`

A paint server, defined by another element in the SVG document, is used. If the paint server reference is invalid, fall back to D2D1_SVG_PAINT_TYPE_CURRENT_COLOR.

### `D2D1_SVG_PAINT_TYPE_FORCE_DWORD:0xffffffff`