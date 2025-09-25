# wglSetLayerPaletteEntries function

## Description

Sets the palette entries in a given color-index layer plane for a specified device context.

## Parameters

### `unnamedParam1`

Type: **HDC**

The device context of a window whose layer palette is to be set.

### `unnamedParam2`

Type: **int**

An overlay or underlay plane. Positive values of *iLayerPlane* identify overlay planes, where 1 is the first overlay plane over the main plane, 2 is the second overlay plane over the first overlay plane, and so on. Negative values identify underlay planes, where 1 is the first underlay plane under the main plane, 2 is the second underlay plane under the first underlay plane, and so on. The number of overlay and underlay planes is given in the **bReserved** member of the [PIXELFORMATDESCRIPTOR](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-pixelformatdescriptor) structure.

### `unnamedParam3`

Type: **int**

The first palette entry to be set.

### `unnamedParam4`

Type: **int**

The number of palette entries to be set.

### `unnamedParam5`

Type: **const [COLORREF](https://learn.microsoft.com/windows/desktop/gdi/colorref)***

A pointer to the first member of an array of *cEntries* structures that contain RGB color information.

## Return value

Type: **int**

If the function succeeds, the return value is the number of entries that were set in the palette in the specified layer plane of the window. If the function fails or no pixel format is selected, the return value is zero. To get extended error information, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

Each color-index plane in a window has a palette with a size 2^n, where *n* is the number of bit planes in the layer plane. You cannot modify the transparent index of a palette.

Use the **wglRealizeLayerPalette** function to realize the layer palette. Initially the layer palette contains only entries for white.

The **wglSetLayerPaletteEntries** function doesn't set the palette entries of the main plane palette. To update the main plane palette, use GDI palette functions.

## See also

[LAYERPLANEDESCRIPTOR](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-layerplanedescriptor)

[OpenGL on Windows](https://learn.microsoft.com/windows/desktop/OpenGL/opengl-on-windows-nt--windows-2000--and-windows-95-98)

[PIXELFORMATDESCRIPTOR](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-pixelformatdescriptor)

[WGL Functions](https://learn.microsoft.com/windows/desktop/OpenGL/wgl-functions)

[wglDescribeLayerPlane](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-wgldescribelayerplane)

[wglGetLayerPaletteEntries](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-wglgetlayerpaletteentries)

[wglRealizeLayerPalette](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-wglrealizelayerpalette)