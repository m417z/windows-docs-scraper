# EngMarkBandingSurface function

## Description

The **EngMarkBandingSurface**  function marks the specified surface as a banding surface.

## Parameters

### `hsurf` [in]

Caller-supplied handle to the surface to mark as a banding surface.

## Return value

**EngMarkBandingSurface** returns **TRUE** upon success; otherwise it returns **FALSE**.

## Remarks

If a [printer graphics DLL](https://learn.microsoft.com/windows-hardware/drivers/print/printer-graphics-dll) uses GDI-managed surfaces, it must call **EngMarkBandingSurface** if it cannot create a surface (by calling [EngCreateBitmap](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-engcreatebitmap)) that is large enough to hold an entire physical page's bitmap. Both **EngCreateBitmap** and **EngMarkBandingSurface** should be called from within the printer graphics DLL's [DrvEnableSurface](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-drvenablesurface) function.

The handle supplied for *hsurf* must be a bitmap handle returned by **EngCreateBitmap**.

If a printer graphics DLL calls **EngMarkBandingSurface**, it must define [DrvStartBanding](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-drvstartbanding) and [DrvNextBand](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-drvnextband) functions.

## See also

[DrvEnableSurface](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-drvenablesurface)

[DrvNextBand](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-drvnextband)

[DrvStartBanding](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-drvstartbanding)

[EngCreateBitmap](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-engcreatebitmap)