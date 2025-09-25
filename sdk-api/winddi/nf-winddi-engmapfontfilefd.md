# EngMapFontFileFD function

## Description

The **EngMapFontFileFD** function maps a font file into system memory, if necessary, and returns a pointer to the base location of the font data in the file.

## Parameters

### `iFile` [in]

Caller-supplied pointer to a value that identifies the font file to be mapped. This pointer must have been received previously as input to [DrvLoadFontFile](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-drvloadfontfile).

### `ppjBuf` [out]

Pointer to a memory location that receives the mapped file's base memory address.

### `pcjBuf` [out]

Pointer to a memory location that receives the size, in bytes, of the mapped file.

## Return value

**EngMapFontFileFD** returns **TRUE** if it succeeds; otherwise, it returns **FALSE**.

## Remarks

The **EngMapFontFileFD** function is provided so font drivers can map a font file into memory and access the file's data. If the font file has not yet been memory-mapped, **EngMapFontFileFD** loads the font data into system memory before returning *ppjBuf* and *pcjBuf* to the driver. If the file is already mapped, the function just returns the file's *ppjBuf* and *pcjBuf* values.

## See also

[DrvLoadFontFile](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-drvloadfontfile)

[EngUnmapFontFileFD](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-engunmapfontfilefd)