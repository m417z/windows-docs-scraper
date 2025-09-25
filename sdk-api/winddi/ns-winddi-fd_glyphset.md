# FD_GLYPHSET structure

## Description

The FD_GLYPHSET structure is used to define the mappings from Unicode characters to glyph handles.

## Members

### `cjThis`

Specifies the size, in bytes, of the structure, including the array of [WCRUN](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-wcrun) structures.

### `flAccel`

Specifies accelerator flags. This member must be the following value:

| Flags | Meaning |
| --- | --- |
| GS_8BIT_HANDLES | All handles are 8-bit quantities. |
| GS_16BIT_HANDLES | All handles are 16-bit quantities. |
| GS_UNICODE_HANDLES | For all runs in this structure, the handle is obtained by zero extending the Unicode code point. |

### `cGlyphsSupported`

Specifies the total number of glyphs in all runs.

### `cRuns`

Specifies the number of [WCRUN](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-wcrun) structures in the **awcrun** array.

### `awcrun`

Is an array of [WCRUN](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-wcrun) structures.

## See also

[DrvQueryFontTree](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-drvqueryfonttree)

[WCRUN](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-wcrun)