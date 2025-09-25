# FONTOBJ_pwszFontFilePaths function

## Description

The **FONTOBJ_pwszFontFilePaths** function retrieves the file path(s) associated with a font.

## Parameters

### `pfo`

Pointer to the [FONTOBJ](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-fontobj) structure being queried.

### `pcwc`

Pointer to the location in which GDI returns the number of Unicode characters, including terminating zeros, found in all the returned font file path strings.

## Return value

**FONTOBJ_pwszFontFilePaths** returns a pointer to an array of font file path strings upon success. Each string is null terminated by a single Unicode zero. This function returns **NULL** upon failure or when the paths are not available for the specified font; that is, when the font is a temporary font added from a memory image.

## Remarks

Printer drivers can call **FONTOBJ_pwszFontFilePaths** when they want to do their own file mapping. File mapping is performed by calling [EngMapFile](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-engmapfile).

Typically, there is only one file per font. For example, a TrueType font has only one file, whereas Type 1 fonts might require two files (a *.*[pfm](https://learn.microsoft.com/windows-hardware/drivers/) and *.pfb*).

## See also

[EngMapFile](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-engmapfile)

[FONTOBJ](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-fontobj)