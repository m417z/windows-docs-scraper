# STROBJ_bGetAdvanceWidths function

## Description

The **STROBJ_bGetAdvanceWidths** function retrieves an array of vectors specifying the probable widths of glyphs making up a specified string.

## Parameters

### `pso`

Is a caller-supplied pointer to a [STROBJ](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-strobj) structure describing a text string. This is typically the STROBJ structure received by the driver's [DrvTextOut](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-drvtextout) function.

### `iFirst` [in]

Is a caller-supplied, zero-based index into the text string supplied by the STROBJ structure. This index represents the first character of the string for which a width is to be returned.

### `c`

Is a caller-supplied count of the number of contiguous characters, starting and the character specified by *iFirst*, for which width values are to be returned.

### `pptqD`

Is a caller-supplied pointer to a *c*-sized array of POINTQF structures to receive character widths in (28.36, 28.36) format. For a description of this data type, see [GDI Data Types](https://learn.microsoft.com/windows-hardware/drivers/display/gdi-data-types).

## Return value

If the operation succeeds, the function returns **TRUE**; otherwise it returns **FALSE**.

## Remarks

The **STROBJ_bGetAdvanceWidths** function is useful to printer drivers that call [STROBJ_bEnumPositionsOnly](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-strobj_benumpositionsonly) instead of [STROBJ_bEnum](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-strobj_benum). The function fills in the *pptqD* array with the probable widths of a string's glyphs, and can be used to calculate the printer position after a string as been rendered by the printer, if the printer's glyph rendering hardware does not return exact character widths.

Note that glyph positions returned by **STROBJ_bEnumPositionsOnly** do not necessarily correspond exactly to the widths returned by **STROBJ_bGetAdvanceWidths.**

## See also

[DrvTextOut](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-drvtextout)

[STROBJ](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-strobj)

[STROBJ_bEnum](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-strobj_benum)

[STROBJ_bEnumPositionsOnly](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-strobj_benumpositionsonly)