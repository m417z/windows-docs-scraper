# IDWriteFactory3::CreateCustomRenderingParams

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

The amount of contrast enhancement to use for grayscale antialiasing, zero or greater.

### `clearTypeLevel`

Type: **FLOAT**

The degree of ClearType level, from 0.0f (no ClearType) to 1.0f (full ClearType).

### `pixelGeometry`

Type: **[DWRITE_PIXEL_GEOMETRY](https://learn.microsoft.com/windows/win32/api/dwrite/ne-dwrite-dwrite_pixel_geometry)**

A [DWRITE_PIXEL_GEOMETRY](https://learn.microsoft.com/windows/win32/api/dwrite/ne-dwrite-dwrite_pixel_geometry)-typed value that specifies the internal structure of a device pixel (that is, the physical arrangement of red, green, and blue color components) that is assumed for purposes of rendering text.

### `renderingMode`

Type: **[DWRITE_RENDERING_MODE1](https://learn.microsoft.com/windows/win32/api/dwrite_3/ne-dwrite_3-dwrite_rendering_mode1)**

A [DWRITE_RENDERING_MODE1](https://learn.microsoft.com/windows/win32/api/dwrite_3/ne-dwrite_3-dwrite_rendering_mode1)-typed value that specifies the method (for example, ClearType natural quality) for rendering glyphs. In most cases, specify **DWRITE_RENDERING_MODE1_DEFAULT** to automatically use an appropriate mode.

### `gridFitMode`

Type: **[DWRITE_GRID_FIT_MODE](https://learn.microsoft.com/windows/win32/api/dwrite_2/ne-dwrite_2-dwrite_grid_fit_mode)**

A [DWRITE_GRID_FIT_MODE](https://learn.microsoft.com/windows/win32/api/dwrite_2/ne-dwrite_2-dwrite_grid_fit_mode)-typed value that specifies how to grid-fit glyph outlines. In most cases, specify **DWRITE_GRID_FIT_DEFAULT** to automatically choose an appropriate mode.

### `renderingParams` [out]

Type: **[IDWriteRenderingParams3](https://learn.microsoft.com/windows/win32/api/dwrite_3/nn-dwrite_3-idwriterenderingparams3)****

A pointer to a memory block that receives a pointer to a [IDWriteRenderingParams3](https://learn.microsoft.com/windows/win32/api/dwrite_3/nn-dwrite_3-idwriterenderingparams3) interface for the newly created rendering parameters object, or **NULL** in case of failure.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IDWriteFactory3](https://learn.microsoft.com/windows/win32/api/dwrite_3/nn-dwrite_3-idwritefactory3)