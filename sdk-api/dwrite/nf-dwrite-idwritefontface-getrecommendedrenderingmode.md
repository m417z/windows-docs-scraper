# IDWriteFontFace::GetRecommendedRenderingMode

## Description

 Determines the recommended rendering mode for the font, using the specified size and rendering parameters.

## Parameters

### `emSize`

Type: **FLOAT**

The logical size of the font in DIP units. A DIP ("device-independent pixel") equals 1/96 inch.

### `pixelsPerDip`

Type: **FLOAT**

The number of physical pixels per DIP. For example, if the DPI of the rendering surface is 96, this
value is 1.0f. If the DPI is 120, this value is 120.0f/96.

### `measuringMode`

Type: **[DWRITE_MEASURING_MODE](https://learn.microsoft.com/windows/win32/api/dcommon/ne-dcommon-dwrite_measuring_mode)**

The measuring method that will be used for glyphs in the font.
Renderer implementations may choose different rendering modes for different measuring methods, for example:

* DWRITE_RENDERING_MODE_CLEARTYPE_NATURAL for [DWRITE_MEASURING_MODE_NATURAL](https://learn.microsoft.com/windows/win32/api/dcommon/ne-dcommon-dwrite_measuring_mode)
* DWRITE_RENDERING_MODE_CLEARTYPE_GDI_CLASSIC for [DWRITE_MEASURING_MODE_GDI_CLASSIC](https://learn.microsoft.com/windows/win32/api/dcommon/ne-dcommon-dwrite_measuring_mode)
* DWRITE_RENDERING_MODE_CLEARTYPE_GDI_NATURAL for [DWRITE_MEASURING_MODE_GDI_NATURAL](https://learn.microsoft.com/windows/win32/api/dcommon/ne-dcommon-dwrite_measuring_mode)

### `renderingParams`

Type: **[IDWriteRenderingParams](https://learn.microsoft.com/windows/win32/api/dwrite/nn-dwrite-idwriterenderingparams)***

A pointer to an object that contains rendering settings such as gamma level, enhanced contrast, and ClearType level. This parameter is necessary in case the rendering parameters
object overrides the rendering mode.

### `renderingMode` [out]

Type: **[DWRITE_RENDERING_MODE](https://learn.microsoft.com/windows/win32/api/dwrite/ne-dwrite-dwrite_rendering_mode)***

When this method returns, contains a value that indicates the recommended rendering mode to use.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IDWriteFontFace](https://learn.microsoft.com/windows/win32/api/dwrite/nn-dwrite-idwritefontface)