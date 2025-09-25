# IDWriteFactory2::CreateCustomRenderingParams

## Description

Creates a rendering parameters object with the specified properties.

## Parameters

### `gamma`

Type: **FLOAT**

The gamma value used for gamma correction, which must be greater than zero and cannot exceed 256.

### `enhancedContrast`

Type: **FLOAT**

The amount of contrast enhancement, zero or greater.

### `grayscaleEnhancedContrast`

Type: **FLOAT**

The amount of contrast enhancement, zero or greater.

### `clearTypeLevel`

Type: **FLOAT**

The degree of ClearType level, from 0.0f (no ClearType) to 1.0f (full ClearType).

### `pixelGeometry`

Type: **[DWRITE_PIXEL_GEOMETRY](https://learn.microsoft.com/windows/win32/api/dwrite/ne-dwrite-dwrite_pixel_geometry)**

The geometry of a device pixel.

### `renderingMode`

Type: **[DWRITE_RENDERING_MODE](https://learn.microsoft.com/windows/win32/api/dwrite/ne-dwrite-dwrite_rendering_mode)**

Method of rendering glyphs. In most cases, this should be DWRITE_RENDERING_MODE_DEFAULT to automatically use an appropriate mode.

### `gridFitMode`

Type: **[DWRITE_GRID_FIT_MODE](https://learn.microsoft.com/windows/win32/api/dwrite_2/ne-dwrite_2-dwrite_grid_fit_mode)**

How to grid fit glyph outlines. In most cases, this should be DWRITE_GRID_FIT_DEFAULT to automatically choose an appropriate mode.

### `renderingParams` [out]

Type: **[IDWriteRenderingParams2](https://learn.microsoft.com/windows/win32/api/dwrite_2/nn-dwrite_2-idwriterenderingparams2)****

Holds the newly created rendering parameters object, or NULL in case of failure.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IDWriteFactory2](https://learn.microsoft.com/windows/win32/api/dwrite_2/nn-dwrite_2-idwritefactory2)