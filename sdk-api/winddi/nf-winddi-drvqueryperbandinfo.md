# DrvQueryPerBandInfo function

## Description

A printer graphics DLL's **DrvQueryPerBandInfo** function is called by GDI before it begins drawing a band for a physical page, so the driver can supply GDI with band-specific information.

## Parameters

### `pso` [in]

Caller-supplied pointer to a [SURFOBJ](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-surfobj) structure describing the drawing surface.

### `pbi` [in, out]

Caller-supplied pointer to a [PERBANDINFO](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-perbandinfo) structure containing default information, which the function can overwrite.

## Return value

The function must return one of the following values:

| Return code | Description |
| --- | --- |
| **Greater than zero** | GDI will use the contents of the PERBANDINFO structure. |
| **Zero** | GDI will ignore the contents of the PERBANDINFO structure. |
| **DDI_ERROR** | GDI will not draw the band. |

## Remarks

If a [printer graphics DLL](https://learn.microsoft.com/windows-hardware/drivers/print/printer-graphics-dll) uses GDI-managed surfaces, and if it supports surface banding, it can optionally provide a **DrvQueryPerBandInfo** function. GDI calls the function prior to rendering each band.

The printer graphics DLL uses the function's [PERBANDINFO](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-perbandinfo) structure to indicate whether the previous band should be redrawn, and to specify that the band should be scaled. If a printer graphics DLL supports banding but does not provide a **DrvQueryPerBandInfo** function, GDI will not repeat or scale bands.

The **DrvQueryPerBandInfo** function is only called during playback of EMF files.

## See also

[DrvNextBand](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-drvnextband)

[DrvStartBanding](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-drvstartbanding)