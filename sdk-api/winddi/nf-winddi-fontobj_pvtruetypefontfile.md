# FONTOBJ_pvTrueTypeFontFile function

## Description

The **FONTOBJ_pvTrueTypeFontFile** function retrieves a user-mode pointer to a view of a TrueType, OpenType, or Type1 font file.

## Parameters

### `pfo`

Pointer to the [FONTOBJ](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-fontobj) structure with which the TrueType, PostScript OpenType, or PostScript Type1 font is associated.

### `pcjFile`

Pointer to a location in which GDI returns the size, in bytes, of the view of the font file.

## Return value

**FONTOBJ_pvTrueTypeFontFile** returns a pointer to a user-mode view of a font file upon success. If the FONTOBJ structure identifies a Type1 font, the return value is a pointer to the memory-mapped image of the *pfb* file. Otherwise, this function returns **NULL**.

## Remarks

**FONTOBJ_pvTrueTypeFontFile** should be called only for TrueType, OpenType, or Type1 fonts. The pointer returned by **FONTOBJ_pvTrueTypeFontFile** is valid only within the scope of the calling [DrvTextOut](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-drvtextout) function. That is, the driver should not assume that the pointer returned by this function is valid upon exiting *DrvTextOut* and returning control to GDI.

## See also

[DrvTextOut](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-drvtextout)

[FONTOBJ](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-fontobj)