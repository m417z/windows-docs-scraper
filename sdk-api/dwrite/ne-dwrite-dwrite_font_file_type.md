# DWRITE_FONT_FILE_TYPE enumeration

## Description

The type of a font represented by a single font file. Font formats that consist of multiple files, for example Type 1 .PFM and .PFB, have separate enum values for each of the file types.

## Constants

### `DWRITE_FONT_FILE_TYPE_UNKNOWN`

Font type is not recognized by the DirectWrite font system.

### `DWRITE_FONT_FILE_TYPE_CFF`

OpenType font with CFF outlines.

### `DWRITE_FONT_FILE_TYPE_TRUETYPE`

OpenType font with TrueType outlines.

### `DWRITE_FONT_FILE_TYPE_OPENTYPE_COLLECTION`

### `DWRITE_FONT_FILE_TYPE_TYPE1_PFM`

Type 1 PFM font.

### `DWRITE_FONT_FILE_TYPE_TYPE1_PFB`

Type 1 PFB font.

### `DWRITE_FONT_FILE_TYPE_VECTOR`

Vector .FON font.

### `DWRITE_FONT_FILE_TYPE_BITMAP`

Bitmap .FON font.

### `DWRITE_FONT_FILE_TYPE_TRUETYPE_COLLECTION`

OpenType font that contains a TrueType collection.