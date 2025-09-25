# DWRITE_FONT_FACE_TYPE enumeration

## Description

Indicates the file format of a complete font face.

## Constants

### `DWRITE_FONT_FACE_TYPE_CFF`

OpenType font face with CFF outlines.

### `DWRITE_FONT_FACE_TYPE_TRUETYPE`

OpenType font face with TrueType outlines.

### `DWRITE_FONT_FACE_TYPE_OPENTYPE_COLLECTION`

### `DWRITE_FONT_FACE_TYPE_TYPE1`

A Type 1 font face.

### `DWRITE_FONT_FACE_TYPE_VECTOR`

A vector .FON format font face.

### `DWRITE_FONT_FACE_TYPE_BITMAP`

A bitmap .FON format font face.

### `DWRITE_FONT_FACE_TYPE_UNKNOWN`

Font face type is not recognized by the DirectWrite font system.

### `DWRITE_FONT_FACE_TYPE_RAW_CFF`

The font data includes only the CFF table from an OpenType CFF font. This font face type can be used only for embedded fonts (i.e., custom font file loaders) and the resulting font face object supports only the minimum functionality necessary to render glyphs.

### `DWRITE_FONT_FACE_TYPE_TRUETYPE_COLLECTION`

OpenType font face that is a part of a TrueType collection.

## Remarks

Font formats that consist of multiple files, such as Type 1 .PFM and .PFB, have a single enum entry.