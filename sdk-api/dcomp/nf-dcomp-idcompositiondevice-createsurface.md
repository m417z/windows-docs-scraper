## Description

Creates an updateable surface object that can be associated with one or more visuals for composition.

## Parameters

### `width` [in]

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The width of the surface, in pixels.

### `height` [in]

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The height of the surface, in pixels.

### `pixelFormat` [in]

Type: **[DXGI_FORMAT](https://learn.microsoft.com/windows/desktop/api/dxgiformat/ne-dxgiformat-dxgi_format)**

The pixel format of the surface.

### `alphaMode` [in]

Type: **[DXGI_ALPHA_MODE](https://learn.microsoft.com/windows/desktop/api/dxgi1_2/ne-dxgi1_2-dxgi_alpha_mode)**

The format of the alpha channel, if an alpha channel is included in the pixel format. It can be one of the following values:

| Value | Meaning |
| - | - |
| **DXGI_ALPHA_MODE_UNSPECIFIED** | The alpha channel isn't specified. This value has the same effect as **DXGI_ALPHA_MODE_IGNORE**. |
| **DXGI_ALPHA_MODE_PREMULTIPLIED** | The color channels contain values that are premultiplied with the alpha channel. |
| **DXGI_ALPHA_MODE_IGNORE** | The alpha channel should be ignored, and the bitmap should be rendered opaquely. |

### `surface` [out]

Type: **[IDCompositionSurface](https://learn.microsoft.com/windows/desktop/api/dcomp/nn-dcomp-idcompositionsurface)****

The newly created surface object. This parameter must not be NULL.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

If the function succeeds, it returns S_OK. Otherwise, it returns an [HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types) error code. See [DirectComposition Error Codes](https://learn.microsoft.com/windows/desktop/directcomp/directcomposition-error-codes) for a list of error codes.

## Remarks

A Microsoft DirectComposition surface is a rectangular array of pixels that can be associated with a visual for composition.

A newly created surface object is in an uninitialized state. While it is uninitialized, the surface has no effect on the composition of the visual tree. It behaves exactly like a surface that has 100% transparent pixels.

To initialize the surface with pixel data, use the **IDCompositionSurface::BeginDraw** method. The first call to this method must cover the entire surface area to provide an initial value for every pixel. Subsequent calls may specify smaller sub-rectangles of the surface to update.

DirectComposition surfaces support the following pixel formats:

* **DXGI_FORMAT_B8G8R8A8_UNORM**
* **DXGI_FORMAT_R8G8B8A8_UNORM**
* **DXGI_FORMAT_R16G16B16A16_FLOAT**

## See also

[IDCompositionDevice](https://learn.microsoft.com/windows/desktop/api/dcomp/nn-dcomp-idcompositiondevice)

[IDCompositionDevice::CreateVirtualSurface](https://learn.microsoft.com/windows/desktop/api/dcomp/nf-dcomp-idcompositiondevice-createvirtualsurface)