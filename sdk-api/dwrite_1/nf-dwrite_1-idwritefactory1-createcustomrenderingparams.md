# IDWriteFactory1::CreateCustomRenderingParams

## Description

Creates a rendering parameters object with the specified properties.

## Parameters

### `gamma`

Type: **FLOAT**

The gamma level to be set for the new rendering parameters object.

### `enhancedContrast`

Type: **FLOAT**

The enhanced contrast level to be set for the new rendering parameters object.

### `enhancedContrastGrayscale`

Type: **FLOAT**

The amount of contrast enhancement to use for grayscale antialiasing, zero or greater.

### `clearTypeLevel`

Type: **FLOAT**

The ClearType level to be set for the new rendering parameters object.

### `pixelGeometry`

Type: **[DWRITE_PIXEL_GEOMETRY](https://learn.microsoft.com/windows/win32/api/dwrite/ne-dwrite-dwrite_pixel_geometry)**

Represents the internal structure of a device pixel (that is, the physical arrangement of red, green, and blue color components) that is assumed for purposes of rendering text.

### `renderingMode`

Type: **[DWRITE_RENDERING_MODE](https://learn.microsoft.com/windows/win32/api/dwrite/ne-dwrite-dwrite_rendering_mode)**

A value that represents the method (for example, ClearType natural quality) for rendering glyphs.

### `renderingParams` [out]

Type: **[IDWriteRenderingParams1](https://learn.microsoft.com/windows/win32/api/dwrite_1/nn-dwrite_1-idwriterenderingparams1)****

When this method returns, contains an address of a pointer to the newly created rendering parameters object.

## Return value

Type: **HRESULT**

Standard HRESULT error code.

## See also

[IDWriteFactory1](https://learn.microsoft.com/windows/win32/api/dwrite_1/nn-dwrite_1-idwritefactory1)