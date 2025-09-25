# DrvUnloadFontFile function

## Description

The **DrvUnloadFontFile** function informs a font driver that the specified font file is no longer needed.

## Parameters

### `iFile`

Pointer to a driver-defined value that identifies the font file to be removed. The *iFile* parameter is the value returned by [DrvLoadFontFile](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-drvloadfontfile).

## Return value

The return value is **TRUE** if the function is successful, and **FALSE** otherwise.

## Remarks

The driver should delete all scratch files, unload all DLLs that were loaded, and free all allocated system resources at this time.

This function is required for font drivers.

## See also

[DrvLoadFontFile](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-drvloadfontfile)