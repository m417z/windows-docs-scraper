## Description

> [!NOTE]
> **Some information relates to pre-released product, which may be substantially modified before it's commercially released. Microsoft makes no warranties, express or implied, with respect to the information provided here.**

Defines constants that specify which formats are supported in a font, either at a font-wide level or per glyph.

For color fonts, these formats can be used to represent color glyphs. Fonts can contain multiple drawable data formats for glyphs. And an app can use these values to tell DirectWrite which formats to return when splitting a color glyph run.

## Constants

### `DWRITE_GLYPH_IMAGE_FORMATS_NONE:0x00000000`

Specifies that no data is available for this glyph.

### `DWRITE_GLYPH_IMAGE_FORMATS_TRUETYPE:0x00000001`

Specifies that the glyph has TrueType outlines.

### `DWRITE_GLYPH_IMAGE_FORMATS_CFF:0x00000002`

Specifies that the glyph has CFF outlines.

### `DWRITE_GLYPH_IMAGE_FORMATS_COLR:0x00000004`

Specifies that the glyph has multilayered COLR data.

### `DWRITE_GLYPH_IMAGE_FORMATS_SVG:0x00000008`

Specifies that the glyph has SVG outlines as standard XML. Fonts may store the content gzip'd rather than plain text, indicated by the first two bytes as gzip header {0x1F 0x8B}.

### `DWRITE_GLYPH_IMAGE_FORMATS_PNG:0x00000010`

Specifies that the glyph has PNG image data, with standard PNG IHDR.

### `DWRITE_GLYPH_IMAGE_FORMATS_JPEG:0x00000020`

Specifies that the glyph has JPEG image data, with standard JIFF SOI header.

### `DWRITE_GLYPH_IMAGE_FORMATS_TIFF:0x00000040`

Specifies that the glyph has TIFF image data.

### `DWRITE_GLYPH_IMAGE_FORMATS_PREMULTIPLIED_B8G8R8A8:0x00000080`

Specifies that the glyph has raw 32-bit premultiplied BGRA data.

### `DWRITE_GLYPH_IMAGE_FORMATS_COLR_PAINT_TREE:0x00000100`

> [!IMPORTANT]
> The **DWRITE_GLYPH_IMAGE_FORMATS_COLR_PAINT_TREE** constant is available in pre-release versions of the [Windows Insider Preview](https://www.microsoft.com/software-download/windowsinsiderpreviewSDK).

Specifies that the glyph is represented by a tree of paint elements in the font's COLR table.