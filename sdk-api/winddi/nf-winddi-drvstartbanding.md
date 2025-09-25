# DrvStartBanding function

## Description

The **DrvStartBanding** function is called by GDI when it is ready to start sending bands of a physical page to the driver for rendering.

## Parameters

### `pso` [in]

Caller-supplied pointer to a [SURFOBJ](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-surfobj) structure, which identifies the banding surface.

### `pptl` [in]

Caller-supplied pointer to a [POINTL](https://learn.microsoft.com/windows/desktop/api/windef/ns-windef-pointl) structure to receive the function-supplied origin of the first band.

## Return value

If the operation succeeds, the function should return **TRUE**. Otherwise, it should call the Win32 **SetLastError** function to set an error code, and then return **FALSE**.

## Remarks

If a printer graphics DLL uses GDI-managed surfaces, and if it supports surface banding, it must provide a [DrvNextBand](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-drvnextband) function. GDI calls **DrvStartBanding** only if the printer graphics DLL's [DrvEnableSurface](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-drvenablesurface) function previously called [EngMarkBandingSurface](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-engmarkbandingsurface) to specify a banding surface.

The **DrvStartBanding** function's purpose is to allow the printer graphics DLL to perform any initializations needed before banding operations begin on a physical page, and to provide GDI with the indices of the first band's origin.

The **DrvStartBanding** function is called once per page. Each time GDI has finished drawing a band, it calls [DrvNextBand](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-drvnextband) so the driver can send the band to the printer.

## See also

[DrvEnableSurface](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-drvenablesurface)

[DrvNextBand](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-drvnextband)

[EngMarkBandingSurface](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-engmarkbandingsurface)