# IDirectDraw7::GetAvailableVidMem

## Description

Retrieves the total amount of display memory available and the amount of display memory currently free for a given type of surface.

## Parameters

### `unnamedParam1` [in]

A pointer to a [DDSCAPS2](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff550292(v=vs.85)) structure that indicates the hardware capabilities of the proposed surface.

### `unnamedParam2` [out]

A pointer to a variable that receives the total amount of display memory available, in bytes. The value received reflects the total video memory, minus the video memory required for the primary surface and any private caches that the display driver reserves.

### `unnamedParam3` [out]

A pointer to a variable that receives the amount of display memory currently free that can be allocated for a surface that matches the capabilities specified by the structure at *lpDDSCaps2*.

## Return value

If the method succeeds, the return value is DD_OK.

If it fails, the method can return one of the following error values:

* DDERR_INVALIDCAPS
* DDERR_INVALIDOBJECT
* DDERR_INVALIDPARAMS
* DDERR_NODIRECTDRAWHW

## Remarks

The following C++ example demonstrates how to use **GetAvailableVidMem** to determine both the total and free display memory available for texture-map surfaces:

```
// For this example, the lpDD variable is a valid
// pointer to an IDirectDraw7 interface.
LPDIRECTDRAW7 lpDD;
DDSCAPS2      ddsCaps2;
DWORD         dwTotal;
DWORD         dwFree;
HRESULT       hr;

hr = lpDD->QueryInterface(IID_IDirectDraw7, &lpDD);
if (FAILED(hr))
    return hr;

// Initialize the structure.
ZeroMemory(&ddsCaps2, sizeof(ddsCaps2));

ddsCaps2.dwCaps = DDSCAPS_TEXTURE;
hr = lpDD->GetAvailableVidMem(&ddsCaps2, &dwTotal, &dwFree);
if (FAILED(hr))
    return hr;

```

If the surface has the [DDSCAPS_VIDEOMEMORY](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff550286(v=vs.85)) flag set, **GetAvailableVidMem** returns different amounts of video memory depending on whether the surface can be used as a 3-D texture. If the surface can be used for 3-D textures, **GetAvailableVidMem** returns the sum of the local video memory and the non-local video memory on AGP systems.

**GetAvailableVidMem** provides only a snapshot of the current display-memory state. The amount of free display memory is subject to change as surfaces are created and released. Therefore, you should use the free memory value only as an approximation. In addition, a particular display adapter card might make no distinction between two different memory types. For example, the adapter might use the same portion of display memory to store z-buffers and textures. So, allocating one type of surface (for example, a z-buffer) can affect the amount of display memory available for another type of surface (textures). Therefore, it is best to first allocate an application's fixed resources (such as front and back buffers and z-buffers) before determining how much memory is available for dynamic use (such as texture mapping).

**GetAvailableVidMem** was not implemented in the previous DirectX IDirectDraw interface version.

## See also

[IDirectDraw7](https://learn.microsoft.com/windows/desktop/api/ddraw/nn-ddraw-idirectdraw7)