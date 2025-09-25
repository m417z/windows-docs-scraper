# EngUnmapFontFileFD function

## Description

The **EngUnmapFontFileFD** function unmaps the specified font file from system memory.

## Parameters

### `iFile` [in]

Pointer to a driver-defined value that identifies the font file to be unmapped. This pointer is obtained from [DrvLoadFontFile](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-drvloadfontfile).

## Return value

None

## Remarks

A font driver calls **EngUnmapFontFileFD** to unmap a font file that was previously mapped by [EngMapFontFileFD](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-engmapfontfilefd).

## See also

[DrvLoadFontFile](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-drvloadfontfile)

[EngMapFontFileFD](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-engmapfontfilefd)