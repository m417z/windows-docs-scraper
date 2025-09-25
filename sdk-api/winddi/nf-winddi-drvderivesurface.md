# DrvDeriveSurface function

## Description

The **DrvDeriveSurface** function derives a GDI surface from the specified DirectDraw surface.

## Parameters

### `pDirectDraw`

Pointer to a [DD_DIRECTDRAW_GLOBAL](https://learn.microsoft.com/windows/desktop/api/ddrawint/ns-ddrawint-dd_directdraw_global) structure that describes the DirectDraw object.

### `pSurface`

Pointer to a [DD_SURFACE_LOCAL](https://learn.microsoft.com/windows/desktop/api/ddrawint/ns-ddrawint-dd_surface_local) structure that describes the DirectDraw surface around which to wrap a GDI surface.

## Return value

**DrvDeriveSurface** returns a handle to the derived GDI surface upon success. It returns **NULL** if the call fails or if the driver cannot accelerate GDI drawing to the specified DirectDraw surface.

## Remarks

**DrvDeriveSurface** allows the driver to create a GDI surface wrapped around a DirectDraw video memory or AGP surface object in order to allow accelerated GDI drawing to the surface. If the driver does not hook this call, all GDI drawing to DirectDraw surfaces is done in software using the DIB engine.

GDI calls **DrvDeriveSurface** with RGB surfaces only.

The driver should call [DrvCreateDeviceBitmap](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-drvcreatedevicebitmap) to create a GDI surface of the same size and format as that of the DirectDraw surface. Space for the actual pixels need not be allocated since it already exists.

## See also

[DrvCreateDeviceBitmap](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-drvcreatedevicebitmap)

[EngCreateDeviceBitmap](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-engcreatedevicebitmap)

[EngModifySurface](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-engmodifysurface)