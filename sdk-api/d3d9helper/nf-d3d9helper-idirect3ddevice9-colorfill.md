# IDirect3DDevice9::ColorFill

## Description

Allows an application to fill a rectangular area of a D3DPOOL_DEFAULT surface with a specified color.

## Parameters

### `pSurface` [in]

Type: **[IDirect3DSurface9](https://learn.microsoft.com/windows/desktop/api/d3d9helper/nn-d3d9helper-idirect3dsurface9)***

Pointer to the surface to be filled.

### `pRect` [in]

Type: **const [RECT](https://learn.microsoft.com/windows/desktop/api/windef/ns-windef-rect)***

Pointer to the source rectangle. Using **NULL** means that the entire surface will be filled.

### `color` [in]

Type: **[D3DCOLOR](https://learn.microsoft.com/windows/desktop/direct3d9/d3dcolor)**

Color used for filling.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

If the method succeeds, the return value is D3D_OK. If the method fails, the return value can be
D3DERR_INVALIDCALL.

## Remarks

This method can only be applied to a render target, a render-target texture surface, or an off-screen plain surface with a pool type of D3DPOOL_DEFAULT.

**IDirect3DDevice9::ColorFill** will work with all formats. However, when using a reference or software device, the only formats supported are D3DFMT_X1R5G5B5, D3DFMT_A1R5G5B5, D3DFMT_R5G6B5, D3DFMT_X8R8G8B8, D3DFMT_A8R8G8B8, D3DFMT_YUY2, D3DFMT_G8R8_G8B8, D3DFMT_UYVY, D3DFMT_R8G8_B8G8, D3DFMT_R16F, D3DFMT_G16R16F, D3DFMT_A16B16G16R16F, D3DFMT_R32F, D3DFMT_G32R32F, and D3DFMT_A32B32G32R32F.

When using a DirectX 7 or DirectX 8.x driver, the only YUV formats supported are D3DFMT_UYVY and D3DFMT_YUY2.

## See also

[D3DPOOL](https://learn.microsoft.com/windows/desktop/direct3d9/d3dpool)

[IDirect3DDevice9](https://learn.microsoft.com/windows/desktop/api/d3d9helper/nn-d3d9helper-idirect3ddevice9)