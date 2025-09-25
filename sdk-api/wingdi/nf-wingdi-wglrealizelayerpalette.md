# wglRealizeLayerPalette function

## Description

The **wglRealizeLayerPalette** function maps palette entries from a given color-index layer plane into the physical palette or initializes the palette of an RGBA layer plane.

## Parameters

### `unnamedParam1`

Specifies the device context of a window whose layer plane palette is to be realized into the physical palette.

### `unnamedParam2`

Specifies the overlay or underlay plane. Positive values of *iLayerPlane* identify overlay planes, where 1 is the first overlay plane over the main plane, 2 is the second overlay plane over the first overlay plane, and so on. Negative values identify underlay planes, where 1 is the first underlay plane under the main plane, 2 is the second underlay plane under the first underlay plane, and so on. The number of overlay and underlay planes is given in the **bReserved** member of the [PIXELFORMATDESCRIPTOR](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-pixelformatdescriptor) structure.

### `unnamedParam3`

Indicates whether the palette is to be realized into the physical palette. When *bRealize* is **TRUE**, the palette entries are mapped into the physical palette where available. When *bRealize* is **FALSE**, the palette entries for the layer plane of the window are no longer needed and might be released for use by another foreground window.

## Return value

If the function succeeds, the return value is **TRUE**, even if *bRealize* is **TRUE** and the physical palette is not available. If the function fails or when no pixel format is selected, the return value is **FALSE**. To get extended error information, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

The physical palette for a layer plane is a shared resource among windows with layer planes. When more than one window attempts to realize a palette for a given physical layer plane, only one palette at a time is realized. When you call the **wglRealizeLayerPalette** function, the layer palette of a foreground window is always realized first.

When a window's layer palette is realized, its palette entries are always mapped one-to-one into the physical palette. Unlike GDI logical palettes, with **wglRealizeLayerPalette** there is no mapping of other windows' layer palettes to the current physical palette.

Whenever a window becomes the foreground window, call **wglRealizeLayerPalette** to realize its layer palettes again, even if the pixel type of the layer plane is RGBA.

Because **wglRealizeLayerPalette** doesn't realize the palette of the main plane, use GDI palette functions to realize the main plane palette.

## See also

[LAYERPLANEDESCRIPTOR](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-layerplanedescriptor)

[OpenGL on Windows](https://learn.microsoft.com/windows/desktop/OpenGL/opengl-on-windows-nt--windows-2000--and-windows-95-98)

[PIXELFORMATDESCRIPTOR](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-pixelformatdescriptor)

[WGL Functions](https://learn.microsoft.com/windows/desktop/OpenGL/wgl-functions)

[wglDescribeLayerPlane](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-wgldescribelayerplane)

[wglGetLayerPaletteEntries](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-wglgetlayerpaletteentries)

[wglRealizeLayerPalette](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-wglrealizelayerpalette)

[wglSetLayerPaletteEntries](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-wglsetlayerpaletteentries)