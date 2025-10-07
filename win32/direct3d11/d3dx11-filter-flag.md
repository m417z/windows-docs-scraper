# D3DX11\_FILTER\_FLAG enumeration

> [!Note]
> The D3DX (D3DX 9, D3DX 10, and D3DX 11) utility library is deprecated for Windows 8 and is not supported for Windows Store apps.

Texture filtering flags.

## Constants

**D3DX11\_FILTER\_NONE**

No scaling or filtering will take place. Pixels outside the bounds of the source image are assumed to be transparent black.

**D3DX11\_FILTER\_POINT**

Each destination pixel is computed by sampling the nearest pixel from the source image.

**D3DX11\_FILTER\_LINEAR**

Each destination pixel is computed by sampling the four nearest pixels from the source image. This filter works best when the scale on both axes is less than two.

**D3DX11\_FILTER\_TRIANGLE**

Every pixel in the source image contributes equally to the destination image. This is the slowest of the filters.

**D3DX11\_FILTER\_BOX**

Each pixel is computed by averaging a 2x2(x2) box of pixels from the source image. This filter works only when the dimensions of the destination are half those of the source, as is the case with mipmaps.

**D3DX11\_FILTER\_MIRROR\_U**

Pixels off the edge of the texture on the u-axis should be mirrored, not wrapped.

**D3DX11\_FILTER\_MIRROR\_V**

Pixels off the edge of the texture on the v-axis should be mirrored, not wrapped.

**D3DX11\_FILTER\_MIRROR\_W**

Pixels off the edge of the texture on the w-axis should be mirrored, not wrapped.

**D3DX11\_FILTER\_MIRROR**

Specifying this flag is the same as specifying the D3DX\_FILTER\_MIRROR\_U, D3DX\_FILTER\_MIRROR\_V, and D3DX\_FILTER\_MIRROR\_W flags.

**D3DX11\_FILTER\_DITHER**

The resulting image must be dithered using a 4x4 ordered dither algorithm. This happens when converting from one format to another.

**D3DX11\_FILTER\_DITHER\_DIFFUSION**

Do diffuse dithering on the image when changing from one format to another.

**D3DX11\_FILTER\_SRGB\_IN**

Input data is in standard RGB (sRGB) color space. See remarks.

**D3DX11\_FILTER\_SRGB\_OUT**

Output data is in standard RGB (sRGB) color space. See remarks.

**D3DX11\_FILTER\_SRGB**

Same as specifying D3DX\_FILTER\_SRGB\_IN \| D3DX\_FILTER\_SRGB\_OUT. See remarks.

## Remarks

D3DX11 automatically performs gamma correction (to convert color data from RGB space to standard RGB space) when loading texture data. This is automatically done for instance when RGB data is loaded from a .png file into an sRGB texture. Use the SRGB filter flags to indicate if the data does not need to be converted into sRGB space.

## Requirements

| Requirement | Value |
|-------------------|----------------------------------------------------------------------------------------|
| Header<br> | D3DX11tex.h |

## See also

[D3DX Enumerations](https://learn.microsoft.com/windows/win32/direct3d11/d3d11-graphics-reference-d3dx11-enums)

