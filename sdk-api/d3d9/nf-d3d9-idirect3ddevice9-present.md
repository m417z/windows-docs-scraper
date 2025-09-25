# IDirect3DDevice9::Present

## Description

Presents the contents of the next buffer in the sequence of back buffers owned by the device.

## Parameters

### `pSourceRect` [in]

Type: **const [RECT](https://learn.microsoft.com/windows/desktop/api/windef/ns-windef-rect)***

Pointer to a value that must be **NULL** unless the swap chain was created with D3DSWAPEFFECT_COPY. pSourceRect is a pointer to a [RECT](https://learn.microsoft.com/windows/desktop/api/windef/ns-windef-rect) structure containing the source rectangle. If **NULL**, the entire source surface is presented. If the rectangle exceeds the source surface, the rectangle is clipped to the source surface.

### `pDestRect` [in]

Type: **const [RECT](https://learn.microsoft.com/windows/desktop/api/windef/ns-windef-rect)***

Pointer to a value that must be **NULL** unless the swap chain was created with D3DSWAPEFFECT_COPY. pDestRect is a pointer to a [RECT](https://learn.microsoft.com/windows/desktop/api/windef/ns-windef-rect) structure containing the destination rectangle, in window client coordinates. If **NULL**, the entire client area is filled. If the rectangle exceeds the destination client area, the rectangle is clipped to the destination client area.

### `hDestWindowOverride` [in]

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Pointer to a destination window whose client area is taken as the target for this presentation. If this value is **NULL**, the runtime uses the **hDeviceWindow** member of [D3DPRESENT_PARAMETERS](https://learn.microsoft.com/windows/desktop/direct3d9/d3dpresent-parameters) for the presentation.

### `pDirtyRegion` [in]

Type: **const [RGNDATA](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-rgndata)***

Value must be **NULL** unless the swap chain was created with D3DSWAPEFFECT_COPY. For more information about swap chains, see [Flipping Surfaces (Direct3D 9)](https://learn.microsoft.com/windows/desktop/direct3d9/flipping-surfaces) and [D3DSWAPEFFECT](https://learn.microsoft.com/windows/desktop/direct3d9/d3dswapeffect). If this value is non-**NULL**, the contained region is expressed in back buffer coordinates. The rectangles within the region are the minimal set of pixels that need to be updated. This method takes these rectangles into account when optimizing the presentation by copying only the pixels within the region, or some suitably expanded set of rectangles. This is an aid to optimization only, and the application should not rely on the region being copied exactly. The implementation can choose to copy the whole source rectangle.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

Possible return values include: D3D_OK or D3DERR_DEVICEREMOVED (see [D3DERR](https://learn.microsoft.com/windows/desktop/direct3d9/d3derr)).

## Remarks

If necessary, a stretch operation is applied to transfer the pixels within the source rectangle to the destination rectangle in the client area of the target window.

**Present** will fail, returning D3DERR_INVALIDCALL, if called between BeginScene and EndScene pairs unless the render target is not the current render target (such as the back buffer you get from creating an additional swap chain). This is a new behavior for Direct3D 9.

## See also

[IDirect3DDevice9](https://learn.microsoft.com/windows/desktop/api/d3d9helper/nn-d3d9helper-idirect3ddevice9)

[Lost Devices (Direct3D 9)](https://learn.microsoft.com/windows/desktop/direct3d9/lost-devices)

[Multihead (Direct3D 9)](https://learn.microsoft.com/windows/desktop/direct3d9/multihead)

[Reset](https://learn.microsoft.com/windows/desktop/api/d3d9/nf-d3d9-idirect3ddevice9-reset)