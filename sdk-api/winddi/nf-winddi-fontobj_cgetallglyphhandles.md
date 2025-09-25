# FONTOBJ_cGetAllGlyphHandles function

## Description

The **FONTOBJ_cGetAllGlyphHandles** function allows the device driver to find every glyph handle of a GDI font.

## Parameters

### `pfo`

Pointer to the [FONTOBJ](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-fontobj) structure that is to be downloaded.

### `phg`

Pointer to a buffer large enough to hold all the glyph handles in the font. This parameter can be **NULL**.

## Return value

The return value is the number of glyph handles supported by the font.

## Remarks

A driver uses this function to download an entire font.

The driver must provide a buffer large enough to contain the output. GDI copies all glyph handles belonging to the associated font to this buffer.

The number of glyphs in the font can be determined by calling [FONTOBJ_vGetInfo](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-fontobj_vgetinfo), or by calling **FONTOBJ_cGetAllGlyphHandles** with the *phg* parameter set to **NULL**.

## See also

[FONTOBJ](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-fontobj)

[FONTOBJ_vGetInfo](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-fontobj_vgetinfo)