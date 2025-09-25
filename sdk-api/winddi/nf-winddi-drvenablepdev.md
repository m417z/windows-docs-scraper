# DrvEnablePDEV function

## Description

The **DrvEnablePDEV** function returns a description of the physical device's characteristics to GDI.

## Parameters

### `pdm` [in]

Pointer to a [DEVMODEW](https://learn.microsoft.com/windows/win32/api/wingdi/ns-wingdi-devmodew) structure that contains driver data.

For a driver that supports Windows NT 4.0, **DrvEnablePDEV** should return the default mode of the hardware when GDI calls it with the following [DEVMODEW](https://learn.microsoft.com/windows/win32/api/wingdi/ns-wingdi-devmodew) members set to zero: **dmBitsPerPel**, **dmPelsWidth**, **dmPelsHeight**, and **dmDisplayFrequency**.

### `pwszLogAddress` [in]

For printer drivers, points to the logical address string that is the user's name for the location to which the driver is writing. Examples include "LPT1" or "My Printer."

Display drivers should ignore this parameter.

### `cPat`

For printer drivers, specifies the number of surface handles in the buffer pointed to by *phsurfPatterns*. The driver cannot access memory beyond the end of the buffer.

Display drivers should ignore this parameter.

### `phsurfPatterns` [in, optional]

Display drivers should ignore this parameter.

For printer drivers, points to a buffer that the driver will fill with surface handles representing the standard fill patterns. The following patterns must be defined in order:

| Pattern | Description |
| --- | --- |
| HS_HORIZONTAL | Horizontal hatch. |
| HS_VERTICAL | Vertical hatch. |
| HS_FDIAGONAL | 45-degree upward hatch (left to right). |
| HS_BDIAGONAL | 45-degree downward hatch (left to right). |
| HS_CROSS | Horizontal and vertical cross hatch. |
| HS_DIAGCROSS | 45-degree crosshatch. |

**Note** The number of default hatch patterns that require driver support was reduced in a previous version of the Driver Development Kit (DDK). Consequently, HS_DDI_MAX, typically used by drivers to declare the size of the pattern array, was reduced.

GDI calls [DrvRealizeBrush](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-drvrealizebrush) with one of these surfaces to realize a brush with a standard pattern.

Each of these surfaces must be a monochrome (1 bit per pixel) GDI bitmap for raster devices. The device driver should choose patterns that will look most like standard patterns when written on the device surface.

GDI is never required to use these brushes in support routines for a vector device. Therefore, surfaces can be device-supported surfaces that [DrvRealizeBrush](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-drvrealizebrush) recognizes as standard patterns.

### `cjCaps`

Specifies the size of the buffer pointed to by *pdevcaps*. The driver must not access memory beyond the end of the buffer.

### `pdevcaps` [out]

Pointer to a [GDIINFO](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-gdiinfo) structure that will be used to describe device capabilities. GDI zero-initializes this structure calling **DrvEnablePDEV**.

### `cjDevInfo`

Specifies the number of bytes in the DEVINFO structure pointed to by *pdi*. The driver should modify no more than this number of bytes in the DEVINFO.

### `pdi` [out]

Pointer to the [DEVINFO](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-devinfo) structure, which describes the driver and the physical device. The driver should only alter the members it understands. GDI fills this structure with zeros before a call to **DrvEnablePDEV**.

### `hdev`

GDI-supplied handle to the device. This handle must be used as input to some GDI callbacks, such as [EngGetDriverName](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-enggetdrivername).

### `pwszDeviceName` [in]

Pointer to a null-terminated string that is the user-readable name of the device.

### `hDriver`

Handle to an output device. For a display driver, this is the display device handle. For a printer driver, this parameter should be used as a handle to the printer in calls to the spooler.

## Return value

The return value is a handle to the [PDEV](https://learn.microsoft.com/windows-hardware/drivers/) that identifies the enabled device if the function is successful. That is, **DrvEnablePDEV** returns a handle to the private, driver-defined device instance information upon success. Otherwise, it returns **NULL**.

## Remarks

A graphics device driver might support several physical devices attached to different logical addresses. Drivers must also support simultaneous use of different drawing surfaces.

The purposes of **DrvEnablePDEV** are the following:

1. To inform GDI of the physical characteristics of the device.
2. To create a private PDEV structure describing the current device instance (based on the received DEVMODE structure and device name).

When GDI subsequently calls other graphics DDI functions, it supplies the handle returned by **DrvEnablePDEV** as input (usually within a SURFOBJ structure) so the driver can identify the device instance.

A single logical device can manage several PDEVs that can be differentiated by the following:

1. Type of hardware -- A single device driver might support "LaserWhiz," "LaserWhiz II," and "LaserWhiz Super."
2. Logical address -- A single device driver can support printers attached to "LPT1," "COM2," "\SERVER1\PSLAZER," and so forth. A display driver that can support more than one VGA display simultaneously might differentiate them according to port numbers; for example, 0x3CE or 0x2CE.
3. Surfaces -- A printer driver can process two print jobs simultaneously. The two surfaces represent two pages that will be printed. Similarly, a display device driver might support two desktops on the same device.

When receiving a call to this function, the driver must allocate the memory to support the PDEV. However, the actual surface need not be supported until GDI calls [DrvEnableSurface](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-drvenablesurface).

If a device surface requires a bitmap to be allocated, these allocations need not be made until needed. Although applications often request device information long before actually writing to the device, waiting to allocate resources, such as large bitmaps, can conserve memory.

GDI zero-initializes the buffer pointed to by *phsurfPatterns* before calling this function.

**DrvEnablePDEV** is required for graphics drivers.

## See also

[DEVINFO](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-devinfo)

[DEVMODEW](https://learn.microsoft.com/windows/win32/api/wingdi/ns-wingdi-devmodew)

[DrvEnableSurface](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-drvenablesurface)

[DrvRealizeBrush](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-drvrealizebrush)

[EngCreatePalette](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-engcreatepalette)

[GDIINFO](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-gdiinfo)