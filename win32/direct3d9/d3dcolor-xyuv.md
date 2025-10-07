# D3DCOLOR\_XYUV macro

Initializes a color with the (y, u, v) values.

## Parameters

*y*

Luminance component of the color. This value must be in the range 0 through 255.

*u*

Blue brightness of the color. This value must be in the range 0 through 255.

*v*

Red brightness of the color. This value must be in the range 0 through 255.

## Return value

Returns the [**D3DCOLOR**](https://learn.microsoft.com/windows/win32/direct3d9/d3dcolor) value that corresponds to the supplied (y, u, v) values.

## Remarks

An RGB color can be reduced to 16 bits per pixel by conversion to luminance and color differences with the following equations:

```C++
y (luminance) = 0.299*red + 0.587*green + 0.114*blue
u = blue - luminance
v = red - luminance
```

## Requirements

| Requirement | Value |
|-------------------|----------------------------------------------------------------------------------------|
| Header<br> | D3d9types.h |

## See also

[Macros](https://learn.microsoft.com/windows/win32/direct3d9/dx9-graphics-reference-d3d-macros)

[**D3DCOLOR\_ARGB**](https://learn.microsoft.com/windows/win32/direct3d9/d3dcolor-argb)

[**D3DCOLOR\_AYUV**](https://learn.microsoft.com/windows/win32/direct3d9/d3dcolor-ayuv)

