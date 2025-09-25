# DWRITE_MEASURING_MODE enumeration

## Description

Indicates the measuring method used for text layout.

## Constants

### `DWRITE_MEASURING_MODE_NATURAL`

Specifies that text is measured using glyph ideal metrics whose values are independent to the current display resolution.

### `DWRITE_MEASURING_MODE_GDI_CLASSIC`

Specifies that text is measured using glyph display-compatible metrics whose values tuned for the current display resolution.

### `DWRITE_MEASURING_MODE_GDI_NATURAL`

Specifies that text is measured using the same glyph display metrics as text measured by GDI using a font created with CLEARTYPE_NATURAL_QUALITY.