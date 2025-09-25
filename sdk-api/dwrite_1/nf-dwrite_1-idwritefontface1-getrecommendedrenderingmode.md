# IDWriteFontFace1::GetRecommendedRenderingMode

## Description

 Determines the recommended rendering mode for the font, using the specified size and rendering parameters.

## Parameters

### `fontEmSize`

Type: **FLOAT**

The logical size of the font in DIP units. A DIP ("device-independent pixel") equals 1/96 inch.

### `dpiX`

Type: **FLOAT**

The number of physical pixels per DIP in a horizontal position. For example, if the DPI of the rendering surface is 96, this
value is 1.0f. If the DPI is 120, this value is 120.0f/96.

### `dpiY`

Type: **FLOAT**

The number of physical pixels per DIP in a vertical position. For example, if the DPI of the rendering surface is 96, this
value is 1.0f. If the DPI is 120, this value is 120.0f/96.

### `transform` [in, optional]

Type: **const DWRITE_MATRIX***

Specifies the world transform.

### `isSideways`

Type: **BOOL**

Whether the glyphs in the run are sideways or not.

### `outlineThreshold`

Type: **[DWRITE_OUTLINE_THRESHOLD](https://learn.microsoft.com/windows/win32/api/dwrite_1/ne-dwrite_1-dwrite_outline_threshold)**

A [DWRITE_OUTLINE_THRESHOLD](https://learn.microsoft.com/windows/win32/api/dwrite_1/ne-dwrite_1-dwrite_outline_threshold)-typed value that specifies the quality of the graphics system's outline rendering,
affects the size threshold above which outline rendering is used.

### `measuringMode`

Type: **[DWRITE_MEASURING_MODE](https://learn.microsoft.com/windows/win32/api/dcommon/ne-dcommon-dwrite_measuring_mode)**

The measuring method that will be used for glyphs in the font.
Renderer implementations may choose different rendering modes for different measuring methods, for example:

* DWRITE_RENDERING_MODE_CLEARTYPE_NATURAL for [DWRITE_MEASURING_MODE_NATURAL](https://learn.microsoft.com/windows/win32/api/dcommon/ne-dcommon-dwrite_measuring_mode)
* DWRITE_RENDERING_MODE_CLEARTYPE_GDI_CLASSIC for [DWRITE_MEASURING_MODE_GDI_CLASSIC](https://learn.microsoft.com/windows/win32/api/dcommon/ne-dcommon-dwrite_measuring_mode)
* DWRITE_RENDERING_MODE_CLEARTYPE_GDI_NATURAL for [DWRITE_MEASURING_MODE_GDI_NATURAL](https://learn.microsoft.com/windows/win32/api/dcommon/ne-dcommon-dwrite_measuring_mode)

### `renderingMode` [out]

Type: **[DWRITE_RENDERING_MODE](https://learn.microsoft.com/windows/win32/api/dwrite/ne-dwrite-dwrite_rendering_mode)***

When this method returns, contains a value that indicates the recommended rendering mode to use.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

This method should be used to determine the actual rendering mode in cases where the rendering
mode of the rendering params object is DWRITE_RENDERING_MODE_DEFAULT.

## See also

[IDWriteFontFace1](https://learn.microsoft.com/windows/win32/api/dwrite_1/nn-dwrite_1-idwritefontface1)