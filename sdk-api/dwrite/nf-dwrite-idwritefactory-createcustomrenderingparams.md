# IDWriteFactory::CreateCustomRenderingParams

## Description

Creates a rendering parameters object with the specified properties.

## Parameters

### `gamma`

Type: **FLOAT**

The gamma level to be set for the new rendering parameters object.

### `enhancedContrast`

Type: **FLOAT**

The enhanced contrast level to be set for the new rendering parameters object.

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

Type: **[IDWriteRenderingParams](https://learn.microsoft.com/windows/win32/api/dwrite/nn-dwrite-idwriterenderingparams)****

When this method returns, contains an address of a pointer to the newly created rendering parameters object.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IDWriteFactory](https://learn.microsoft.com/windows/win32/api/dwrite/nn-dwrite-idwritefactory)