# DWRITE_LINE_METRICS structure

## Description

Contains information about a formatted line of text.

## Members

### `length`

Type: **UINT32**

The number of text positions in the text line.
This includes any trailing whitespace and newline characters.

### `trailingWhitespaceLength`

Type: **UINT32**

The number of whitespace positions at the end of the text line.
Newline sequences are considered whitespace.

### `newlineLength`

Type: **UINT32**

The number of characters in the newline sequence at the end of the text line.
If the count is zero, then the text line was either wrapped or it is the end of the text.

### `height`

Type: **FLOAT**

The height of the text line.

### `baseline`

Type: **FLOAT**

The distance from the top of the text line to its baseline.

### `isTrimmed`

Type: **BOOL**

The line is trimmed.