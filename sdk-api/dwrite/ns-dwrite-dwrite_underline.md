# DWRITE_UNDERLINE structure

## Description

Contains information about the width, thickness, offset, run height, reading direction, and flow direction of an underline.

## Members

### `width`

Type: **FLOAT**

A value that indicates the width of the underline, measured parallel to the baseline.

### `thickness`

Type: **FLOAT**

A value that indicates the thickness of the underline, measured perpendicular to the baseline.

### `offset`

Type: **FLOAT**

A value that indicates the offset of the underline from the baseline. A positive offset represents a position below the baseline (away from the text) and a negative offset is above (toward the text).

### `runHeight`

Type: **FLOAT**

A value that indicates the height of the tallest run where the underline is applied.

### `readingDirection`

Type: **[DWRITE_READING_DIRECTION](https://learn.microsoft.com/windows/win32/api/dwrite/ne-dwrite-dwrite_reading_direction)**

A value that indicates the reading direction of the text associated with the underline. This value is used to interpret whether the width value runs horizontally or vertically.

### `flowDirection`

Type: **[DWRITE_FLOW_DIRECTION](https://learn.microsoft.com/windows/win32/api/dwrite/ne-dwrite-dwrite_flow_direction)**

A value that indicates the flow direction of the text associated with the underline. This value is used to interpret whether the thickness value advances top to bottom, left to right, or right to left.

### `localeName`

Type: **const WCHAR***

An array of characters which contains the locale of the text that the underline is being drawn under. For example, in vertical text, the underline belongs on the left for Chinese but on the right for Japanese.

### `measuringMode`

Type: **[DWRITE_MEASURING_MODE](https://learn.microsoft.com/windows/win32/api/dcommon/ne-dcommon-dwrite_measuring_mode)**

The measuring mode can be useful to the renderer to determine how underlines are rendered, such as rounding the thickness to a whole pixel in GDI-compatible modes.

## Remarks

All coordinates are in device independent pixels (DIPs).