# DWRITE_STRIKETHROUGH structure

## Description

Contains information regarding the size and placement of strikethroughs.All coordinates are in device independent pixels (DIPs).

## Members

### `width`

Type: **FLOAT**

A value that indicates the width of the strikethrough, measured parallel to the baseline.

### `thickness`

Type: **FLOAT**

A value that indicates the thickness of the strikethrough, measured perpendicular to the baseline.

### `offset`

Type: **FLOAT**

A value that indicates the offset of the strikethrough from the baseline.
A positive offset represents a position below the baseline and
a negative offset is above. Typically, the offset will be negative.

### `readingDirection`

Type: **[DWRITE_READING_DIRECTION](https://learn.microsoft.com/windows/win32/api/dwrite/ne-dwrite-dwrite_reading_direction)**

Reading direction of the text associated with the strikethrough.
This value is used to interpret whether the width value runs horizontally
or vertically.

### `flowDirection`

Type: **[DWRITE_FLOW_DIRECTION](https://learn.microsoft.com/windows/win32/api/dwrite/ne-dwrite-dwrite_flow_direction)**

Flow direction of the text associated with the strikethrough.
This value is used to interpret whether the thickness value advances top to
bottom, left to right, or right to left.

### `localeName`

Type: **const WCHAR***

An array of characters containing the locale of the text that is the strikethrough is being drawn over.

### `measuringMode`

Type: **[DWRITE_MEASURING_MODE](https://learn.microsoft.com/windows/win32/api/dcommon/ne-dcommon-dwrite_measuring_mode)**

The measuring mode can be useful to the renderer to determine how underlines are rendered, such as rounding the thickness to a whole pixel in GDI-compatible modes.