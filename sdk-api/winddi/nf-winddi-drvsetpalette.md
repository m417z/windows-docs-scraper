# DrvSetPalette function

## Description

The **DrvSetPalette** function requests that the driver realize the palette for a specified device.

## Parameters

### `dhpdev`

Handle to the physical device's [PDEV](https://learn.microsoft.com/windows-hardware/drivers/) structure, which identifies the device whose palette is to be realized. This parameter is the device handle returned to GDI by [DrvEnablePDEV](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-drvenablepdev).

### `ppalo`

Pointer to the [PALOBJ](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-palobj) structure from which the colors (RGB values) should be queried.

### `fl`

A set of flags that provides hints and options. This parameter can be the following value:

| Value | Meaning |
| --- | --- |
| SP_DEFAULT | The palette is the device's complete default palette. The [PALOBJ](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-palobj) can be ignored, but contains the correct contents. |

### `iStart`

Specifies the first palette index to overwrite.

### `cColors`

Specifies the number of colors to change in the hardware palette. Extra colors, beyond the number available in the hardware, can be ignored. If *cColors* is smaller than the size of the hardware palette, set only *cColors* entries and leave the remaining colors as they are.

## Return value

The return value is **TRUE** if the function is successful. Otherwise, it is **FALSE**, and an error code is logged.

## Remarks

 The driver sets the hardware palette to match the entries in the given palette as closely as possible.

Only indexed palettes are realizable. The RC_PALETTE bit of the **flRasterCaps** member of the [GDIINFO](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-gdiinfo) structure specifies whether a device has a realizable palette.

**DrvSetPalette** is required for display drivers that support realizable palettes.

## See also

[DrvEnablePDEV](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-drvenablepdev)

[EngCreatePalette](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-engcreatepalette)

[EngDeletePalette](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-engdeletepalette)