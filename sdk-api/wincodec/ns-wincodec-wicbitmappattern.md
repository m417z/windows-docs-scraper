# WICBitmapPattern structure

## Description

Contains members that identify a pattern within an image file which can be used to identify a particular format.

## Members

### `Position`

Type: **ULARGE_INTEGER**

The offset the pattern is located in the file.

### `Length`

Type: **ULONG**

The pattern length.

### `Pattern`

Type: **BYTE***

The actual pattern.

### `Mask`

Type: **BYTE***

The pattern mask.

### `EndOfStream`

Type: **BOOL**

The end of the stream.