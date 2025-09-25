# IDirect3DDevice9::GetScissorRect

## Description

Gets the scissor rectangle.

## Parameters

### `pRect` [out]

Type: **[RECT](https://learn.microsoft.com/windows/desktop/api/windef/ns-windef-rect)***

Returns a pointer to a [RECT](https://learn.microsoft.com/windows/desktop/api/windef/ns-windef-rect) structure that defines the rendering area within the render target if scissor test is enabled.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

If the method succeeds, the return value is D3D_OK. If the method fails, the return value can be the following:
D3DERR_INVALIDCALL.

## Remarks

The scissor rectangle is used as a rectangular clipping region.

See [Rectangles (Direct3D 9)](https://learn.microsoft.com/windows/desktop/direct3d9/rectangles) for further information on the use of rectangles in DirectX.

## See also

[IDirect3DDevice9](https://learn.microsoft.com/windows/desktop/api/d3d9helper/nn-d3d9helper-idirect3ddevice9)