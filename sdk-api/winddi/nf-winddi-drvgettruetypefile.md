# DrvGetTrueTypeFile function

## Description

The **DrvGetTrueTypeFile** function accesses a memory-mapped TrueType font file.

## Parameters

### `iFile`

Pointer to a driver-defined value that identifies a driver's TrueType font file.

### `pcj`

Pointer to a ULONG value that specifies the size, in bytes, of the font file. This parameter cannot be **NULL**.

## Return value

The return value is a pointer to the memory-mapped TrueType font file if the function is successful. Otherwise, it is **NULL**.

## Remarks

This private entry point is provided by the TrueType driver to allow GDI efficient access to the memory-mapped TrueType font file.

**DrvGetTrueTypeFile** is required for TrueType font drivers.

## See also

[DrvLoadFontFile](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-drvloadfontfile)