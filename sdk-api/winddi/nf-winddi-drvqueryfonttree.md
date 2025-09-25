# DrvQueryFontTree function

## Description

The **DrvQueryFontTree** function provides GDI with a pointer to a structure that defines one of the following:

* A mapping from Unicode to glyph handles, including glyph variants
* A mapping of kerning pairs to kerning handles

## Parameters

### `dhpdev`

Identifies a device by a handle to its [PDEV](https://learn.microsoft.com/windows-hardware/drivers/), returned from a prior call to [DrvEnablePDEV](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-drvenablepdev).

### `iFile`

Identifies the driver font file. This value is returned by [DrvLoadFontFile](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-drvloadfontfile).

### `iFace`

Specifies the one-based index of the driver font.

### `iMode`

Specifies the type of information to be provided. This can be one of the following values:

| Value | Meaning |
| --- | --- |
| QFT_GLYPHSET | GDI requests a pointer to an [FD_GLYPHSET](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-fd_glyphset) structure that defines the mappings from single Unicode characters to glyph handles. |
| QFT_KERNPAIRS | GDI requests a pointer to a sorted, null-terminated array of [FD_KERNINGPAIR](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-fd_kerningpair) structures.<br><br>The kerning pairs should be stored in increasing order. The primary key is the second Unicode character; the secondary key is the first Unicode character in the kerning pair. |

### `pid`

Pointer to a memory location holding the address of a driver-defined value. GDI passes the contents of **pid* to [DrvFree](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-drvfree), along with the returned pointer, when the FD_GLYPHSET structure or array of FD_KERNINGPAIR structures are no longer needed. Depending on how memory is managed in the driver, the driver-defined value can identify the structure, identify the way it was allocated, or do nothing at all.

## Return value

The return value is a pointer to the requested structure if the function is successful. Otherwise, it is **NULL**, and an error code is logged.

## Remarks

The returned structure must remain unmodified until GDI calls [DrvFree](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-drvfree) with the address of the structure.

**DrvQueryFontTree** is required for font drivers and drivers that use device-specific fonts.

## See also

[DEVINFO](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-devinfo)

[DrvEnablePDEV](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-drvenablepdev)

[DrvFree](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-drvfree)

[DrvLoadFontFile](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-drvloadfontfile)

[DrvQueryFontData](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-drvqueryfontdata)

[DrvQueryFontTree](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-drvqueryfonttree)

[FD_GLYPHSET](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-fd_glyphset)

[FD_KERNINGPAIR](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-fd_kerningpair)

[IFIMETRICS](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-ifimetrics)