# DWRITE_RENDERING_MODE enumeration

## Description

Represents a method of rendering glyphs.

**Note** This topic is about **DWRITE_RENDERING_MODE** in Windows 8 and later. For info on the previous version see the Remarks section.

## Constants

### `DWRITE_RENDERING_MODE_DEFAULT`

Specifies that the rendering mode is determined automatically, based on the font and size.

### `DWRITE_RENDERING_MODE_ALIASED`

Specifies that no anti-aliasing is performed. Each pixel is either set to the foreground color of the text or retains the color of the background.

### `DWRITE_RENDERING_MODE_GDI_CLASSIC`

Specifies that antialiasing is performed in the horizontal direction and the appearance of glyphs is layout-compatible with GDI using CLEARTYPE_QUALITY.
Use DWRITE_MEASURING_MODE_GDI_CLASSIC to get glyph advances. The antialiasing may be either ClearType or grayscale depending on the text antialiasing mode.

### `DWRITE_RENDERING_MODE_GDI_NATURAL`

Specifies that antialiasing is performed in the horizontal direction and the appearance of glyphs is layout-compatible with GDI using CLEARTYPE_NATURAL_QUALITY.
Glyph advances are close to the font design advances, but are still rounded to whole pixels. Use DWRITE_MEASURING_MODE_GDI_NATURAL to get glyph advances.
The antialiasing may be either ClearType or grayscale depending on the text antialiasing mode.

### `DWRITE_RENDERING_MODE_NATURAL`

Specifies that antialiasing is performed in the horizontal direction. This rendering mode allows glyphs to be positioned with subpixel precision and
is therefore suitable
for natural (i.e., resolution-independent) layout. The antialiasing may be either ClearType or grayscale depending on the text antialiasing mode.

### `DWRITE_RENDERING_MODE_NATURAL_SYMMETRIC`

Similar to natural mode except that antialiasing is performed in both the horizontal and vertical directions.
This is typically used at larger sizes to make curves and diagonal lines look smoother. The antialiasing may be either ClearType or grayscale depending
on the text antialiasing mode.

### `DWRITE_RENDERING_MODE_OUTLINE`

Specifies that rendering should bypass the rasterizer and use the outlines directly. This is typically used at very large sizes.

### `DWRITE_RENDERING_MODE_CLEARTYPE_GDI_CLASSIC`

### `DWRITE_RENDERING_MODE_CLEARTYPE_GDI_NATURAL`

### `DWRITE_RENDERING_MODE_CLEARTYPE_NATURAL`

### `DWRITE_RENDERING_MODE_CLEARTYPE_NATURAL_SYMMETRIC`

## Remarks

### DWRITE_RENDERING_MODE previous to Windows 8

```
enum DWRITE_RENDERING_MODE {
  DWRITE_RENDERING_MODE_DEFAULT,
  DWRITE_RENDERING_MODE_ALIASED,
  DWRITE_RENDERING_MODE_CLEARTYPE_GDI_CLASSIC,
  DWRITE_RENDERING_MODE_CLEARTYPE_GDI_NATURAL,
  DWRITE_RENDERING_MODE_CLEARTYPE_NATURAL,
  DWRITE_RENDERING_MODE_CLEARTYPE_NATURAL_SYMMETRIC,
  DWRITE_RENDERING_MODE_OUTLINE

};
```