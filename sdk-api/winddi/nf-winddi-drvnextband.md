# DrvNextBand function

## Description

The **DrvNextBand** function is called by GDI when it has finished drawing a band for a physical page, so the driver can send the next band to the printer.

## Parameters

### `pso` [in]

Caller-supplied pointer to a [SURFOBJ](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-surfobj) structure, which identifies the banding surface.

### `pptl` [in]

Caller-supplied pointer to a [POINTL](https://learn.microsoft.com/windows/desktop/api/windef/ns-windef-pointl) structure to receive the function-supplied origin of the next band.

## Return value

If the operation succeeds, the function should return **TRUE**. Otherwise, it should call the Win32 **SetLastError** function to set an error code, and then return **FALSE**.

## Remarks

If a [printer graphics DLL](https://learn.microsoft.com/windows-hardware/drivers/print/printer-graphics-dll) uses GDI-managed surfaces, and if it supports surface banding, it must provide a **DrvNextBand** function. GDI calls **DrvNextBand** each time it has finished drawing the portion of the page's image that can be contained on the band's surface. The surface used by GDI for drawing is one that the driver previously specified by calling [EngMarkBandingSurface](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-engmarkbandingsurface). The function should send the image to the printer by calling [EngWritePrinter](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-engwriteprinter), and it should return the indices of the next band's origin in the POINTL structure pointed to by *pptl*.

After all of a physical page's bands have been drawn, the function should set both members of the POINTL structure pointed to by *pptl* to -1.

## See also

[DrvEnableSurface](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-drvenablesurface)

[DrvStartBanding](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-drvstartbanding)

[EngMarkBandingSurface](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-engmarkbandingsurface)

[EngWritePrinter](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-engwriteprinter)