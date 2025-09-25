# DWRITE_TEXT_METRICS structure

## Description

Contains the metrics associated with text after layout.
All coordinates are in device independent pixels (DIPs).

## Members

### `left`

Type: **FLOAT**

A value that indicates the left-most point of formatted text relative to the layout box,
while excluding any glyph overhang.

### `top`

Type: **FLOAT**

A value that indicates the top-most point of formatted text relative to the layout box, while excluding any glyph overhang.

### `width`

Type: **FLOAT**

A value that indicates the width of the formatted text, while ignoring trailing whitespace
at the end of each line.

### `widthIncludingTrailingWhitespace`

Type: **FLOAT**

The width of the formatted text, taking into account the
trailing whitespace at the end of each line.

### `height`

Type: **FLOAT**

The height of the formatted text. The height of an empty string
is set to the same value as that of the default font.

### `layoutWidth`

Type: **FLOAT**

The initial width given to the layout. It can be either larger or smaller than the
text content width, depending on whether the text
was wrapped.

### `layoutHeight`

Type: **FLOAT**

Initial height given to the layout. Depending on the length of the text, it may be larger or smaller than the text content height.

### `maxBidiReorderingDepth`

Type: **UINT32**

The maximum reordering count of any line of text, used
to calculate the most number of hit-testing boxes needed.
If the layout has no bidirectional text, or no text at all,
the minimum level is 1.

### `lineCount`

Type: **UINT32**

Total number of lines.