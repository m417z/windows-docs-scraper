# DrvQueryFontData function

## Description

The **DrvQueryFontData** function retrieves information about a realized font.

## Parameters

### `dhpdev`

Handle to the physical device's [PDEV](https://learn.microsoft.com/windows-hardware/drivers/) that was returned from a prior call to [DrvEnablePDEV](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-drvenablepdev).

### `pfo`

Pointer to a [FONTOBJ](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-fontobj) structure that defines the font realization.

### `iMode`

Specifies the type of information requested. This parameter can be one of the following values:

| Value | Meaning |
| --- | --- |
| QFD_GLYPHANDBITMAP | If *pgd* is not **NULL**, then the driver should fill in the [GLYPHDATA](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-glyphdata) structure with the metrics of the glyph specified by *hg*.<br><br>If *pv* is not **NULL**, a [GLYPHBITS](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-glyphbits) structure should be written at this address. The driver should copy the glyph bitmap corresponding to the glyph specified by *hg* into this structure. The size of the structure is specified by *cjSize*.<br><br>If glyph bitmaps are not supported by the driver, this function will only be called with *pv* set to **NULL**.<br><br>If the driver supports glyph bitmaps, the return value is the size, in bytes, of the glyph bitmap. Otherwise, it is zero.<br><br>This mode must be supported. |
| QFD_GLYPHANDOUTLINE | If *pgd* is not **NULL**, then the driver should fill in the [GLYPHDATA](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-glyphdata) structure with the metrics of the glyph specified by *hg*.<br><br>If *pv* is not **NULL**, a [PATHOBJ](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-pathobj) structure should be written at this address. The driver passes this PATHOBJ to the PATHOBJ_*Xxx* services to create the outline for the glyph specified by *hg*. The *cjSize* parameter should be ignored.<br><br>The return value is zero if the function is successful. Otherwise, it is FD_ERROR.<br><br>Only font drivers that provide glyph outlines need to support this mode. |
| QFD_MAXEXTENTS | If *pv* is not **NULL**, the driver should write an [FD_DEVICEMETRICS](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-fd_devicemetrics) structure to the buffer pointed to by *pv*.<br><br>The return value is the size, in bytes, needed for the buffer if *pv* is **NULL**. |
| QFD_TT_GRAY1_BITMAP | The realized font should be rendered in one bit-per-pixel of grayscale (that is, either black or white). |
| QFD_TT_GRAY2_BITMAP | The realized font should be rendered in two bits-per-pixel of grayscale. |
| QFD_TT_GRAY4_BITMAP | The realized font should be rendered in four bits-per-pixel of grayscale. |
| QFD_TT_GRAY8_BITMAP | The realized font should be rendered in eight bits-per-pixel of grayscale. |
| QFD_TT_MONO_BITMAP | Same as QFD_TT_GRAY1_BITMAP. |

### `hg`

Handle to the glyph.

### `pgd`

Pointer to [GLYPHDATA](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-glyphdata) structure. This parameter can be **NULL**.

### `pv` [out]

Pointer to a data buffer. The type of data written to this buffer is dependent on *iMode*. This parameter can be **NULL**.

### `cjSize`

Specifies the size of the buffer pointed to by *pv*.

## Return value

The return value depends on the value of the *iMode* parameter. If an error occurs, the return value is FD_ERROR, and an error code is logged.

## Remarks

For the QFD_GLYPHANDBITMAP and QFD_GLYPHANDOUTLINE values of the *iMode* parameter, GDI provides a pointer to a GLYPHDATA structure (in the *pgd* parameter). The driver places information about glyph metrics in this structure and writes the contents of either a GLYPHBITS structure or a PATHOBJ structure in the location specified by the *pv* parameter, depending respectively, on whether the font is a bitmap font or an outline font. For the QFD_MAXEXTENTS value of the *iMode* parameter, the driver writes the contents of an FD_DEVICEMETRICS structure in the location specified by the *pv* parameter.

**DrvQueryFontData** is required for font drivers and drivers that use device-specific or driver-specific fonts.

## See also

[DrvEnablePDEV](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-drvenablepdev)

[DrvQueryFontFile](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-drvqueryfontfile)

[FD_DEVICEMETRICS](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-fd_devicemetrics)

[FONTOBJ](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-fontobj)

[GLYPHBITS](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-glyphbits)

[GLYPHDATA](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-glyphdata)

[PATHOBJ](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-pathobj)