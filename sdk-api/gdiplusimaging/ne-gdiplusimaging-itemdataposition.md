# ItemDataPosition enumeration

## Description

The **ItemDataPosition** enumeration is used to specify the location of custom metadata in an image file.

## Constants

### `ItemDataPositionAfterHeader:0x0`

Specifies that custom metadata is stored after the file header. Valid for JPEG, PNG, and GIF.

### `ItemDataPositionAfterPalette:0x1`

Specifies that custom metadata is stored after the palette. Valid for PNG.

### `ItemDataPositionAfterBits:0x2`

Specifies that custom metadata is stored after the pixel data. Valid for GIF and PNG.

## Remarks

GDI+ supports custom metadata for JPEG, PNG, and GIF image files.

## See also

[ImageItemData](https://learn.microsoft.com/previous-versions/ms534468(v=vs.85))