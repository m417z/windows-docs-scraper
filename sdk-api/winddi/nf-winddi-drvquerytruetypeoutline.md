# DrvQueryTrueTypeOutline function

## Description

The **DrvQueryTrueTypeOutline** function retrieves glyph outlines in native TrueType format.

## Parameters

### `dhpdev`

Handle to a physical device's [PDEV](https://learn.microsoft.com/windows-hardware/drivers/) structure returned from a call to [DrvEnablePDEV](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-drvenablepdev).

### `pfo`

Pointer to a [FONTOBJ](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-fontobj) structure. Details of the font realization can be queried from this structure.

### `hglyph`

Handle to the glyph for which the outline is being queried.

### `bMetricsOnly`

Specifies that font metrics (only) should be returned, or that TrueType outlines should be returned in cubic Bezier format, or that the TrueType outlines should be returned unhinted. This value can be one of the following:

| Flag | Meaning |
| --- | --- |
| TTO_METRICS_ONLY | Only font metrics are to be returned. Font data (either outlines or bitmaps) will not be returned. |
| TTO_QUBICS | Outlines are to be returned in cubic Bezier format. |
| TTO_UNHINTED | Outlines are to be returned unhinted. |

### `pgldt`

Pointer to the buffer where the [GLYPHDATA](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-glyphdata) structure for this glyph should be written. If *pgldt* is **NULL**, no data is written to the GLYPHDATA structure.

### `cjBuf`

Specifies the size, in bytes, of the buffer that receives the TrueType outline.

### `ppoly`

Pointer to the buffer where the TrueType outline should be written. The format of the data is in native TrueType format, stored in a TTPOLYGONHEADER structure. See the Microsoft Windows SDK documentation for more information about the TTPOLYGONHEADER structure.

## Return value

The return value is the size, in bytes, required for the *ppoly* buffer if *pgldt* is **NULL**. If *pgldt* is not **NULL**, the return value is the number of bytes copied into the *ppoly* buffer. If an error occurs, the return value is FD_ERROR.

## Remarks

**DrvQueryTrueTypeOutline** is required for TrueType font drivers.

## See also

[DrvEnablePDEV](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-drvenablepdev)

[FONTOBJ](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-fontobj)