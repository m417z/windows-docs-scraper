# IDirect3DDevice9Ex::PresentEx

## Description

Swap the swapchain's next buffer with the front buffer.

## Parameters

### `pSourceRect` [in]

Type: **const [RECT](https://learn.microsoft.com/windows/desktop/api/windef/ns-windef-rect)***

Pointer to a [RECT](https://learn.microsoft.com/windows/desktop/api/windef/ns-windef-rect) structure indicating region on the source surface to copy in window client coordinates. Only applies when the swapchain was created with the [D3DSWAPEFFECT_COPY](https://learn.microsoft.com/windows/desktop/direct3d9/d3dswapeffect) flag. If **NULL**, the entire source surface is presented. If the rectangle exceeds the source surface, it is clipped to the source surface.

### `pDestRect` [in]

Type: **const [RECT](https://learn.microsoft.com/windows/desktop/api/windef/ns-windef-rect)***

Pointer to [RECT](https://learn.microsoft.com/windows/desktop/api/windef/ns-windef-rect) structure indicating the target region on the destination surface in window client coordinates. Only applies when the swapchain was created with the [D3DSWAPEFFECT_COPY](https://learn.microsoft.com/windows/desktop/direct3d9/d3dswapeffect) flag. If **NULL**, the entire client area is filled. If the rectangle exceeds the destination client area, it is clipped to the destination client area.

### `hDestWindowOverride` [in]

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Pointer to a destination window whose client area is taken as the target for this presentation. If this value is **NULL**, the runtime uses the **hDeviceWindow** member of [D3DPRESENT_PARAMETERS](https://learn.microsoft.com/windows/desktop/direct3d9/d3dpresent-parameters) for the presentation.

**Note** If you create a swap chain with D3DSWAPEFFECT_FLIPEX, you must pass **NULL** to *hDestWindowOverride*

### `pDirtyRegion` [in]

Type: **const [RGNDATA](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-rgndata)***

Pointer to a [RGNDATA](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-rgndata) structure indicating the smallest set of pixels that need to be transferred. This value must be **NULL** unless the swapchain was created with the [D3DSWAPEFFECT_COPY](https://learn.microsoft.com/windows/desktop/direct3d9/d3dswapeffect) flag. For more information about swapchains, see [Flipping Surfaces (Direct3D 9)](https://learn.microsoft.com/windows/desktop/direct3d9/flipping-surfaces).

If this value is non-**NULL**, the contained region is expressed in back buffer coordinates. The method takes these rectangles into account when optimizing the presentation by copying only the pixels within the region, or some suitably expanded set of rectangles. This is an aid to optimization only, and the application should not rely on the region being copied exactly. The implementation can choose to copy the whole source rectangle.

### `dwFlags` [in]

Type: **[DWORD](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Allows the application to request that the method return immediately when the driver reports that it cannot schedule a presentation. Valid values are 0, or any combination of [D3DPRESENT](https://learn.microsoft.com/windows/desktop/direct3d9/d3dpresent) flags.

* If dwFlags = 0, this method behaves as it did prior to Direct3D 9. Present will spin until the hardware is free, without returning an error.
* If dwFlags = [D3DPRESENT_DONOTFLIP](https://learn.microsoft.com/windows/desktop/direct3d9/d3dpresent) the display driver is called with the front buffer as both the source and target surface. The driver responds by scheduling a frame synch, but not changing the displayed surface. This flag is only available in full-screen mode or when using D3DSWAPEFFECT_FLIPEX in windowed mode.
* If dwFlags = [D3DPRESENT_DONOTWAIT](https://learn.microsoft.com/windows/desktop/direct3d9/d3dpresent), and the hardware is busy processing or waiting for a vertical sync interval, the method will return D3DERR_WASSTILLDRAWING.
* If dwFlags = [D3DPRESENT_FORCEIMMEDIATE](https://learn.microsoft.com/windows/desktop/direct3d9/d3dpresent), D3DPRESENT_INTERVAL_IMMEDIATE is enforced on this Present call. This flag can only be specified when using D3DSWAPEFFECT_FLIPEX. This behavior is the same for windowed and full-screen modes.
* If dwFlags = [D3DPRESENT_LINEAR_CONTENT](https://learn.microsoft.com/windows/desktop/direct3d9/d3dpresent), gamma correction is performed from linear space to sRGB for windowed swap chains. This flag will take effect only when the driver exposes [D3DCAPS3_LINEAR_TO_SRGB_PRESENTATION](https://learn.microsoft.com/windows/desktop/direct3d9/d3dcaps3) (see [Gamma (Direct3D 9)](https://learn.microsoft.com/windows/desktop/direct3d9/gamma)).

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

Possible return values include: S_OK, D3DERR_DEVICELOST, D3DERR_DEVICEHUNG, D3DERR_DEVICEREMOVED, or D3DERR_OUTOFVIDEOMEMORY (see [D3DERR](https://learn.microsoft.com/windows/desktop/direct3d9/d3derr)) or S_PRESENT_OCCLUDED, or S_PRESENT_MODE_CHANGED (see [S_PRESENT](https://learn.microsoft.com/windows/win32/direct3d9/device-state-return-codes)). See [Lost Device Behavior Changes](https://learn.microsoft.com/windows/desktop/direct3d9/dx9lh) for more information about lost, hung, and removed devices.

|  |
| --- |
| Differences between Direct3D 9 and Direct3D 9Ex:<br><br>[D3DSWAPEFFECT_FLIPEX](https://learn.microsoft.com/windows/desktop/direct3d9/d3dswapeffect) is only available in Direct3D9Ex running on Windows 7 (or more current operating system). |

## Remarks

Similar to the [IDirect3DDevice9::Present](https://learn.microsoft.com/windows/desktop/api/d3d9/nf-d3d9-idirect3ddevice9-present) Method, PresentEx adds a dwflags parameter.

When the swapchain is created with [D3DSWAPEFFECT_FLIPEX](https://learn.microsoft.com/windows/desktop/direct3d9/d3dswapeffect) flag, **pSourceRect**, **pDestRect** and **pDirtyRegion** values must be set to **NULL**.

## See also

[IDirect3DDevice9Ex](https://learn.microsoft.com/windows/desktop/api/d3d9/nn-d3d9-idirect3ddevice9ex)