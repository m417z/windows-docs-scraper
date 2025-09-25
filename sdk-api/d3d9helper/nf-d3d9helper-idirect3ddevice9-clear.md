# IDirect3DDevice9::Clear

## Description

Clears one or more surfaces such as a render target, [multiple render targets](https://learn.microsoft.com/windows/desktop/direct3d9/multiple-render-targets), a stencil buffer, and a depth buffer.

## Parameters

### `Count` [in]

Type: **[DWORD](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Number of rectangles in the array at pRects. Must be set to 0 if pRects is **NULL**. May not be 0 if pRects is a valid pointer.

### `pRects` [in]

Type: **const [D3DRECT](https://learn.microsoft.com/windows/desktop/direct3d9/d3drect)***

Pointer to an array of [D3DRECT](https://learn.microsoft.com/windows/desktop/direct3d9/d3drect) structures that describe the rectangles to clear. Set a rectangle to the dimensions of the rendering target to clear the entire surface. Each rectangle uses screen coordinates that correspond to points on the render target. Coordinates are clipped to the bounds of the viewport rectangle. To indicate that the entire viewport rectangle is to be cleared, set this parameter to **NULL** and Count to 0.

### `Flags` [in]

Type: **[DWORD](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Combination of one or more [D3DCLEAR](https://learn.microsoft.com/windows/desktop/direct3d9/d3dclear) flags that specify the surface(s) that will be cleared.

### `Color` [in]

Type: **[D3DCOLOR](https://learn.microsoft.com/windows/desktop/direct3d9/d3dcolor)**

Clear a render target to this ARGB color.

### `Z` [in]

Type: **float**

Clear the depth buffer to this new z value which ranges from 0 to 1. See remarks.

### `Stencil` [in]

Type: **[DWORD](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Clear the stencil buffer to this new value which ranges from 0 to 2ⁿ-1 (n is the bit depth of the stencil buffer). See remarks.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

If the method succeeds, the return value is D3D_OK. If the method fails, the return value can be: D3DERR_INVALIDCALL.

## Remarks

Use this method to clear a surface including: a render target, all render targets in an MRT, a stencil buffer, or a depth buffer. Flags determines how many surfaces are cleared. Use pRects to clear a subset of a surface defined by an array of rectangles.

**IDirect3DDevice9::Clear** will fail if you:

* Try to clear either the depth buffer or the stencil buffer of a render target that does not have an attached depth buffer.
* Try to clear the stencil buffer when the depth buffer does not contain stencil data.

## See also

[IDirect3DDevice9](https://learn.microsoft.com/windows/desktop/api/d3d9helper/nn-d3d9helper-idirect3ddevice9)