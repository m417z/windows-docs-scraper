# DWRITE_HIT_TEST_METRICS structure

## Description

Describes the region obtained by a hit test.

## Members

### `textPosition`

Type: **UINT32**

The first text position within the hit region.

### `length`

Type: **UINT32**

The number of text positions within the hit region.

### `left`

Type: **FLOAT**

The x-coordinate of the upper-left corner of the hit region.

### `top`

Type: **FLOAT**

The y-coordinate of the upper-left corner of the hit region.

### `width`

Type: **FLOAT**

The width of the hit region.

### `height`

Type: **FLOAT**

The height of the hit region.

### `bidiLevel`

Type: **UINT32**

The [BIDI level](https://learn.microsoft.com/windows/win32/api/dwrite/nf-dwrite-idwritetextanalyzer-analyzebidi) of the text positions within the hit region.

### `isText`

Type: **BOOL**

true if the hit region contains text; otherwise, false.

### `isTrimmed`

Type: **BOOL**

true if the text range is trimmed; otherwise, false.