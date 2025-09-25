# DrvEnableSurface function

## Description

The **DrvEnableSurface** function sets up a surface to be drawn on and associates it with a given physical device.

## Parameters

### `dhpdev`

Handle to the physical device's [PDEV](https://learn.microsoft.com/windows-hardware/drivers/). This is the return value of [DrvEnablePDEV](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-drvenablepdev). The PDEV describes the physical device for which a surface is to be created.

## Return value

The return value is a handle that identifies the newly created surface. Otherwise, it is zero, and an error code is logged.

## Remarks

There are two methods for preparing a surface for use.

1. In this method, which is recommended, the driver creates the surface by a call to [EngCreateDeviceSurface](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-engcreatedevicesurface). After GDI creates the surface and returns a handle to the driver, the driver calls [EngModifySurface](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-engmodifysurface), which sets the appropriate hook flags, and optionally, informs GDI of the surface's location.
2. The second method is the one used by Windows NT 4.0 drivers. In this method, the driver calls [EngCreateBitmap](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-engcreatebitmap). After this call, the driver calls [EngAssociateSurface](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-engassociatesurface) to associate the surface with the physical display device. This GDI function allows the driver to specify which graphics output routines are supported for standard-format bitmaps. A call to this function can be made only when no surface exists for the given physical device. If a Windows 2000 or later driver is back-ported to run on Windows NT 4.0, this method must be used. If such a driver will also run on Windows 2000 or later, a separate code path in the driver should use the first method.

   For printer devices, the usual situation is for GDI to collect the graphics directly onto a GDI bitmap. The driver should call [EngCreateBitmap](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-engcreatebitmap), which allows GDI to allocate memory for the bitmap.

Any existing GDI bitmap handle is a valid surface handle.

For [printer graphics DLLs](https://learn.microsoft.com/windows-hardware/drivers/print/printer-graphics-dll) that use GDI-managed surfaces, the **DrvEnableSurface** function should call [EngCreateBitmap](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-engcreatebitmap), specifying a surface size large enough to contain an entire physical page. If that fails, repeated calls to **EngCreateBitmap** should be attempted, with decreasing surface sizes, until a call succeeds. The valid size should be specified as input to [EngMarkBandingSurface](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-engmarkbandingsurface), which informs GDI that surface banding will be necessary.

After **DrvEnableSurface** returns a handle to a primary surface, do not call [EngModifySurface](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-engmodifysurface) or [EngAssociateSurface](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-engassociatesurface) on that handle. Doing so can cause a bug check in certain circumstances. For more information, see [Microsoft Knowledge Base article 330248](https://support.microsoft.com/?kbid&ID=330248).

**DrvEnableSurface** is required for graphics drivers.

## See also

[DrvDisableSurface](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-drvdisablesurface)

[DrvEnablePDEV](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-drvenablepdev)

[EngCreateBitmap](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-engcreatebitmap)

[EngCreateDeviceSurface](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-engcreatedevicesurface)