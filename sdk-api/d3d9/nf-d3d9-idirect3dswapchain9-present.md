# IDirect3DSwapChain9::Present

## Description

Presents the contents of the next buffer in the sequence of back buffers owned by the swap chain.

## Parameters

### `pSourceRect` [in]

Type: **const [RECT](https://learn.microsoft.com/windows/desktop/api/windef/ns-windef-rect)***

Pointer to the source rectangle (see [RECT](https://learn.microsoft.com/windows/desktop/api/windef/ns-windef-rect)). Use **NULL** to present the entire surface. This value must be **NULL** unless the swap chain was created with D3DSWAPEFFECT_COPY. If the rectangle exceeds the source surface, the rectangle is clipped to the source surface.

### `pDestRect` [in]

Type: **const [RECT](https://learn.microsoft.com/windows/desktop/api/windef/ns-windef-rect)***

Pointer to the destination rectangle in client coordinates (see [RECT](https://learn.microsoft.com/windows/desktop/api/windef/ns-windef-rect)). This value must be **NULL** unless the swap chain was created with D3DSWAPEFFECT_COPY. Use **NULL** to fill the entire client area. If the rectangle exceeds the destination client area, the rectangle is clipped to the destination client area.

### `hDestWindowOverride` [in]

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Destination window whose client area is taken as the target for this presentation. If this value is **NULL**, the runtime uses the **hDeviceWindow** member of [D3DPRESENT_PARAMETERS](https://learn.microsoft.com/windows/desktop/direct3d9/d3dpresent-parameters) for the presentation.

### `pDirtyRegion` [in]

Type: **const [RGNDATA](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-rgndata)***

This value must be **NULL** unless the swap chain was created with [D3DSWAPEFFECT_COPY](https://learn.microsoft.com/windows/desktop/direct3d9/d3dswapeffect). See [Flipping Surfaces (Direct3D 9)](https://learn.microsoft.com/windows/desktop/direct3d9/flipping-surfaces).
If this value is non-**NULL**, the contained region is expressed in back buffer coordinates. The rectangles within the region are the minimal set of pixels that need to be updated. This method takes these rectangles into account when optimizing the presentation by copying only the pixels within the region, or some suitably expanded set of rectangles. This is an aid to optimization only, and the application should not rely on the region being copied exactly. The implementation may choose to copy the whole source rectangle.

### `dwFlags` [in]

Type: **[DWORD](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Allows the application to request that the method return immediately when the driver reports that it cannot schedule a presentation. Valid values are 0, or any combination of [D3DPRESENT_DONOTWAIT](https://learn.microsoft.com/windows/desktop/direct3d9/d3dpresent) or [D3DPRESENT_LINEAR_CONTENT](https://learn.microsoft.com/windows/desktop/direct3d9/d3dpresent).

* If dwFlags = 0, this method behaves as it did prior to Direct3D 9. Present will spin until the hardware is free, without returning an error.
* If dwFlags = [D3DPRESENT_DONOTWAIT](https://learn.microsoft.com/windows/desktop/direct3d9/d3dpresent), and the hardware is busy processing or waiting for a vertical sync interval, the method will return D3DERR_WASSTILLDRAWING.
* If dwFlags = [D3DPRESENT_LINEAR_CONTENT](https://learn.microsoft.com/windows/desktop/direct3d9/d3dpresent), gamma correction is performed from linear space to sRGB for windowed swap chains. This flag will take effect only when the driver exposes [D3DCAPS3_LINEAR_TO_SRGB_PRESENTATION](https://learn.microsoft.com/windows/desktop/direct3d9/d3dcaps3) (see [Gamma (Direct3D 9)](https://learn.microsoft.com/windows/desktop/direct3d9/gamma)). Applications should specify this flag if the backbuffer format is 16-bit floating point in order to match windowed mode present to fullscreen gamma behavior.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

If the method succeeds, the return value is D3D_OK. If the method fails, the return value can be one of the following: D3DERR_DEVICELOST, D3DERR_DRIVERINTERNALERROR, D3DERR_INVALIDCALL, D3DERR_OUTOFVIDEOMEMORY, E_OUTOFMEMORY.

## Remarks

The [Present](https://learn.microsoft.com/windows/desktop/api/d3d9/nf-d3d9-idirect3ddevice9-present) method is a shortcut to Present. Present has been updated to take a flag allowing the application to request that the method return immediately when the driver reports that it cannot schedule a presentation.

If necessary, a stretch operation is applied to transfer the pixels within the source rectangle to the destination rectangle in the client area of the target window.

Present will fail if called between [BeginScene](https://learn.microsoft.com/windows/desktop/api/d3d9/nf-d3d9-idirect3ddevice9-beginscene) and [EndScene](https://learn.microsoft.com/windows/desktop/api/d3d9/nf-d3d9-idirect3ddevice9-endscene) pairs unless the render target is not the current render target (such as the back buffer you get from creating an additional swap chain). This is a new behavior for Direct3D 9.

## See also

[IDirect3DSwapChain9](https://learn.microsoft.com/windows/desktop/api/d3d9helper/nn-d3d9helper-idirect3dswapchain9)

[Reset](https://learn.microsoft.com/windows/desktop/api/d3d9/nf-d3d9-idirect3ddevice9-reset)