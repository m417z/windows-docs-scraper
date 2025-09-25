## Description

Creates an image source from a set of DXGI surface(s). The YCbCr surface(s) are converted to RGBA automatically during subsequent drawing.

## Parameters

### `surfaces`

Type: [in] **[IDXGISurface](https://learn.microsoft.com/windows/desktop/api/dxgi/nn-dxgi-idxgisurface)****

The DXGI surfaces to create the image source from.

### `surfaceCount`

Type: **UINT32**

The number of surfaces provided; must be between one and three.

### `colorSpace`

Type: **[DXGI_COLOR_SPACE_TYPE](https://learn.microsoft.com/windows/desktop/api/dxgicommon/ne-dxgicommon-dxgi_color_space_type)**

The color space of the input.

### `options`

Type: **[D2D1_IMAGE_SOURCE_FROM_DXGI_OPTIONS](https://learn.microsoft.com/windows/desktop/api/d2d1_3/ne-d2d1_3-d2d1_image_source_from_dxgi_options)**

Options controlling color space conversions.

### `imageSource`

Type: [out] **[ID2D1ImageSource](https://learn.microsoft.com/windows/desktop/api/d2d1_3/nn-d2d1_3-id2d1imagesource)****

Receives the new image source instance.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

S_OK if successful, otherwise a failure HRESULT.

## Remarks

This method creates an image source, which can be used to draw the image.

This method supports surfaces that use a limited set of DXGI formats and DXGI color space types. Only the below set of combinations of color space types, surface formats, and surface counts are supported:

| Color Space Type | Surface Count(s) | Surface Format(s) |
| --- | --- | --- |
| DXGI_COLOR_SPACE_RGB_FULL_G22_NONE_P709 | 1 | Standard D2D-supported pixel formats:<br><br>* DXGI_FORMAT_A8_UNORM<br>* DXGI_FORMAT_R8_UNORM<br>* DXGI_FORMAT_R8G8_UNORM<br>* DXGI_FORMAT_R8G8B8A8_UNORM<br>* DXGI_FORMAT_B8G8R8A8_UNORM<br>* DXGI_FORMAT_B8G8R8X8_UNORM<br>* DXGI_FORMAT_R8G8B8A8_UNORM_SRGB<br>* DXGI_FORMAT_B8G8R8A8_UNORM_SRGB<br>* DXGI_FORMAT_R16G16B16A16_FLOAT<br>* DXGI_FORMAT_R16G16B16A16_UNORM<br>* DXGI_FORMAT_R32G32B32A32_FLOAT<br>* DXGI_FORMAT_BC1_UNORM<br>* DXGI_FORMAT_BC2_UNORM<br>* DXGI_FORMAT_BC3_UNORM |
| DXGI_COLOR_SPACE_YCBCR_FULL_G22_NONE_P709_X601 | 1, 2, 3 | When Surface count is 1:<br><br>* DXGI_FORMAT_AYUV<br>* DXGI_FORMAT_NV12<br>* DXGI_FORMAT_YUY2<br>* DXGI_FORMAT_P208<br>* DXGI_FORMAT_V208<br>* DXGI_FORMAT_V408<br><br>When Surface Count is 2:<br><br>* {DXGI_FORMAT_R8_UNORM, DXGI_FORMAT_R8G8_UNORM}<br><br>When Surface Count is 3:<br><br>* {DXGI_FORMAT_R8_UNORM, DXGI_FORMAT_R8_UNORM, DXGI_FORMAT_R8_UNORM} |
| DXGI_COLOR_SPACE_YCBCR_STUDIO_G22_LEFT_P601 DXGI_COLOR_SPACE_YCBCR_FULL_G22_LEFT_P601<br><br>DXGI_COLOR_SPACE_YCBCR_STUDIO_G22_LEFT_P709<br><br>DXGI_COLOR_SPACE_YCBCR_FULL_G22_LEFT_P709<br><br>DXGI_COLOR_SPACE_YCBCR_STUDIO_G22_LEFT_P2020<br><br>DXGI_COLOR_SPACE_YCBCR_FULL_G22_LEFT_P2020 | 1,2,3 | When Surface count is 1: <br><br>* DXGI_FORMAT_NV12<br>* DXGI_FORMAT_YUY2<br>* DXGI_FORMAT_P208<br>* DXGI_FORMAT_V208<br><br>When Surface Count is 2:<br><br>* {DXGI_FORMAT_R8_UNORM, DXGI_FORMAT_R8G8_UNORM}<br><br>When Surface Count is 3:<br><br>* {DXGI_FORMAT_R8_UNORM, DXGI_FORMAT_R8_UNORM, DXGI_FORMAT_R8_UNORM} |

The GPU must also have sufficient support for a pixel format to be supported by D2D. To determine whether D2D supports a format, call IsDxgiFormatSupported.

This API converts YCbCr formats to sRGB using the provided color space type and options. RGBA data is assumed to be in the desired space, and D2D does not apply any conversion.

If multiple surfaces are provided, this method infers whether chroma planes are subsampled (by 2x) from the relative sizes of each
corresponding source rectangle (or if the source rectangles parameter is NULL, the bounds of each surface). The second and third rectangle must each
be equal in size to the first rectangle, or to the first rectangle with one or both dimensions scaled by 0.5 (while rounding up).

If provided, the source rectangles must be within the bounds of the corresponding surface. The source rectangles may have different origins.
In this case, this method shifts the data from each plane to align with one another.

## See also

[ID2D1DeviceContext2](https://learn.microsoft.com/windows/desktop/api/d2d1_3/nn-d2d1_3-id2d1devicecontext2)