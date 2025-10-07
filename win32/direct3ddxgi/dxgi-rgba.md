# DXGI\_RGBA structure

Represents a color value with alpha, which is used for transparency.

## Members

**r**

Floating-point value that specifies the red component of a color. This value generally is in the range from 0.0 through 1.0. A value of 0.0 indicates the complete absence of the red component, while a value of 1.0 indicates that red is fully present.

**g**

Floating-point value that specifies the green component of a color. This value generally is in the range from 0.0 through 1.0. A value of 0.0 indicates the complete absence of the green component, while a value of 1.0 indicates that green is fully present.

**b**

Floating-point value that specifies the blue component of a color. This value generally is in the range from 0.0 through 1.0. A value of 0.0 indicates the complete absence of the blue component, while a value of 1.0 indicates that blue is fully present.

**a**

Floating-point value that specifies the alpha component of a color. This value generally is in the range from 0.0 through 1.0. A value of 0.0 indicates fully transparent, while a value of 1.0 indicates fully opaque.

## Remarks

You can set the members of this structure to values outside the range of 0 through 1 to implement some unusual effects. Values greater than 1 produce strong lights that tend to wash out a scene. Negative values produce dark lights that actually remove light from a scene.

The DXGItype.h header type-defines **DXGI\_RGBA** as an alias of [**D3DCOLORVALUE**](https://learn.microsoft.com/windows/win32/direct3ddxgi/d3dcolorvalue), as follows:

```
typedef D3DCOLORVALUE DXGI_RGBA;
```

You can use **DXGI\_RGBA** with [**IDXGISwapChain1::SetBackgroundColor**](https://learn.microsoft.com/windows/desktop/api/DXGI1_2/nf-dxgi1_2-idxgiswapchain1-setbackgroundcolor), [**IDXGISwapChain1::GetBackgroundColor**](https://learn.microsoft.com/windows/desktop/api/DXGI1_2/nf-dxgi1_2-idxgiswapchain1-getbackgroundcolor), and [**DXGI\_ALPHA\_MODE**](https://learn.microsoft.com/windows/desktop/api/DXGI1_2/ne-dxgi1_2-dxgi_alpha_mode).

## Requirements

| Requirement | Value |
|-------------------------------------|------------------------------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows 8 and Platform Update for Windows 7 \[desktop apps \| UWP apps\]<br> |
| Minimum supported server<br> | Windows Server 2012 and Platform Update for Windows Server 2008 R2 \[desktop apps \| UWP apps\]<br> |
| Header<br> | DXGItype.h |

## See also

[DXGI Structures](https://learn.microsoft.com/windows/win32/direct3ddxgi/d3d10-graphics-reference-dxgi-structures)

[**D3DCOLORVALUE**](https://learn.microsoft.com/windows/win32/direct3ddxgi/d3dcolorvalue)

[**D3DCOLORVALUE (in Direct3D 9)**](https://learn.microsoft.com/windows/win32/direct3d9/d3dcolorvalue)

